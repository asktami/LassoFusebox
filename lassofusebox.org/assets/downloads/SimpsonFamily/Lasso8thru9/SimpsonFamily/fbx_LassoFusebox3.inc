[
// -------------------------------------------------------------------------------------------
// This file is broken into eleven sections. 
// Section One is the Fusedoc for the file.
// Section Two contains the public "API-style" variables that are used in the Fusebox framework.
// Section Three established the private structure "FB_".
// Section Four is the former formURL2attributes Custom Tag. In LassoFusebox all ACTION_PARAMS
// are put into a common scope.
// Section Five includes the fbx_Circuits.inc file.
// Section Six creates a mirror of the fusebox.circuits strucure for reverse look-ups.
// Section Seven includes the root fbx_Globals.inc file.
// Section Eight massages the variable FUSEACTION and begins the aliased lookup process.
// Section Nine includes nested fbx_Settings.inc files top-to-bottom.
// Section Ten includes the target circuit fbx_Switch.inc file, which processes the requested fuseaction.
// Section Eleven includes any layout files, in bottom-to-top order to allow layouts to be nested.
// It also outputs the final display of the page.
// -------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------
// SECTION ONE
// For more information about Fusedocs and how to read them, visit fusebox.org and halhelms.com. 
// -------------------------------------------------------------------------------------------
/*
<fusedoc fuse="fbx_LassoFusebox3.inc" specification="3.0">
	<responsibilities>
		I am the code behind fbx_LassoFusebox 3.0 that handles nesting, layouts--oh, a bunch of stuff, really. PLEASE BE VERY CAREFUL ABOUT MAKING ANY CHANGES TO THIS FILE, AS IT WILL RENDER IT NON-COMPLIANT WITH THE STANDARD NOTED ABOVE. There is no need to modify this file for any settings. All settings can occur in fbx_Settings.inc.
	</responsibilities>
	<properties>
		<property name="version" value="3.8" />
		<property name="build" value="1e" />
		<history author="John Quarto-vonTivadar" date="27 Sep 2001" email="jcq@mindspring.com">Portions of code contributed by Steve Nelson, Hal Helms, Jeff Peters, Nat Papovich, Patrick McElhaney, Fred Sanders, Bill Wheatley and Stan Cox.</history>
		<history author="Nat Papovich" date="Oct 2001" email="mcnattyp@yahoo.com" type="Update">Converted to cfscripting, bug fixes for final release.</history>
		<history author="Nat Papovich" date="Nov 2001" email="mcnattyp@yahoo.com" type="Update" />
		<history author="Michael S. McKellip" date="Sept 2002" email="michael@lassofusebox.org" type="Update">Converted to Lasso Professional 6</history>
		<history author="Michael S. McKellip" date="May 2003" email="michael@lassofusebox.org" type="Update">
		Multiple updates:
		- Converted main "fbx_fusebox30_LP6.lasso" to LassoScript to increase execution speed.
		- Updated all core files to support the creation of LassoApps from a Fusebox 3 app. Simply use the [LassoApp_Link] command in all includes, redirects, links and form actions. Application can then be either run normally or converted to a LassoApp.
		- Added a new framework core file named "fbx_Sessions.lasso". Use this file to initialize and open sessions. The file should exist only once within the application and be placed within the root folder.
		- A new tag named [FBX_Redirect] has been added to the "fbx_Library.lasso" file. Use of this tag for redirects allows session keys to be passed with the redirect. Examples:
		
		  To redirect when using cookies to pass session keys:
		  [FBX_Redirect:'somewhere.lasso']
		  
		  To redirect when using links to pass session keys:
		  [FBX_Redirect:'somewhere.lasso', -UseLink]
		  
		  To enable redirects and creation of a LassoApp add the LassoApp_Link command:
		  [FBX_Redirect:(LassoApp_Link:'somewhere.lasso')]
		  
		  Original code and concept courtesy of Bil Corry.
		  
		- The file "URL_Redirect.lasso" has been deprecated. Use the [FBX_Redirect] tag instead.
		</history>
		<history author="Tami Williams" date="August 2003" email="tami@asktami.com" type="Update">
		Multiple updates:
		- Various changes to the core files and removed, added and renamed some variables. Also renamed core as fbx_LassoFusebox3.inc.
		- Removed the variable "thisLayoutPath" (replaced with new functionality in the variable "currentPath").
		- Renamed HomeCircuit as RootCircuit and isHomeCircuit as isRootCircuit.
		- Removed the "suppressErrors" variable which turned on/off viewing errors in the core files. The core files are a basic requirement for any fusebox application and as such errors must be seen and corrected before deployment.
		
		- Changed the suffix of all core files from ".lasso" to ".inc".
		
		- The fbx_Sessions.inc file is now included in the application AFTER converting action params to variables (instead of before), and so session variables now override the action_params.
		- Only action_params that don't start with "-" or "_" are automatically converted into variables.
		- Use the root directory fbx_Settings.inc file to override session variables with variables created from action_params when needed.
		- Use child directory fbx_Settings.inc files to create static and dynamic variables and variables that use/rely on/override fbx_Sessions.inc-based or parent fbx_Settings.inc variables.
		
		- All redirects are now done by only using Lasso's built-in redirect_url tag.  The [FBX_Redirect] tag has been deprecated; use Lasso's built-in redirect_url tag instead.
		
		- Added a new framework core file named "fbx_CustomTags.inc".  Users should put their own custom tags here.
		- Added a new framework core file named "fbx_Globals.inc".  Use this file for settings (including the "default" fuseaction) that if missing would break the application. The file should exist only once within the application and be placed within the root folder.  The "default" fuseaction MUST be in this file.
		
		- Now REQUIRED that you have a fbx_Switch.inc file in your root_folder.
		
		- In the fbx_Circuits.inc file you MUST have at least one line that maps the root circuit's alias name (ie a path to the root directory for the application).  You don't need to define a circuit named "error".
		
		- Removed the [SaveContent] tag and replaced it with a new variable [$layout].
		- Changed the definition of the [FBX_Include] tag.
				
		- If a circuit has a fuseaction with the same name then if the fuseaction passed in the url is just the circuit name the matching fuseaction runs.
		  Example: "fuseaction=user.user" now works the same way as "fuseaction=user." and "fuseaction=user".
		</history>
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="September 2008" email="tami@asktami.com" type="Update">
		To protect against cross-site scripting and cross-site request forgery attacks added encode_html to user supplied input before its used inside any page and/or encode_sql to action_params being auto-converted to string variables in these pages: _common/dsp_debug.inc,  _common/dsp_debuginline.inc, fbx_CustomTags.inc, fbx_LassoFusebox3.inc, and fbx_Library.inc.  Added a comment to site.lasso explaining how it protects against cross-site request forgery attacks.
		</history>
		<history author="Tami Williams" date="2-21-2009" email="tami@asktami.com" type="Update">
		Added this to section 4:
		-	If: #temp->first->type == 'string' && !((#temp->first)->(BeginsWith: '_'))  &&  !((#temp->first)->(BeginsWith: '-'));
			Its a check for #temp type == string to handle null values in action_params from urls like this: http://localhost/action_params.lasso?a&b=c&=d (where the result is null = d)
			OR this: <input type="submit" value="submit">
		</history>
		<history author="Tami Williams" date="1-27-2010" email="tami@asktami.com" type="Update">
		Removed encode_sql from code in section 4 of this file because it caused double encoding! To protect against cross-site scripting and cross-site request forgery attacks you should set as variable OR add encode_html to user supplied input (action_params) before using inside any page.  Be careful using action_params in these pages: _common/dsp_debug.inc,  _common/dsp_debuginline.inc, fbx_CustomTags.inc, fbx_LassoFusebox3.inc, and fbx_Library.inc.  Added a comment to site.lasso explaining how it protects against cross-site request forgery attacks.  Be careful of double encoding when using encode_sql to protect against cross-site request forgery attacks in this way.
		</history>
		
		<history author="Tami Williams" date="3-9-2011" email="tami@asktami.com" type="Update">
		Converted from Colon syntax to Parentheses syntax.  See this tip of the week (http://www.lassotech.com/TotW_20071207) for more info on Parentheses syntax.
		</history>
		
		<history author="Tami Williams" date="1-23-2012" email="tami@asktami.com" type="Update">
		Updated core files to work with Lasso 9.1.4.
		</history>
	</properties>
	<io>
		<out>
			<structure name="fusebox" scope="variables" comments="this is the public API of variables that should be treated as read-only">
				<boolean name="isCustomTag" default="FALSE" />
				<boolean name="isRootCircuit" default="FALSE" />
				<boolean name="isTargetCircuit" default="FALSE" />
				<string name="fuseaction" comments="will be assigned a literal value of 'fusebox.defaultfuseaction' if attributes.fuseaction comes in as 'circuit.' with no fuseaction passed." />
				<string name="circuit" />
				<string name="RootCircuit" />
				<string name="targetCircuit" />
				<string name="thisCircuit" />
				<string name="currentPath" />
				<string name="rootPath" />
			</structure>
			<structure name="FB_" comments="Internal use only. Please treat the FB_ as a reserved structure, not to be touched.">
			</structure>
		</out>
	</io>
</fusedoc> 
*/
// -------------------------------------------------------------------------------------------
// SECTION TWO
// The fusebox structure below is a structure encompassing the public Fusebox API. We recommend making 
// no changes to this structure as it will render your application non-compliant to the Fusebox 3.0 
// standard.

// fusebox.IsCustomTag:
// The boolean variable is set by the Fusebox framework which will automatically determine if it is 
// being called as a custom tag. Currently, Fusebox offers no expanded support for applications being 
// called as Custom Tags. But you can programatically alter your application if it's being called as 
// Custom Tag by checking the value of this variable. This can be helpful for changing (or removing 
// altogether) layout files in fbx_Layouts.inc.

// fusebox.IsRootCircuit:
// This boolean variable is set and re-set as the Fusebox framework does its business pulling in 
// fbx_Settings.inc files and the fbx_Switch.inc file and fbx_Layouts.inc files (and associated 
// layout files). It is TRUE only when the currently accessed circuit is the root circuit running this 
// application.

// fusebox.IsTargetCircuit:
// Like isRootCircuit above, this boolean variable is used during the process of including files. It 
// is TRUE only when the currently accessed circuit is the target circuit running specified by 
// circuit.fuseaction.

// fusebox.Circuit:
// This is the first part of the compound fuseaction that gets passed as attributes.fuseaction.

// fusebox.Fuseaction:
// This is the second part of a compound fuseaction that gets passed as attributes.fuseaction. 
// fusebox.fuseaction is the variable expression evaluated in fbx_Switch.inc.

// fusebox.RootCircuit:
// This variable is set to the root-level circuit as defined in fusebox.circuits strucure.

// fusebox.TargetCircuit:
// This is the circuit the requested fuseaction is to run in. The difference between this variable and 
// fusebox.circuit above, is that this variable is the circuit alias that was found in the 
// fusebox.circuits file as opposed to the circuit that is being attempted to be found. In all 
// non-error situations fusebox.TargetCircuit and fusebox.Circuit will be the same.
	
// fusebox.ThisCircuit:
// Like IsTargetCircuit and IsRootCircuit above, this variable is set and re-set during the process of 
// running the fbx_Settings.inc files and the fbx_Switch.inc file, and refers to the circuit alias 
// of the circuit from which files are currently being accessed.

// fusebox.Circuits:
// This variable is a structure whose aliases are the circuit names created in fbx_Circuits.inc and 
// whose values are the directory paths to those circuits.

// fusebox.currentPath:
// This variable takes you from the root circuit to any location it is called. If you use images in 
// directories beneath individual circuits, this variable will point to that circuit like 
// "directory/directory/". 
// It is also the directory path that the layout file being used is called from. This variable changes as 
// the layouts are nested one inside another, building the overall page layout.
	
// fusebox.rootPath:
// This variable takes you from the circuit it is being called from, back to the root. This is helpful 
// to determine your location relative to the root application.
// -------------------------------------------------------------------------------------------


/*
-------------------------------------------------------------------------------------------
// SECTION TWO
Create fusebox variables.
-------------------------------------------------------------------------------------------
*/

var('_section' = 2);

Library('fbx_Library.inc');

// User defined custom tags/types
Library('fbx_CustomTags.inc');

var(
'_error' = pair('0' ='Error_NoError'),
'IsCustomTag' = '',
'IsRootCircuit' = 'false',
'IsTargetCircuit' = 'false',
'fuseaction' = '',
'circuit' = '',
'RootCircuit' = '',
'RootCircuitPath' = '',
'TargetCircuit' = '',
'TargetCircuitPath' = '',
'thisCircuit' = '',
'showErrors' = '',	// changed from suppressErrors; no longer being used - included for backward compatibility
'stopLayout' = '',
'layoutDir' = '',
'layoutFile' = '',
'layout' = '',			// new
'displayfile' = '',		// new; no longer being used - included for backward compatibility
'feedback' = '',
'currentPath' = '',
'rootPath' = '',
'_Circuits' = map
);

/*
-------------------------------------------------------------------------------------------
// SECTION THREE
FB_ is a structure encompassing "private" variables used by the underlying Fusebox framework. 
Make no changes to it without a full understanding of the ramifications of those changes.
-------------------------------------------------------------------------------------------
*/

$_section = 3;

var('FB_' = Map);

/*
-------------------------------------------------------------------------------------------
// SECTION FOUR
This code used to be in a Custom Tag called formURL2attributes.lasso.
It copies all incoming FORM and URL variables to variable scope.
Then include the fbx_Sessions.inc file which is exclusive to the Lasso version of Fusebox.

From www.listsearch.com/ ID= 105874 :
"If action params are set to variables before user defined variables on the page then any existing variables (appearing afterwards) will overwrite user-injected variables."
-------------------------------------------------------------------------------------------
*/

$_section = 4;
protect;
local('temp' = '');
iterate(action_params, #temp);
if(#temp->first != '' );
	if(#temp->first->type == 'string' && !(#temp->first)->(BeginsWith('_'))  &&  !(#temp->first)->(BeginsWith('-')) );
		// check for #temp type == string to handle null values in action_params from urls like this: http://localhost/action_params.lasso?a&b=c&=d (null = d)
		// make variable = NULL if empty string passed in action_param
		// useful when using MySQL and adding/editing integers and dates
		// also works with FileMaker - will make the field blank/empty on adds and updates
		// also can NOT use encode_sql to prevent sql injection on strings in this section b/c it causes double encoding! so that can't is stored and output as can\'t 
			
			if(!(action_param(#temp->first))) ;
			   var(#temp->first = null);
			else;
			   var(#temp->first = action_param(#temp->first)) ;
			/if;
	/if;
/if;
/iterate;
/protect;

protect;
 			Handle(error_code != 0);
			$_error->first = error_code;
			$_error->second = error_msg;
			/Handle;
Include('fbx_Sessions.inc');
/protect;


Fail_If(integer($_error->first) != 0 ,-10004,'I could not find "fbx_Sessions.inc" (or one of its components) in the Fusebox application\'s root directory.
Error Code: ' + $_error->first + '
		Error: ' + $_error->second );


/*
-------------------------------------------------------------------------------------------
// SECTION FIVE
Attempt to include the fbx_Circuits.inc file, which should be in the same directory as this file.
-------------------------------------------------------------------------------------------
*/

$_section = 5;

protect;
 			Handle(error_code != 0);
			$_error->first = error_code;
			$_error->second = error_msg;
			/Handle;
Include('fbx_Circuits.inc');
/protect;

Fail_If(integer($_error->first) != 0 ,-10005,'The circuits structure does not exist. This must be defined in the Fusebox application\'s fbx_Circuits.inc file.' );

/*
-------------------------------------------------------------------------------------------
// SECTION SIX
Create a reverse path look-up of the fusebox.Circuits structure which can be used later to 
conveniently look up the circuit alias of whichever circuit is being accessed at that moment, 
particularly when determining fusebox.thisCircuit.
-------------------------------------------------------------------------------------------
*/

$_section = 6;

var(
'_ReverseCircuits' = map,
'aCircuit' = ''
);

iterate($_Circuits, $aCircuit);
	$_ReverseCircuits->Insert($aCircuit->Second=$aCircuit->First);
	
	If($_Circuits->Find($aCircuit->First)->Split('/')->Size == 1);
		$RootCircuit=$aCircuit->First;
		$IsRootCircuit='true';
		$RootCircuitPath=$aCircuit->Second;
	/If;
/Iterate;


/*
-------------------------------------------------------------------------------------------
// SECTION SEVEN
Attempt to include the fbx_Globals.inc file from the root directory, 
the same directory that this file is being run from.
-------------------------------------------------------------------------------------------
*/

$_section = 7;

protect;
	handle(error_code != 0);
		   $_error->first = error_code;
		   $_error->second = error_msg;
	/handle;
Include('fbx_Globals.inc');
/protect;

Fail_If(integer($_error->first) != 0 ,-10007,'I could not find "fbx_Globals.inc" (or one of its components) in the Fusebox application\'s root directory.
<br><br>Error Code: ' + $_error->first + '
		Error: ' + $_error->second);



/*
-------------------------------------------------------------------------------------------
// SECTION EIGHT
Dissect attributes.fuseaction (available in the attributes scope either from being converted 
in the formURL2attributes section or via the above included fbx_Globals.inc file in the 
root directory). If attributes.fuseaction is not a compound fuseaction (i.e. it only includes 
the circuit in the form of "?fuseaction=circuit."), then set the fuseaction as blank, which 
the target circuit's default CASE tag will pick up. Now look up the target circuit in the 
fusebox.circuit structure for the full path to the circuit.
-------------------------------------------------------------------------------------------
*/

$_section = 8;

var('rawFA' = $fuseaction);

if(!Variable_Defined('fuseaction') || var('fuseaction') == '' );
// no default fuseaction
$rawFA = 'no default fuseaction' ;

else;

		if( 
		($fuseaction->Split('.')->Size == 2 && $fuseaction->EndsWith('.')) || $fuseaction->Split('.')->Size == 1 
		);
			$fuseaction= 'defaultfuseaction';
		else;
			$fuseaction = string($rawFA->Split('.')->Get(2));
		/If;
		
		$circuit = string($rawFA->Split('.')->Get(1));
		$TargetCircuit = string($circuit);
		$TargetCircuitPath = $_Circuits->Find($circuit);
		

/if;

// handle bad circuit names
// a bad circuit name or bad fuseaction means use the RootCircuit's switch file
if(!$_Circuits->contains($circuit));
$fuseaction = 'error' ;
$circuit = string($RootCircuit);
$TargetCircuitPath = $_Circuits->Find($RootCircuit);
/if;

Fail_If( !($_Circuits->Find($circuit)),-10008,'I could not find the <b>error</b> circuit.  It must be defined in the Fusebox application\'s fbx_Circuits.inc file.');



/*
-------------------------------------------------------------------------------------------
// SECTION NINE
Attempt to include any nested fbx_Settings.inc files, in top-to-bottom order so that 
variables set in children fbx_Settings.inc files can overwrite variables set in higher 
fbx_Settings.inc files. Also include the root directory fbx_Settings.inc file.
To prevent child fbx_Settings.inc variables from overwriting parent fbx_Settings.inc variables, use FBX_PARAM rather than variable.
Alternately, any child fbx_Settings.inc can use variable to set a variable and lower fbx_Settings.inc files cannot overwrite it unless  they use variable.

If any fbx_Settings.inc file or circuit directory alias cannot be found, continue on without failing.

i.e. Loop thru all directories in url of target circuit path and include each settings file.
-------------------------------------------------------------------------------------------
*/

$_section = 9;

var('layoutpathArray' = $TargetCircuitPath->Split('/'),
'circuitaliasPath' = '' ,
'_circuitaliasPath' =  '' );

loop($layoutpathArray->Size);

$circuitaliasPath = string($circuitaliasPath + ($layoutpathArray->(Get(Loop_Count))) );

If($_ReverseCircuits->Find($circuitaliasPath));
		protect;
			Handle(error_code != 0 );
				Error_SetErrorCode(Error_NoError(-ErrorCode));
				Error_SetErrorMessage(Error_NoError) ;
				$thisCircuit = '';
			/Handle;
			$thisCircuit = $_ReverseCircuits->Find($circuitaliasPath);
		/protect;
		
		If($thisCircuit == $TargetCircuit);
			$IsTargetCircuit = 'true';
		Else;
			$IsTargetCircuit = 'false';
		/If;
		
		If($thisCircuit == $RootCircuit);
			$IsRootCircuit = 'true';
		Else;
			$IsRootCircuit = 'false';
		/If;
		

		$currentPath = string($circuitaliasPath);
		
		
		If($currentPath->Size);
			$currentPath = string($currentPath + '/' );
		/If;

		$currentPath->RemoveLeading($RootCircuitPath);
		$currentPath->RemoveLeading('/');


// fbx_Settings.inc file is only required in the Fusebox application's root directory.
// code -9984 = file missing in Lasso 8
// code 404 = file missing in Lasso 9

		protect;
		handle(error_code != -9984  && error_code != 404 && error_code != 0);
		   $_error->first = error_code;
		   $_error->second = error_msg;
		/handle;
		Include($currentPath + 'fbx_Settings.inc');
		/protect;

Fail_If(integer($_error->first) != -9984  && integer($_error->first) != 404 && integer($_error->first) != 0 ,-10009,'I could not find "' + $currentPath +  'fbx_Settings.inc" (or there is an error in one of its components).
<br><br>Error Code: ' + $_error->first + '
		Error: ' + $_error->second);

	/If;
	
	$_circuitaliasPath =  $circuitaliasPath + '/' ;
	$circuitaliasPath = $_circuitaliasPath;
/loop;

/*
-------------------------------------------------------------------------------------------
// SECTION TEN
Now "reach down" and include the fbx_Switch.inc in the target circuit, executing 
fusebox.fuseaction. Store the contents of the output into a variable called "layout".
-------------------------------------------------------------------------------------------
*/


protect;
handle(error_code != 0);
	$_error->first = error_code;
	$_error->second = error_msg;
/handle;
$layout = Include($currentPath + 'fbx_Switch.inc' );
/protect;


Fail_If(integer($_error->first) != 0 ,-10010, 'Error in the "' + $circuit + '" circuit fbx_Switch.inc file (or one of its components such as an included file or variable).  
		<br><br>Error Code: ' + $_error->first + '
		Error: ' + $_error->second );



/*
-------------------------------------------------------------------------------------------
// SECTION ELEVEN
Now handle the layouts, resolving them in bottom-to-top order to nest the circuits, if needed. 
Also set fusebox.thisCircuit equal to the circuit name of the current circuit the code is 
passing through, which will let any layout files in circuits know where they are. If 
attempting to include any layout file throws an error, then do nothing and continue on. 
This ENTIRE section and functionality of nesting layouts and controlling layouts via layout 
files is optional. If you do not have any layout files (fbx_Layout.inc), or only have a 
layout file in your root directory, everything will still work.

Note: bottom to top means start at last nested then loop back to first from TargetCircuitPath
This variable changes as the layouts are nested one inside another, building the overall page layout.
-------------------------------------------------------------------------------------------
*/

$_section = 11;

var('circuitalias' = $TargetCircuitPath);
var('layoutpath' = $TargetCircuitPath);

While($layoutpath->Size > 0);
	
	If($_ReverseCircuits->Find($circuitalias));
		protect;
			Handle(error_code != 0);
				Error_SetErrorCode(Error_NoError(-ErrorCode));
				Error_SetErrorMessage(Error_NoError) ;
				$thisCircuit = '';
			/Handle;
			$thisCircuit = $_ReverseCircuits->Find($circuitalias);
		/protect;
		
		If($thisCircuit == $TargetCircuit);
			$IsTargetCircuit = 'true';
		Else;
			$IsTargetCircuit = 'false';
		/If;
		
		If($thisCircuit == $RootCircuit);
			$IsRootCircuit = 'true';
		Else;
			$IsRootCircuit = 'false';
		/If;

 		$currentPath = string($layoutpath);
		
		// do as 2 separate actions or won't work
		$currentPath->RemoveLeading($RootCircuitPath);
		$currentPath->RemoveLeading('/');

		If($currentPath->Size);
			$currentPath = $currentPath + '/' ;
		/If;
		
		$rootPath = '';
		
		Loop((String_RemoveLeading(String_RemoveTrailing($currentPath, '/'), '/'))->Split('/')->Size);
			if($currentPath == '');
				$rootPath = '';
			else;
				$rootPath = $rootPath + '../';
			/if;
		/Loop;
	



// fbx_Layouts.inc file is only required in the Fusebox application's root directory.
// code -9984 = file missing in Lasso 8
// code 404 = file missing in Lasso 9

		protect;
		handle(error_code != -9984  && error_code != 404 && error_code != 0);
		   $_error->first = error_code;
		   $_error->second = error_msg;
		/handle;
		Include($currentPath + 'fbx_Layouts.inc');
		/protect;

		Fail_If(integer($_error->first) != -9984  && integer($_error->first) != 404 && integer($_error->first) != 0 ,-10011,'Problem in the layoutfile "' + $currentPath +  'fbx_Layouts.inc" (or there is an error in one of its components).
			<br><br>Error Code: ' + $_error->first + '
					Error: ' + $_error->second);

		protect;
		If($layoutfile->Size);
			Handle(error_code != 0);
				$_error->first = error_code;
				$_error->second = error_msg;
			/Handle;
			$layout = Include($currentPath + $layoutdir + $layoutfile);
		/If;
		/protect;
		
		Fail_If(integer($_error->first) != 0 , -10012, 'Problem in the layoutfile "' + $layoutdir +  $layoutfile + '".'  + '
		<br><br>Error Code: ' + $_error->first + '
		Error: ' + $_error->second );


	/If;
	

	var('_layoutpath' = $layoutpath->Split('/'));
	var('_circuitalias' = $circuitalias->Split('/'));

	$_layoutpath->Remove;
	$_circuitalias->Remove;

	$layoutpath = $_layoutpath->Join('/');
	$circuitalias = $_circuitalias->Join('/');
	
/While;


$layout;
]