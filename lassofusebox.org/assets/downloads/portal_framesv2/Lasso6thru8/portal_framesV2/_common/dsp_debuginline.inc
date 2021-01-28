[output_none]
<fusedoc fuse="dsp_debuginline.inc" language="Lasso" specification="3.0">
	<responsibilities>I set up the debuging variables for inlines in the application. There should be only one dsp_debuginline.inc file within the application and it should reside within the _common folder.</responsibilities>
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create">
		  This file allows you to see activity within the inline and capture inline activity for a log file.
		</history>
		<history author="Tami Williams" date="05/08/2008" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
[/output_none]

[protect]
[$errckDbname = (action_params)->find:'-database'->get:1->second ]
[$errckTblname = (action_params)->find:'-table'->get:1->second ]
[$errckAction =  (Lasso_CurrentAction) ]
[$errckFound =  (found_count) ]
[$errckActionStatement =  (Action_Statement) ]
[$errckCode =  (Error_CurrentError: -ErrorCode)]
[$errckError =  (Error_CurrentError)]
[/protect]

[Error_SetErrorCode: (Error_NoError: -ErrorCode) ]
[Error_SetErrorMessage: (Error_NoError)]


[if: $debuginlineflag  == 'Y' ]
   <div id="debuginline">
   <hr size="5" noshade />
   <span class="red">DEBUG INLINE</span>   [Date]
   <span class="red"><br />Error [$errckCode]:  [$errckError]</span>
   <hr  width="30%" align="left" />
	[if: ($errckAction)]
   <b>Lasso_CurrentAction = [$errckAction]</b>
   [/if]
   [if: ($errckActionStatement)]
   <br />Action_Statement = [$errckActionStatement]
   [/if]
   
   <hr  width="30%" align="left" />
   
   Database Name = [$errckDbname]
   <br />Table Name = [$errckTblname]
   <br />Found = [$errckFound]
   <br />success = [var:'success']
   <br />rawFA = [encode_html:(var:'rawFA')]
   <br>TargetCircuit: [var:'TargetCircuit']
   <br>TargetCircuitPath: [var:'TargetCircuitPath']
   <br /> 
   <br />[ShowActionParams: (action_params)]
   <hr />
   </div>
[/if]