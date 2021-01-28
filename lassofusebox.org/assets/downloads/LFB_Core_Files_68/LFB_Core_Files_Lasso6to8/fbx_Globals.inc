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
		<history author="Tami Williams" date="06/13/2008" email="tami@asktami.com" type="Update" />
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


// default fuseaction
FBX_Param: -Name='fuseaction', -Default='home.welcome' ;


/*
-------------------------------------------------------------------------------------------
GLOBAL SERVER SETTINGS
-------------------------------------------------------------------------------------------
assumes Public Server uses:
	http://www.lassofusebox.org/index.lasso
	
and Local Hard Drive uses the following:
	http://127.0.0.1/[your root directory]/index.lasso
	
nice to do in case you use different upload paths, databases, etc. 
depending on where the application is being run from
-------------------------------------------------------------------------------------------
*/


// Be nice to the DNS server and only do this once
if: !(Global_Defined: 'gServerName');
		Global: 'gServerName' = (server_name) ;
/If;


If: $gServerName >> 'asktami';
				//	Public Server - asktami DBs, asktami upload folder
				var: 'appLocation' = 'test';
				
Else: $gServerName >> 'lassofusebox' ;
				//	Public  Server - Live DBs, lassofusebox.org upload folder
				var: 'appLocation' = 'live';
Else;
	   //	Local Hard Drive, local upload folder
	   var: 'appLocation' = 'local';
/If;


var: 'appGlobalsMap' = (Map);
$appGlobalsMap->(Insert:'tab'='\t');
$appGlobalsMap->(Insert:'cr'='\n');

//	path & layout include vars
$appGlobalsMap->(Insert: 'js' = 'scripts/');
$appGlobalsMap->(Insert: 'css' =  'css/');
$appGlobalsMap->(Insert: 'img' =  'images/');

$appGlobalsMap->(Insert: 'sitetemplate' = '_lay/lay_site.lasso' );
$appGlobalsMap->(Insert: 'debuginline' =  '_common/dsp_debuginline.inc' );
$appGlobalsMap->(Insert: 'debug' =  '_common/dsp_debug.inc');
$appGlobalsMap->(Insert: 'feedbackmsg' =  '_common/dsp_feedback.inc');
$appGlobalsMap->(Insert: 'valErrormsg' =  '_common/dsp_valError.inc');

$appGlobalsMap->(Insert:'uploadPath'='///Library/WebServer/Documents/LFB_Core_Files/uploads/');

local:'temp' = '';
iterate: $appGlobalsMap, #temp ;
var: (#temp->first) = @($appGlobalsMap->(Find:(#temp->first)) );
/iterate;

?>