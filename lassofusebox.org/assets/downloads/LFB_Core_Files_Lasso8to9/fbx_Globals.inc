[
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
		<history author="Tami Williams" date="4/5/2012" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<out>
			<string name="fuseaction" scope="variables" />
			<string name="gSiteMap" scope="variables" />
			<string name="gServerName" scope="variables" />
			<string name="appLocation" scope="variables" />
			<string name="debugflag" scope="variables" />
			<string name="debuginlineflag" scope="variables" />
			<string name="errckDbname" scope="variables" />
			<string name="errckTblname" scope="variables" />
			<string name="errckCode" scope="variables" />
			<string name="errckError" scope="variables" />
			<string name="errckFound" scope="variables" />
			<string name="errckAction" scope="variables" />
			<string name="errckActionStatement" scope="variables" />
			<string name="feedback" scope="variables" />
			<string name="logMessage" scope="variables" />
			<string name="valError" scope="variables" />
			<string name="isValid" scope="variables" />
			<string name="success" scope="variables" />
		</out>
	</io>
</fusedoc>
*/

/*
-------------------------------------------------------------------------------------------
EVERYTHING IN THIS FILE = REQUIRED VARS (do not remove)
-------------------------------------------------------------------------------------------
*/

// default fuseaction
FBX_Param(-Name='fuseaction', -Default='home.welcome' );


//	put settings here that should ALWAYS run; they may be overridden by settings in child circuits
// you can put settings here that use/rely on fusebox map variables

FBX_Param(-Name='self', -Default='index.lasso?fuseaction=' );
// FBX_Param(-Name='selfSSL', -Default='https://127.0.0.1/index.lasso?fuseaction=' );

// alternative [$self] variable with random number [noCache] custom tag included to defeat caching
// FBX_Param(-Name='self', -Default='index.lasso?'+ noCache + '&fuseaction=' );

FBX_Param(-Name='baduser', -Default='index.lasso?'+ noCache + '&fuseaction=home.baduser' );

// FOR LASSO 8 only: IF you're going to create a LassoApp of this application change the [$self] variable to:
// var('self' ='AppName.LassoApp?fuseaction=' );

// to add anchor tags to session LINKS
//<a href="<?LassoScript Output('#anchorThisLink', -EncodeNone);>?>">ThisLink</a>



/*
*******************************************************************************************
*******************************************************************************************
MISCELLANEOUS CODING SUGGESTIONS NOT REQUIRED BY FUSEBOX
*******************************************************************************************
*******************************************************************************************
*/

var('pgtitle' = tw_TitleCase($fuseaction));



/*
-------------------------------------------------------------------------------------------
GLOBAL SERVER SETTINGS
-------------------------------------------------------------------------------------------
assumes Local Hard Drive uses the following:
	http://127.0.0.1/[your root directory]/index.lasso
	
nice to do in case you use different upload paths, databases, etc. 
depending on where the application is being run
-------------------------------------------------------------------------------------------
*/

if(!Var_Defined('gServerName'));
	Var('gServerName' = server_name);
/If;


If($gServerName >> 'asktami');
				//	Public Server - asktami DBs, asktami upload folder
				var('appLocation' = 'asktami');
				
Else($gServerName >> 'lassofusebox' );
				//	Public  Server - Live DBs, lassofusebox upload folder
				var('appLocation' = 'lassofusebox');
Else;
	   //	Local Hard Drive, local upload folder
	   var('appLocation' = 'local');
/If;



/*
----------------------------------------------------------------------------
OTHER VARIABLES
----------------------------------------------------------------------------
*/

var('gSiteMap' = Map);

$gSiteMap->Insert('tab'='\t');
$gSiteMap->Insert('cr'='\n');
$gSiteMap->Insert('ghighlight'='#e5ebf4');
$gSiteMap->Insert('galtrowcolor'='#cf9');
$gSiteMap->Insert('gphone'='770-457-3221');
$gSiteMap->Insert('gYear'='2012');

$gSiteMap->Insert('gmailhost'='YOUR MAIL HOST');
$gSiteMap->Insert('fromEmail'='YOUR FROM EMAIL ADDRESS');
$gSiteMap->Insert('gmailto'='YOUR TO EMAIL ADDRESS');
$gSiteMap->Insert('gmailbcc'='YOUR BCC EMAIL ADDRESS');

$gSiteMap->Insert('gsitename'='LFB_Core_Files');
$gSiteMap->Insert('gSeed'='myEncryptionSeed');


//	path & layout include vars
$gSiteMap->Insert('js' = 'scripts/');
$gSiteMap->Insert('css' =  'css/');
$gSiteMap->Insert('img' =  'images/');
$gSiteMap->Insert('uploadPath'='///Library/WebServer/Documents/uploads/');

$gSiteMap->Insert('sitetemplate' = '_lay/lay_site.lasso' );
$gSiteMap->Insert('debuginline' =  '_common/dsp_debuginline.inc' );
$gSiteMap->Insert('debug' =  '_common/dsp_debug.inc');
$gSiteMap->Insert('feedbackmsg' =  '_common/dsp_feedback.inc');
$gSiteMap->Insert('valErrormsg' =  '_common/dsp_valError.inc');

local('temp' = '');
iterate($gSiteMap, #temp );
var(#temp->first = @($gSiteMap->Find((#temp->first)) ));
/iterate;




var('debugflag' = 'N' ,							// debug	Y = display the debug vars from _common/dsp_debug.inc
'debuginlineflag' = 'N' ,						// debuginlineflag	Y = display the inline debug vars from _common/dsp_debuginline.inc
'errckDbname' = '' ,
'errckTblname' = '' ,
'errckCode' = Error_NoError(-ErrorCode) ,
'errckError' = (Error_NoError) ,
'errckFound' = (integer) ,
'errckAction' = '' ,
'errckActionStatement' = '' ,
'feedback' = '',
'logMessage' = '',
'valError' =  (map) ,							// valError, isValid and success are used by val_ pages
'isValid' = '',
'success' = '' );


]