<?LassoScript
/*
<fusedoc fuse="fbx_Settings.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I set up the enviroment settings for this circuit. If this settings file is being inherited, then you can use VARIABLE to override
		a value set in a parent circuit or FBX_PARAM to accept a value set by a parent circuit
	</responsibilities>	
	<properties>
		<history author="Michael McKellip" email="mmckellip@lassofusebox.org" date="1/5/2003" type="create">
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<in>
			<structure name="fusebox">
				<boolean name="isRootCircuit" comments="Is the circuit currently executing the root circuit?" />
			</structure>
		</in>
		<out>
			<string name="self" scope="variables" />
			<string name="SSL_self" scope="variables" />
			<string name="fuseaction" scope="variables" />
			<string name="gLoginMap" scope="variables" />
			<string name="appSiteMap" scope="variables" />
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
READ ME
-------------------------------------------------------------------------------------------
put settings here that should ALWAYS run; they may be overridden by settings in child circuits
you can put settings here that use/rely on fusebox map variables
-------------------------------------------------------------------------------------------
*/

// FMP timestamp format (%D %r) looks like this: 09/02/2006 03:33:25 PM
// MySQL datetime & timestamp format (%Q %T) looks like: 2006-09-02 15:33:25
Date_SetFormat: -Format='%Q %T';


var: 'self' ='index.lasso?fuseaction=' ;
// var: 'selfSSL' ='https://127.0.0.1/index.lasso?fuseaction=' ;

// alternative [$self] variable with random number [noCache] custom tag included to defeat browser caching
// var: 'self' ='index.lasso?' + (noCache) +  '&fuseaction=' ;

// IF you're going to create a LassoApp of this application change the [$self] variable to:
// var: 'self' ='AppName.LassoApp?fuseaction=' ;


// to add anchor tags to session LINKS
//<a href="<?LassoScript Output:'#anchorThisLink', -EncodeNone;>?>">ThisLink</a>


var: 'appSiteMap' = (Map);
$appSiteMap->(Insert:'ghighlight'='#e5ebf4');
$appSiteMap->(Insert:'galtrowcolor'='#cf9');
$appSiteMap->(Insert:'gphone'='770-457-3221');
$appSiteMap->(Insert:'gYear'='2008');
$appSiteMap->(Insert:'gmailhost'='YOUR MAIL HOST');
$appSiteMap->(Insert:'fromEmail'='YOUR FROM EMAIL ADDRESS');
$appSiteMap->(Insert:'gmailto'='YOUR TO EMAIL ADDRESS');
$appSiteMap->(Insert:'gmailbcc'='YOUR BCC EMAIL ADDRESS');
$appSiteMap->(Insert:'gsitename'='LFB_Core_Files');
$appSiteMap->(Insert:'gSeed'='myEncryptionSeed');
$appSiteMap->(Insert:'FileUsername'='fusn');				//Username for file permissions outside root
$appSiteMap->(Insert:'FilePassword'='fpwd');				//Password for file permissions outside root

local:'temp' = '';
iterate: $appSiteMap, #temp ;
var: (#temp->first) = @($appSiteMap->(Find:(#temp->first)) );
/iterate;


/*
-------------------------------------------------------------------------------------------
REQUIRED VARS (do not remove)
-------------------------------------------------------------------------------------------
*/

var: 'debugflag' = 'N' ,							// debug	Y = display the debug vars from _common/dsp_debug.inc
'debuginlineflag' = 'N' ,						// debuginlineflag	Y = display the inline debug vars from _common/dsp_debuginline.inc
'errckDbname' = '' ,
'errckTblname' = '' ,
'errckCode' = (Error_NoError: -ErrorCode) ,
'errckError' = (Error_NoError) ,
'errckFound' = (integer) ,
'errckAction' = '' ,
'errckActionStatement' = '' ,
'feedback' = '',
'logMessage' = '',
'valError' =  (map) ,							// valError, isValid and success are used by val_ pages
'isValid' = '',
'success' = '' ;



// -------------------------------------------------------------------------------------------
// SITEWIDE NAVIGATION - PRE AND POST LOGIN
// -------------------------------------------------------------------------------------------

FBX_Param: -Name='XFA_cookietest', -Default=$self + 'home.cookietest' ;			// used to check if cookies and javascript are turned on
FBX_Param: -Name='XFA_logout', -Default= $self + 'home.logoutA' ;						// used for Logout button


/*
*******************************************************************************************
*******************************************************************************************
MISCELLANEOUS CODING SUGGESTIONS NOT REQUIRED BY FUSEBOX
*******************************************************************************************
*******************************************************************************************
*/

// var: 'pgtitle' = (TitleCase: $fuseaction) ;



/*
-------------------------------------------------------------------------------------------
TO OVERRIDE A SESSION VAR
-------------------------------------------------------------------------------------------
IF sometimes "someVariable" comes from URL and then its stored in a session variable do the following
(if this was not here then the session variable would ALWAYS override the URL variable)
-------------------------------------------------------------------------------------------
*/

// 	if: (action_param:'someVariable') != '' ;
// 		var:'someVariable' = encode_sql: (action_param:'someVariable') ;
// 	/if;




/*
-------------------------------------------------------------------------------------------
DATABASE CONNECTIONS
-------------------------------------------------------------------------------------------

"t" is the prefix for table names
"d" is the prefix for database names (if using more than 1 database)
usually put all tables in the same database and just create 1 var for that database's name

You can override the settings in individual inlines like this:

inline: -inlineName='thisInlineName',
$readCon,
-table='newtablename',
-maxRecords = '10',
-search;
/inline;

OR

inline: -inlineName='thisInlineName',
$readCon,
-SQL='SQLStatement';
/Inline;


OR


inline: -inlineName='thisInlineName',
$readCon,
-SQL=(var:'SQLStatement');
/Inline;



// see fbx_Globals.inc for code that defines appLocation
-------------------------------------------------------------------------------------------
*/


If: $appLocation == 'test';
//test
		var: 'dbName' = 'testDbName',
				'dbpwd' = 'testDbpassword',
				'dbusn' = 'testDbusername' ;
		
Else: $appLocation == 'live';
// live
		var: 'dbName' = 'liveDbName',
				'dbpwd' = 'liveDbpassword',
				'dbusn' = 'liveDbbusername' ;
		
Else;
// local
		var: 'dbName' = 'localDbName',
				'dbpwd' = 'localDbpassword',
				'dbusn' = 'localDbbusername' ;
/If;

    
// read Connection
var: 'readCon' = (array:
	-username=$dbusn,
	-password=$dbpwd,
	-database = $dbName,
    -maxRecords = 'all',
    -keyField = 'ID');
    
        
// write (update) Connection
var: 'writeCon' = (array:
	-username=$dbusn,
	-password=$dbpwd,
	-database = $dbName,
	'modifier' = 'web',
	'dateModified' = (date),
    -keyField = 'ID');
    
    
// add Connection
var: 'addCon' =(array:
	-username=$dbusn,
	-password=$dbpwd,
	-database = $dbName,
	'creator' = 'web',
	'modifier' = 'web',
	'dateCreated' = (date),
	'dateModified' = (date),
    -keyField = 'ID');

?>