[
/*
<fusedoc fuse="fbx_Switch.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I am the Select statement that handles the fuseaction, delegating work to various fuses.
	</responsibilities>
	<properties>
		<history author="Tami Williams" date="June 2008" email="tami@asktami.com" type="Create"></history>
		<history author="Tami Williams" date="4/28/2012" email="tami@asktami.com" type="Update"></history>
	</properties>
	<io>
		<in>
			<structure name="fusebox">
				<string name="fuseaction" />
				<string name="circuit" />	
			</structure>
		</in>
	</io>	
</fusedoc>
*/


select($fuseaction);

case('defaultfuseaction');
// This will be the value returned if someone types in "circuitname.", omitting the actual fuseaction request
// EX: if in url "fuseaction=circuitname."  or "fuseaction=circuitname"
'This is the default fuseaction for this circuit <b>" ' + $circuit + '"</b> when a fuseaction is not specified in the url.' ;

case('welcome');
	FBX_Include('dsp_secured.inc' );

case;
// unknown fuseaction
	FBX_IncludeCommon('dsp_unknownfuseaction.inc');

// you can also display text directly from this file
// uncomment the example below to see how it works (it will be added below the "unknown fuseaction" result)
// 'This is the <b>default</b> UNKNOWN FUSEACTION text.'  ;

/select;

]