[Output_None]
<?LassoScript
// -------------------------------------------------------------------------------------------
// This file is broken into eleven sections. 
// Section One is the Fusedoc for the file.
// Section Two contains the public "API-style" variables that are used in the Fusebox framework.
// Section Three established the private structure "fb_".
// Section Four is the former formURL2attributes Custom Tag. In LassoFusebox all ACTION_PARAMS
// are put into a common scope.
// Section Five includes the fbx_circuits.lasso file.
// Section Six creates a mirror of the fusebox.circuits strucure for reverse look-ups.
// Section Seven includes the root fbx_settings.lasso file.
// Section Eight massages the variable FUSEACTION and begins the aliased lookup process.
// Section Nine includes nested fbx_settings.lasso files top-to-bottom.
// Section Ten includes the target circuit fbx_switch file, which processes the requested fuseaction.
// Section Eleven includes any layout files, in bottom-to-top order to allow layouts to be nested.
// It also outputs the final display of the page.
// -------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------
// SECTION ONE
// For more information about Fusedocs and how to read them, visit fusebox.org and halhelms.com. 
// -------------------------------------------------------------------------------------------
?>

[Lasso_Comment]
<fusedoc fuse="FBX_FUSEBOX30_LP6.LASSO" specification="2.0">
	<responsibilities>
		I am the code behind Fusebox 3.0 that handles nesting, layouts--oh, a bunch of stuff, really. PLEASE BE VERY CAREFUL ABOUT MAKING ANY CHANGES TO THIS FILE, AS IT WILL RENDER IT NON-COMPLIANT WITH THE STANDARD NOTED ABOVE. There is no need to modify this file for any settings. All settings can occur in fbx_settings.lasso.
	</responsibilities>
	<properties>
		<property name="version" value="3.01" />
		<property name="build" value="1b" />
		<history author="John Quarto-vonTivadar" date="27 Sep 2001" email="jcq@mindspring.com">Portions of code contributed by Steve Nelson, Hal Helms, Jeff Peters, Nat Papovich, Patrick McElhaney, Fred Sanders, Bill Wheatley and Stan Cox.</history>
		<history author="Nat Papovich" date="Oct 2001" email="mcnattyp@yahoo.com" type="Update">Converted to cfscripting, bug fixes for final release.</history>
		<history author="Nat Papovich" date="Nov 2001" email="mcnattyp@yahoo.com" type="Update" />
		<history author-"Michael S. McKellip" date="Sept 2002" email="mmckellip@lassofusebox.org" type="Update">Converted to Lasso Professional 6</history>
	</properties>
	<io>
		<out>
			<structure name="fusebox" scope="variables" comments="this is the public API of variables that should be treated as read-only">
				<boolean name="isCustomTag" default="FALSE" />
				<boolean name="isHomeCircuit" default="FALSE" />
				<boolean name="isTargetCircuit" default="FALSE" />
				<string name="fuseaction" comments="will be assigned a literal value of 'fusebox.defaultfuseaction' if attributes.fuseaction comes in as 'circuit.' with no fuseaction passed." />
				<string name="circuit" />
				<string name="homeCircuit" />
				<string name="targetCircuit" />
				<string name="thisCircuit" />
				<string name="thisLayoutPath" />
				<boolean name="suppressErrors" default="FALSE" />
				<string name="currentPath" />
				<string name="rootPath" />
			</structure>
			<structure name="FB_" comments="Internal use only. Please treat the FB_ as a reserved structure, not to be touched.">
			</structure>
		</out>
	</io>
</fusedoc> 
[/Lasso_Comment]

<?LassoScript
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
// altogether) layout files in fbx_layouts.lasso.

// fusebox.IsHomeCircuit:
// This boolean variable is set and re-set as the Fusebox framework does its business pulling in 
// fbx_settings.lasso files and the fbx_switch.lasso file and fbx_layouts.lasso files (and associated 
// layout files). It is TRUE only when the currently accessed circuit is the home circuit running this 
// application.

