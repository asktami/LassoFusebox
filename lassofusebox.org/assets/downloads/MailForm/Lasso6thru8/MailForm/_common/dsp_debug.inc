[output_none]
<fusedoc fuse="dsp_debug.inc" language="Lasso" specification="3.0">
	<responsibilities>I set up the debuging variables for the application. There should be only one dsp_debug.inc file within the application and it should reside within the _common folder.</responsibilities>
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create">
		  Put any variables that you want to track in this file.
		</history>
	</properties>
</fusedoc>
[/output_none]


[if: $debugflag  == 'Y' ]
<div id="debug">
<hr size="5" noshade />

	<span class="red">Debug</span>
		 <br />session  = [Session_ID: -Name=$sessionName]
		 <hr  width="30%" align="left" />
		 
		 [ShowActionParams: (action_params)]
		 <hr  width="30%" align="left" />
		 
		<br>appLocation = [$appLocation]
		<br>gServerName = [$gServerName]
		 
		<br>rawFA: [encode_html($rawFA)]
		 <br>TargetCircuit: [$TargetCircuit]
		 <br>TargetCircuitPath: [$TargetCircuitPath]
		 <br /> layoutdir: [$layoutdir]
		 <br /> layoutfile: [$layoutfile]
		 <hr  width="30%" align="left" />
		 
		 RootCircuit: [$RootCircuit]
		 <br>RootCircuitPath: [$RootCircuitPath]
		 <br>isRootCircuit: [$isRootCircuit]
</div>
[/if]
