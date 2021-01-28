<?LassoScript
/*
<fusedoc fuse="fbx_Globals.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I set up the static enviroment settings for the application. There should be only one fbx_Globals.inc file within the application and it should reside within the root folder.
	</responsibilities>	
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create">
		  The default fuseaction MUST be in this file and it MUST be called "fuseaction".
		  Put settings here that, if missing, would break the application; they may be overridden by settings in child circuits.
		  The globals defined here use files and folders that are part of this Fusebox core.
		</history>
	</properties>
	<io>
		<out>
			<string name="fuseaction" scope="variables" />
			<string name="appGlobalsMap" scope="variables" />
			<string name="gServerName" scope="variables" />
			<string name="appLocation" scope="variables" />
		</out>
	</io>
</fusedoc>
*/

//put settings here that, if missing, would break the application; they may be overridden by settings in child circuits


//default frame variable
FBX_Param: -Name='frame', -Default='N' ;


// default fuseaction MUST be in this file

if: $frame == 'Y';
	FBX_Param: -Name='fuseaction', -Default='simpsonfamily.frameset' ;
	FBX_Param: -Name='targetContent', -Default='TARGET=\"content\"' ;
else;	
	FBX_Param: -Name='fuseaction', -Default='simpsonfamily.main' ;
	FBX_Param: -Name='targetContent', -Default='' ;
/if;

var: 'img' =  'images/';


?>