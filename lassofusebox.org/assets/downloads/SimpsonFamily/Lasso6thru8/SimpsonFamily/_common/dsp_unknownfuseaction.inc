[output_none]
<fusedoc fuse="dsp_unknownfuseaction.inc" language="Lasso" specification="3.0">
	<responsibilities>I set up the unknown fusebox message for the application. There should be only one dsp_unknownfuseaction.inc file within the application and it should reside within the _common folder.</responsibilities>
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create" />
		<history author="Tami Williams" date="05/08/2008" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
[/output_none]

<div id="unknown">
	  <p><i>I received a fuseaction called <span class="red"><b>[$rawFA]</b></span> and I don't know what to do with it.</i>
			[if: $rawFA >> 'no default']
			<br /><br />
			<b>Please make sure that a default fuseaction is defined in the fbx_Globals.inc file in the application's root directory.</b>
			[else: $fuseaction == 'error']
			<br /><br />
			Please make sure that the circuit <b>[$circuit]</b> is defined in fbx_Circuits.inc in the application's root directory.
			[/if]
</p>
<p>Click here to <a href="javascript:history.go(-1)">go back</a> to the previous page if necessary.</p>
</div>