// fusebox.IsTargetCircuit:
// Like isHomeCircuit above, this boolean variable is used during the process of cfincluding files. It 
// is TRUE only when the currently accessed circuit is the target circuit running specified by 
// circuit.fuseaction.

// fusebox.Circuit:
// This is the first part of the compound fuseaction that gets passed as attributes.fuseaction.

// fusebox.Fuseaction:
// This is the second part of a compound fuseaction that gets passed as attributes.fuseaction. 
// fusebox.fuseaction is the variable expression evaluated in fbx_switch.lasso.

// fusebox.HomeCircuit:
// This variable is set to the root-level circuit as defined in fusebox.circuits strucure.

// fusebox.TargetCircuit:
// This is the circuit the requested fuseaction is to run in. The difference between this variable and 
// fusebox.circuit above, is that this variable is the circuit alias that was found in the 
// fusebox.circuits file as opposed to the circuit that is being attempted to be found. In all 
// non-error situations fusebox.TargetCircuit and fusebox.Circuit will be the same.
	
// fusebox.ThisCircuit:
// Like IsTargetCircuit and IsHomeCircuit above, this variable is set and re-set during the process of 
// running the fbx_settings.lasso files and the fbx_switch.lasso file, and refers to the circuit alias 
// of the circuit from which files are currently being accessed.

// fusebox.ThisLayoutPath:
// This is the directory path that the layout file being used is called from. This variable changes as 
// the layouts are nested one inside another, building the overall page layout.

// fusebox.suppressErrors:
// A boolean variable, which defaults to FALSE. If TRUE, the Fusebox framework will attempt to give \
// you "smarter" errors that may occur from within its own code as it applies to the Framework itself. 
// If FALSE (default), you will receive the native Lasso error messages. During development you may want 
// to turn this to TRUE and FALSE alternately to ensure you've got your framework set up properly. Set 
// this to TRUE in a production enviroment, since at that point errors that occur will not be Fusebox 
// framework errors but rahter erros in your fuseactions and fuses.	

// fusebox.Circuits:
// This variable is a structure whose aliases are the circuit names created in fbx_circuits.lasso and 
// whose values are the directory paths to those circuits.

// fusebox.currentPath:
// This variable takes you from the root circuit to any location it is called. If you use images in 
// directories beneath individual circuits, this variable will point to that circuit like 
// "directory/directory/".
	
// fusebox.rootPath:
// This variable takes you from the circuit it is being called from, back to the root. This is helpful 
// to determine your location relative to the root application.
// -------------------------------------------------------------------------------------------

Variable:'_section' = 2;

Library:'fbx_Library.lasso';
Variable:'_error' = (Pair:0,(Error_NoError));

Variable:'fusebox' = (Map);

$fusebox->(Insert:'IsCustomTag'=false);

$fusebox->(Insert:'IsHomeCircuit'=false);
$fusebox->(Insert:'IsTargetCircuit'=false);
$fusebox->(Insert:'fuseaction'='');
$fusebox->(Insert:'circuit'='');
$fusebox->(Insert:'HomeCircuit'='');
$fusebox->(Insert:'TargetCircuit'='');
$fusebox->(Insert:'thisCircuit'='');
$fusebox->(Insert:'thislayoutpath'='');
$fusebox->(Insert:'suppressErrors'=false);

$fusebox->(Insert:'Circuits'=(Map));
Variable:'_Circuits' = @($fusebox->(Find:'Circuits'));

$fusebox->(Insert:'currentPath'='');
$fusebox->(Insert:'rootPath'='');

// -------------------------------------------------------------------------------------------
// SECTION THREE
// FB_ is a structure encompassing "private" variables used by the underlying Fusebox framework. 
// Make no changes to it without a full understanding of the ramifications of those changes.
// -------------------------------------------------------------------------------------------

$_section = 3;

Variable:'FB_' = (Map);

