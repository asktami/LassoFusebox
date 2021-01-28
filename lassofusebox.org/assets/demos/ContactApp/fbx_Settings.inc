<?LassoScript
/*
<fusedoc fuse="fbx_Settings.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I set up the enviroment settings for this circuit. If this settings file is being inherited, then you can use VARIABLE to override
		a value set in a parent circuit or FBX_PARAM to accept a value set by a parent circuit
	</responsibilities>	
	<properties>
		<history author="Rich Tretola" email="rich@lassofusebox.org" date="10/07/2002" type="Create">
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
			<string name="success" scope="variables" />
		</out>
	</io>
</fusedoc>
*/



 var: 'self' ='index.lasso?fuseaction=' ;

// alternative [$self] variable with random number [noCache] custom tag included to defeat caching
// var: 'self' ='index.lasso?' + (noCache) +  '&fuseaction=' ;

// IF you're going to create a LassoApp of this application (called ContactApp.LassoApp) change the [$self] variable to:
// var: 'self' ='ContactApp.LassoApp?fuseaction=' ;



var: 'appSiteMap' = (Map);
$appSiteMap->(Insert:'ghighlight'='#e5ebf4');
$appSiteMap->(Insert:'galtrowcolor'='#cf9');
$appSiteMap->(Insert:'gphone'='999-999-9999');
$appSiteMap->(Insert:'gYear'='2008');
$appSiteMap->(Insert:'gmailhost'='mail.pointinspace.com');
$appSiteMap->(Insert:'fromEmail'='rich@lassofusebox.org');
$appSiteMap->(Insert:'gmailto'='rich@lassofusebox.org');
$appSiteMap->(Insert:'gmailbcc'='info@asktami.com');
$appSiteMap->(Insert:'gsitename'='LassoFusebox Sample ContactApp');
$appSiteMap->(Insert:'gSeed'='myEncryptionSeed');
$appSiteMap->(Insert:'FileUsername'='fusn');			// Username for file permissions outside root
$appSiteMap->(Insert:'FilePassword'='fpwd');			// Password for file permissions outside root

local:'temp' = '';
iterate: $appSiteMap, #temp ;
var: (#temp->first) = @($appSiteMap->(Find:(#temp->first)) );
/iterate;


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
'valErrorLabel' =  (map) ,					// valErrorLabel used by val_contactForm.inc to highlight form labels
'isValid' = '',
'success' = '' ;

FBX_Param: -Name='hitcount', -Default=0;

If: $appLocation == 'lassofusebox' ;
// live site (default)

FBX_Param: -Name='datasource', -Default='LFB_database2';
FBX_Param: -Name='dbusername', -Default='LFB_lassofusebox';
FBX_Param: -Name='dbpassword', -Default='fuse1972xob';


else: $appLocation == 'asktami' ;
// test site

FBX_Param: -Name='datasource', -Default='asktami';
FBX_Param: -Name='dbusername', -Default='tamiw7';
FBX_Param: -Name='dbpassword', -Default='jt9haw5';

else;
// local hard drive

FBX_Param: -Name='datasource', -Default='test';
FBX_Param: -Name='dbusername', -Default='xxx';
FBX_Param: -Name='dbpassword', -Default='xxx';

/if;


// read Connection
var: 'readCon' = (array:
	-username = $dbusername,
	-password = $dbpassword,
	-database = $datasource,
    -maxRecords = 'all',
    -keyField = 'ID') ;


// write Connection
var: 'writeCon' = (array:
	-username = $dbusername,
	-password = $dbpassword,
	-database = $datasource,
    -keyField = 'ID');    


?>