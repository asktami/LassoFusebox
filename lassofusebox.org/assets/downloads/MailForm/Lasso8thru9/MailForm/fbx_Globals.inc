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
		<history author="Tami Williams" date="4/20/2012" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<out>
			<string name="fuseaction" scope="variables" />
			<string name="appSiteMap" scope="variables" />
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


// default fuseaction
FBX_Param(-Name='fuseaction', -Default='home.welcome');

var('self' ='index.lasso?fuseaction=' );

// alternative [$self] variable with random number [noCache] custom tag included to defeat caching
// var('self' ='index.lasso?' + (noCache) +  '&fuseaction=' );

// For Lasso 8 ONLY: IF you're going to create a LassoApp of this application (called MailForm.LassoApp) change the [$self] variable to(
// var('self' ='MailForm.LassoApp?fuseaction=' ));



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

var('appSiteMap' = (Map));
$appSiteMap->Insert('tab'='\t');
$appSiteMap->Insert('cr'='\n');
$appSiteMap->Insert('ghighlight'='#e5ebf4');
$appSiteMap->Insert('galtrowcolor'='#cf9');
$appSiteMap->Insert('gphone'='999-999-9999');
$appSiteMap->Insert('gYear'='2012');
$appSiteMap->Insert('gsitename'='LassoFusebox Sample MailForm');
$appSiteMap->Insert('gSeed'='myEncryptionSeed');
$appSiteMap->Insert('sitetemplate' = '_lay/lay_site.lasso' );



//	path & layout include vars
$appSiteMap->Insert('js' = 'scripts/');
$appSiteMap->Insert('css' =  'css/');
$appSiteMap->Insert('img' =  'images/');

$appSiteMap->Insert('sitetemplate' = '_lay/lay_site.lasso' );
$appSiteMap->Insert('debuginline' =  '_common/dsp_debuginline.inc' );
$appSiteMap->Insert('debug' =  '_common/dsp_debug.inc');
$appSiteMap->Insert('feedbackmsg' =  '_common/dsp_feedback.inc');
$appSiteMap->Insert('valErrormsg' =  '_common/dsp_valError.inc');




If($appLocation == 'lassofusebox' );
// live site (default)

	$appSiteMap->Insert('gmailhost'='mail.pointinspace.com');
	$appSiteMap->Insert('fromEmail'='rich@lassofusebox.org');
	$appSiteMap->Insert('gmailto'='rich@lassofusebox.org');
	$appSiteMap->Insert('gmailbcc'='info@asktami.com');

else($appLocation == 'asktami'   ||  $appLocation == 'local' );
// test site or local hard drive

	$appSiteMap->Insert('gmailhost'='YOUR MAIL SERVER');
	$appSiteMap->Insert('fromEmail'='YOUR FROM ADDRESS');
	$appSiteMap->Insert('gmailto'='YOUR TO ADDRESS');
	$appSiteMap->Insert('gmailbcc'='YOUR BCC ADDRESS');

/if;


local('temp' = '');
iterate($appSiteMap, #temp );
var((#temp->first) = @($appSiteMap->Find((#temp->first)) ));
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