// -------------------------------------------------------------------------------------------
// SECTION FOUR
// This code used to be in a Custom Tag called formURL2attributes.lasso. It copies all incoming 
// FORM and URL variables to VARIABLES scope.
// -------------------------------------------------------------------------------------------

$_section = 4;

Iterate:(Action_Params),(Variable:'_temp');
	If:!($_temp->First)->(BeginsWith:'-');
		Variable:($_temp->First) = ($_temp->Second);
	/If;
/Iterate;

// -------------------------------------------------------------------------------------------
// SECTION FIVE
// Attempt to include the fbx_Circuits.lasso file, which should be in the same directory as
// this file.
// -------------------------------------------------------------------------------------------

$_section = 5;

Include:'fbx_Circuits.lasso';

// -------------------------------------------------------------------------------------------
// SECTION SIX
// Create a reverse path look-up of the fusebox.Circuits structure which can be used later to 
// conveniently look up the circuit alias of whichever circuit is being accessed at that moment, 
// particularly when determining fusebox.thisCircuit.
// -------------------------------------------------------------------------------------------

$_section = 6;

Fail_If:$_Circuits->Size == 0,-10001,'The circuits structure does not exist. This must be defined in the Fusebox application\'s root fbx_circuits.lasso file.';

$FB_->(Insert:'ReverseCircuitPath'=(Map));
Variable:'_ReverseCircuits' = @($FB_->(Find:'ReverseCircuitPath'));
Iterate:$_Circuits,(Variable:'aCircuit');
	$_ReverseCircuits->(Insert:$aCircuit->Second=$aCircuit->First);
	
	If:$_Circuits->(Find:$aCircuit->First)->(Split:'/')->Size == 1;
		$fusebox->(Insert:'HomeCircuit'=$aCircuit->First);
		$fusebox->(Insert:'IsHomeCircuit'=true);
	/If;
/Iterate;

// -------------------------------------------------------------------------------------------
// SECTION SEVEN
// Attempt to include the fbx_Settings.lasso file from the root directory, the same directory 
// that this file is being run from.
// -------------------------------------------------------------------------------------------

$_section = 7;
Include:'fbx_Settings.lasso';


// -------------------------------------------------------------------------------------------
// SECTION EIGHT
// Dissect attributes.fuseaction (available in the attributes scope either from being converted 
// in the formURL2attributes section or via the above included fbx_settings.lasso file in the 
// root directory). If attributes.fuseaction is not a compound fuseaction (i.e. it only includes 
// the circuit in the form of "?fuseaction=circuit."), then set the fuseaction as blank, which 
// the target circuit's default CASE tag will pick up. Now look up the target circuit in the 
// fusebox.circuit structure for the full path to the circuit.
// -------------------------------------------------------------------------------------------

$_section = 8;

$FB_->(Insert:'rawFA' = $fuseaction);
If:$FB_->(Find:'rawFA')->(Split:'.')->Size == 2 && $FB_->(Find:'rawFA')->(EndsWith:'.');
	$fusebox->(Insert:'fuseaction' = 'fusebox.defaultfuseaction');
Else;
	$fusebox->(Insert:'fuseaction' = $FB_->(Find:'rawFA')->(Split:'.')->(Get:2));
/If;

$fusebox->(Insert:'circuit' = $FB_->(Find:'rawFA')->(Split:'.')->(Get:1));
$fusebox->(Insert:'TargetCircuit' = $fusebox->(Find:'circuit'));

Fail_If:!(Variable_Defined:'fuseaction') || !($_Circuits->(Find:$fusebox->(Find:'circuit'))),-10003,'The variable "fuseaction" is not available or the Fusebox framework could not find the circuit you requested: "'+($fusebox->(Find:'circuit'))+'".';

