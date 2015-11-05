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
		<history author="Tami Williams" date="05/23/08" email="tami@asktami.com" type="Update" />
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



var: 'self' ='index.lasso?fuseaction=' ;

// alternative [$self] variable with random number [noCache] custom tag included to defeat caching
// var: 'self' ='index.lasso?' + (noCache) +  '&fuseaction=' ;

// IF you're going to create a LassoApp of this application (called MailForm.LassoApp) change the [$self] variable to:
// var: 'self' ='MailForm.LassoApp?fuseaction=' ;



var: 'appSiteMap' = (Map);
$appSiteMap->(Insert:'ghighlight'='#e5ebf4');
$appSiteMap->(Insert:'galtrowcolor'='#cf9');
$appSiteMap->(Insert:'gphone'='999-999-9999');
$appSiteMap->(Insert:'gYear'='2008');
$appSiteMap->(Insert:'gsitename'='LassoFusebox Sample MailForm');
$appSiteMap->(Insert:'gSeed'='myEncryptionSeed');
$appSiteMap->(Insert:'FileUsername'='fusn');			// Username for file permissions outside root
$appSiteMap->(Insert:'FilePassword'='fpwd');			// Password for file permissions outside root


If: $appLocation == 'lassofusebox' ;
// live site (default)

	$appSiteMap->(Insert:'gmailhost'='mail.pointinspace.com');
	$appSiteMap->(Insert:'fromEmail'='rich@lassofusebox.org');
	$appSiteMap->(Insert:'gmailto'='rich@lassofusebox.org');
	$appSiteMap->(Insert:'gmailbcc'='info@asktami.com');

else: $appLocation == 'asktami'   ||  $appLocation == 'local' ;
// test site or local hard drive

	$appSiteMap->(Insert:'gmailhost'='YOUR MAIL SERVER');
	$appSiteMap->(Insert:'fromEmail'='YOUR FROM ADDRESS');
	$appSiteMap->(Insert:'gmailto'='YOUR TO ADDRESS');
	$appSiteMap->(Insert:'gmailbcc'='YOUR BCC ADDRESS');

/if;


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
'isValid' = '',
'success' = '' ;

?>