[
/*
<fusedoc fuse="dsp_feedback.inc" language="Lasso" specification="3.0">
	<responsibilities>I set up the feedback messages for the application. There should be only one dsp_feedback.inc file within the application and it should reside within the _common folder.</responsibilities>
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create" />
		<history author="Tami Williams" date="05/08/2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/5/2012" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
*/
]


[if(($feedback) != '')]
<span class="red">[$feedback]</span>

[else($errckAction == 'update'   && $errckCode == 0 )]
[var('logMessage' = 'The information submitted was updated successfully.')]

<span class="red">The information submitted was updated successfully.</span>

[else(($fuseaction == 'login'  || $fuseaction == 'get_password'  || $fuseaction >> 'process')  && var('success') == 'No')]
		 [if($errckFound > 1)]
		 [var('logMessage' = 'Sorry, more than one record matched your request.')]

							 <span class="red">Sorry, more than one record matched your request.<br>
							 Please contact us at [$gmailto].</span>
							 
		 [else(($errckFound) == 0)]
		 [var('logMessage' = 'Sorry. The information you have entered does not agree with data in our records.')]
		 <span class="red">Sorry. The information you have entered does not agree with data in our records.
		 <br>Please re-enter and submit again.</span>
		 [/if]
		 
[else(($errckAction == 'search'  || $errckAction == 'findall' ) &&  $errckCode != 0  &&  !($errckError >> 'database') && !($errckError >> 'table'))]
   <span class="red"> No records found.</span>

[else(!($errckError >> 'no error') || $errckCode != 0)]
[output_none]
can't find database, can't find table, other errors
[/output_none]

		 [var('logMessage' = 'Communication Error')]
		<span class="red">Communication Error</span>
		<p>An error occurred while trying to perform the last action. Often these errors are individual occurances due to internet traffic problems. Please use your browser's back button to return to the previous page, and try to submit the information again. If your browser presents a dialog asking if form data should be reposted, click the OK, or Yes, or another affirmative button.</p>
		
		<p>If the error occurs again, please send a message to us at <a href="mailto:[$gmailto]?subject=[$gsitename] Website Error [(Date)->Format('%D %r')]&body=There was an error in the '[$errckDbname]' database, '[$errckTblname]' table.  Error: ([$errckCode]) '[$errckError]'  occurred on [$circuit].[$fuseaction].">[$gmailto]</a> and report that you got the following error message:</p>
		
		<p> There was an error in the <span class="red">"[$errckDbname]"</span> database, <span class="red">"[$errckTblname]"</span> table.</p>
		<p>Error: <span class="red">([$errckCode]) "[$errckError]"</span> occurred on <span class="red">[$circuit].[$fuseaction]</span>.</p>
		
		<p>We will investigate the error as soon as possible, and apologize for the inconvenience.</p>
		
<hr size="2" noshade>
[/if]