// -------------------------------------------------------------------------------------------
// SECTION NINE
// Attempt to include any nested fbx_Settings.lasso files, in top-to-bottom order so that 
// variables set in children fbx_settings.lasso files can overwrite variables set in higher 
// fbx_settings.lasso files. To prevent children fbx_settings.lasso files from overwriting 
// variables, use FBX_PARAM rather than VARIABLE. Alternately, any child fbx_settings.lasso can 
// use VARIABLE to set a variable and lower fbx_settings.lasso files cannot overwrite it unless 
// they use VARIABLE. If any fbx_settings.lasso file or directory alias cannot be found, 
// continue on.
// -------------------------------------------------------------------------------------------

$_section = 9;

$FB_->(Insert:'fullPath' =       (String_RemoveLeading:(String_RemoveLeading:$_Circuits->(Find:$fusebox->(Find:'TargetCircuit')),-Pattern=$_Circuits->(Find:$fusebox->(Find:'HomeCircuit'))),-Pattern='/'));
$FB_->(Insert:'Corepath' = '');
$fusebox->(Insert:'thisCircuit' = $fusebox->(Find:'HomeCircuit'));

Iterate:$FB_->(Find:'fullPath')->(Split:'/'),(Variable:'aPath');
	If:$FB_->(Find:'corePath')->Size;
		$FB_->(Insert:'Corepath' = $FB_->(Find:'corePath') + '/' + $aPath);
	Else;
		$FB_->(Insert:'Corepath' = $aPath);
	/If;
	
	$fusebox->(Insert:'IsHomeCircuit' = false);
	$fusebox->(Insert:'currentPath' = $FB_->(Find:'Corepath') + '/');
	
	$fusebox->(Insert:'rootPath' = '');
	Loop:(String_RemoveLeading:(String_RemoveTrailing:$fusebox->(Find:'currentPath'),-Pattern='/'),-Pattern='/')->(Split:'/')->Size;
		$fusebox->(Insert:'rootPath' = $fusebox->(Find:'rootPath') + '../');
	/Loop;
	
	If:$_ReverseCircuits->(Find:$_Circuits ->(Find:$fusebox->(Find:'HomeCircuit')) + '/' + $FB_->(Find:'Corepath'));
		$fusebox->(Insert:'thisCircuit' = $_ReverseCircuits->(Find:$_Circuits->(Find:$fusebox->(Find:'HomeCircuit')) + '/' + $FB_->(Find:'Corepath')));
		If:$fusebox->(Find:'thisCircuit') == $fusebox->(Find:'TargetCircuit');
			$fusebox->(Insert:'IsTargetCircuit' = true);
		Else;
			$fusebox->(Insert:'IsTargetCircuit' = false);
		/If;
		Include:$fusebox->(Find:'currentPath') + 'fbx_Settings.lasso';
	/If;
/Iterate;

// -------------------------------------------------------------------------------------------
// SECTION TEN
// Now "reach down" and include the fbx_switch.lasso in the target circuit, executing 
// fusebox.fuseaction. Store the contents of the output into a variable called fusebox.layout.
// -------------------------------------------------------------------------------------------

$_section = 10;

$fusebox->(Insert:'thisCircuit' = $fusebox->(Find:'TargetCircuit'));
$fusebox->(Insert:'IsTargetCircuit' = true);
$FB_->(Insert:'fuseboxpath' = $FB_->(Find:'fullPath'));
If:$FB_->(Find:'fuseboxpath')->Size;
	$FB_->(Insert:'fuseboxpath' = $FB_->(Find:'fuseboxpath') + '/');
	$fusebox->(Insert:'IsHomeCircuit' = false);
Else;
	$fusebox->(Insert:'IsHomeCircuit' = true);
/If;
$fusebox->(Insert:'currentPath' = $FB_->(Find:'fuseboxpath'));

$fusebox->(Insert:'rootPath' = '');
Loop:(String_RemoveLeading:(String_RemoveTrailing:$FB_->(Find:'fuseboxpath'),-Pattern='/'),-Pattern='/')->(Split:'/')->Size;
	$fusebox->(Insert:'rootPath' = $fusebox->(Find:'rootPath') + '../');
