[
/*
<fusedoc fuse="dsp_debuginline.inc" language="Lasso" specification="3.0">
	<responsibilities>I set up the debuging variables for inlines in the application. There should be only one dsp_debuginline.inc file within the application and it should reside within the _common folder.</responsibilities>
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create">
		  This file allows you to see activity within the inline and capture inline activity for a log file.
		</history>
		<history author="Tami Williams" date="05/08/2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/5/2012" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
*/
]



[protect]
[output_none]
<!-- 
assumes you're using one of the database connection variables from fbx_Settings ($readCon, etc) 

var('readCon' = array(
	-username = $dbusername,
	-password = $dbpassword,
	-database = $datasource,
    -maxRecords = 'all') );

IF DO
inline(
	$readCon,  // no -inlineName
    -Table='People',
	-FindAll);
/inline;

    [$errckDbname = (action_params)->get(2)->get(3)->second]
    
OR

var('readCon' = array(
	-Host=(Array(-Datasource='MySQLDS', -Name='localhost', -Username=$dbusername, -Password=$dbpassword)),
	-database = $datasource,
    -maxRecords = 'all')
    );
    
   [$errckDbname = (action_params)->get(1)->get(2)->second]

IF DO
inline(
	$readCon,
	-InlineName='getAllContacts',	// have -inlineName
    -Table='People',
	-FindAll);
/inline;
   
   [$errckDbname = (action_params)->get(1)->get(3)->second]

-->
[/output_none]

    
[if(string(lasso_version) >> '9')]
   [if(string(action_params) >> '-Datasource')]
	   [$errckDbname = (action_params)->get(1)->get(5)->second]
   [else]
	   [$errckDbname = (action_params)->get(1)->get(3)->second]
   [/if]
[else]
	<!-- for Lasso 8 -->
	[$errckDbname = (action_params)->find('-database')->get(1)->second]
[/if]


[$errckTblname = (action_params)->find('-table')->get(1)->second]
[/protect]

[$errckAction =  Lasso_CurrentAction]
[$errckFound =  found_count]
[$errckActionStatement =  Action_Statement]
[$errckCode =  error_code]
[$errckError =  error_msg]

[error_reset]

[if($debuginlineflag  == 'Y' )]
<div id="debuginline">
<hr size="5" noshade>
<span class="red">DEBUG INLINE</span>   [Date]
<span class="red"><br>Error [$errckCode]:  [$errckError]</span>
<hr  width="30%" align="left">

[if($errckAction)]
<b>Lasso_CurrentAction = [$errckAction]</b>
[/if]

[if($errckActionStatement)]
<br>Action_Statement = [$errckActionStatement]
[/if]

<hr  width="30%" align="left">

Database Name = [$errckDbname]
<br>Table Name = [$errckTblname]
<br>Found = [$errckFound]
<br>success = [var('success')]
<br>rawFA = [encode_html(var('rawFA'))]
<br>TargetCircuit = [var('TargetCircuit')]
<br>TargetCircuitPath = [var('TargetCircuitPath')]
<br> 


[tw_ShowActionParams(action_params)]

<hr size="5" noshade>
</div>
[/if]