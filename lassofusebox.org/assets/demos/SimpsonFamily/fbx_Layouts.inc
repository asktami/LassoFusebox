<?LassoScript
/*
<fusedoc fuse="fbx_Layouts.inc" language="Lasso" specification="3.0">
   <responsibilities>
	   This file contains all the conditional logic for determining which layout file, if any, 
	   should be used for this circuit. It should result in the setting of the Fusebox public 
	   API variables fusebox.layoutdir, fusebox.layoutfile and (optionally) fusebox.stopLayout.
   </responsibilities>
   <properties>
	   <history author="Tami Williams" date="05/23/08" email="tami@asktami.com" type="Update" />
   </properties>
   <io>
		<in>
			<string name="fusebox.stopLayout" comments="Nest this layout inside a higher level layout?" />
		</in>
	   <out>
		   <string name="fusebox.layoutDir" />
		   <string name="fusebox.layoutFile" />
	   </out>
   </io>
</fusedoc>
*/


if: $stopLayout == 'Y' ;
		$layoutFile = '';
		 
else;
// just use the layout specified by the child circuit's fbx_Layouts.inc file
		 
	if: $frame == 'Y';
		 $layoutFile = '_lay/lay_frame.lasso';
	 else;
		 $layoutFile = '_lay/lay_noframes.lasso';
	 /if;

/if;

$layoutDir = '';

?>