/Loop;

FBX_SaveContent: -Variable='_layout';
	Include:$FB_->(Find:'fuseboxpath') + 'fbx_Switch.lasso';
/FBX_SaveContent;
$fusebox->(Insert:'layout' = @$_layout);

// -------------------------------------------------------------------------------------------
// SECTION ELEVEN
// Now handle the layouts, resolving them in bottom-to-top order to nest the circuits, if needed. 
// Also set fusebox.thisCircuit equal to the circuit name of the current circuit the code is 
// passing through, which will let any layout files in circuits know where they are. If 
// attempting to include any layout file throws an error, then do nothing and continue on. 
// This ENTIRE section and functionality of nesting layouts and controlling layouts via layout 
// files is optional. If you do not have any layout files (fbx_layout.lasso), or only have a 
// layout file in your root directory, everything will still work.
// -------------------------------------------------------------------------------------------

$_section = 11;

$FB_->(Insert:'circuitalias' = $_Circuits->(Find:$fusebox->(Find:'TargetCircuit')));
$FB_->(Insert:'layoutpath' = $_Circuits->(Find:$fusebox->(Find:'TargetCircuit')));
While:$FB_->(Find:'layoutpath')->Size;
	If:$_ReverseCircuits->(Find:$FB_->(Find:'circuitalias'));
		Protect;
			$fusebox->(Insert:'thisCircuit' = $_ReverseCircuits->(Find:$FB_->(Find:'circuitalias')));
			Handle:false;
				$fusebox->(Insert:'thisCircuit' = '');
			/Handle;
		/Protect;
		
		If:$fusebox->(Find:'thisCircuit') == $fusebox->(Find:'TargetCircuit');
			$fusebox->(Insert:'IsTargetCircuit' = true);
		Else;
			$fusebox->(Insert:'IsTargetCircuit' = false);
		/If;
		If:$fusebox->(Find:'thisCircuit') == $fusebox->(Find:'HomeCircuit');
			$fusebox->(Insert:'IsHomeCircuit' = true);
		Else;
			$fusebox->(Insert:'IsHomeCircuit' = false);
		/If;
		$fusebox->(Insert:'ThisLayoutPath' =       (String_RemoveLeading:(String_RemoveLeading:$FB_->(Find:'layoutpath'),-Pattern=$_Circuits->(Find:$fusebox->(Find:'HomeCircuit'))),-Pattern='/'));
		If:$fusebox->(Find:'ThisLayoutPath')->Size;
			$fusebox->(Insert:'ThisLayoutPath' = $fusebox->(Find:'ThisLayoutPath') + '/');
		/If;
		$fusebox->(Insert:'currentPath' = $fusebox->(Find:'ThisLayoutPath'));
		
		$fusebox->(Insert:'rootPath' = '');
		Loop:(String_RemoveLeading:(String_RemoveTrailing:$fusebox->(Find:'ThisLayoutPath'),-Pattern='/'),-Pattern='/')->(Split:'/')->Size;
			$fusebox->(Insert:'rootPath' = $fusebox->(Find:'rootPath') + '../');
		/Loop;
		
		Protect;
			Include:$fusebox->(Find:'ThisLayoutPath') + 'fbx_Layouts.lasso';
			Handle:false;
				$fusebox->(Insert:'layoutfile' = '');
				$fusebox->(Insert:'layoutdir' = '');
			/Handle;
		/Protect;
		
		If:$fusebox->(Find:'layoutfile')->Size;
			FBX_SaveContent: -Variable='_layout';
				Include:$fusebox->(Find:'ThisLayoutPath') + $fusebox->(Find:'layoutdir') + $fusebox->(Find:'layoutfile');
			/FBX_SaveContent;
			$fusebox->(Insert:'layout' = @$_layout);
		/If;
	/If;
	
	Variable:'_layoutpath' = $FB_->(Find:'layoutpath')->(Split:'/');
	Variable:'_circuitalias' = $FB_->(Find:'circuitalias')->(Split:'/');
	$_layoutpath->Remove;
	$_circuitalias->Remove;
	$FB_->(Insert:'layoutpath' = $_layoutpath->(Join:'/'));
	$FB_->(Insert:'circuitalias' = $_circuitalias->(Join:'/'));
/While;
?>
[/Output_None]

[Output:$fusebox->(Find:'layout'), -EncodeNone]

<?LassoScript
Handle:(Error_CurrentError) != (Error_NoError) && $fusebox->(Find:'suppressErrors');
	Variable:'_rethrow' = false;
	Select:$_section;
		Case:'5';
			If:(Error_CurrentError) >> 'fbx_Circuits.lasso';
				Fail:-10000,'The Fusebox framework could not find the file fbx_Circuits.lasso. If you think this error is incorrect, turn off the Fusebox suppress error messages flag by setting fusebox.SuppressErrors to FALSE, and you will receive Lasso\'s "normal" error output.';
			Else;
				$_rethrow = true;
			/If;
		Case:'6';
			If:(Error_CurrentError) >> 'fbx_Circuits.lasso';
				Fail:-10001,'The circuits structure does not exist. This must be defined in the Fusebox application\'s root fbx_circuits.lasso file. If you think this error is incorrect, turn off the Fusebox suppress error messages flag by setting fusebox.SuppressErrors to FALSE, and you will receive Lasso\'s "normal" error output.';
			Else;
				$_rethrow = true;
			/If;
		Case:'7';
			If:(Error_CurrentError) >> 'fbx_Settings.lasso';
				Fail:-10002,'The Fusebox framework could not find the file fbx_Settings.lasso. If you think this error is incorrect, turn off the Fusebox suppress error messages flag by setting fusebox.SuppressErrors to FALSE, and you will receive Lasso\'s "normal" error output.';
			Else;
				$_rethrow = true;
			/If;
		Case:'8';
			If:(Error_CurrentError) >> ($fusebox->(Find:'circuit'));
				Fail:-10003,'The variable "fuseaction" is not available or the Fusebox framework could not find the circuit you requested: "'+($fusebox->(Find:'circuit'))+'". If you think this error is incorrect, turn off the Fusebox suppress error messages flag by setting fusebox.SuppressErrors to FALSE, and you will receive Lasso\'s "normal" error output.';
			Else;
				$_rethrow = true;
			/If;
		Case:'9';
			
		Case:'10';
			If:(Error_CurrentError) >> 'fbx_Switch.lasso';
				Fail:-10005,'I could not find '+($FB_->(Find:'fuseboxpath'))+'fbx_Switch.lasso (or one of its components such as an included fuse) in the "'+($fusebox->(Find:'circuit'))+'" circuit. If you think this error is incorrect, turn off the Fusebox suppress error messages flag by setting fusebox.SuppressErrors to FALSE, and you will receive Lasso\'s "normal" error output, which could be generated by a file included from fbx_switch.lasso.';
			Else;
				$_rethrow = true;
			/If;
		Case:'11';
			If:(Error_CurrentError) >> ($fusebox->(Find:'layoutfile'));
				Fail:-10006,'I could not find the layoutfile '+($fusebox->(Find:'ThisLayoutPath'))+($fusebox->(Find:'layoutdir'))+($fusebox->(Find:'layoutfile'))+' specified by '+($fusebox->(Find:'ThisLayoutPath'))+'fbx_Layouts.lasso. If you think this error is incorrect, turn off the Fusebox suppress error messages flag by setting fusebox.SuppressErrors to FALSE, and you will receive Lasso\'s "normal" error output.';
			Else;
				$_rethrow = true;
			/If;
		Case;
			$_rethrow = true;
	/Select;
	If:$_rethrow;
		Fail:(Error_CurrentError: -ErrorCode),(Error_CurrentError);
	/If;
/Handle;
?>
