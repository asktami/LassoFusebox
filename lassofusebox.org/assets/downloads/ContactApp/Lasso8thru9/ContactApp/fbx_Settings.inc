[
/*
<fusedoc fuse="fbx_Settings.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I set up the enviroment settings for this circuit. If this settings file is being inherited, then you can use VARIABLE to override
		a value set in a parent circuit or FBX_PARAM to accept a value set by a parent circuit
	</responsibilities>	
	<properties>
		<history author="Rich Tretola" email="rich@lassofusebox.org" date="10/07/2002" type="Create" />
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/5/2012" email="tami@asktami.com" type="Update" />
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
			<string name="siteMap" scope="variables" />
			<string name="readCon" scope="variables" />
			<string name="writeCon" scope="variables" />
			<string name="appLocation" scope="variables" />
			<string name="XFA_home" scope="variables" />
			<string name="hitcount" scope="variables" />
		</out>
	</io>
</fusedoc>
*/


// other required vars (do not remove)

FBX_Param(-Name='XFA_home', -Default= $self + 'ContactApp.list_Contacts');
FBX_Param(-Name='hitcount', -Default=0);


var('siteMap' = Map,
'valErrorLabel' =  (map),		// valErrorLabel used by val_contactForm.inc to highlight form labels
);

If($appLocation == 'lassofusebox');
// live site (default)

	// database, username & password
	$siteMap->Insert('db' = 'LFB_database2');
	$siteMap->Insert('dbusername' = 'LFB_lassofusebox');
	$siteMap->Insert('dbpassword' = 'xobesufossal');
	 
	 
else($appLocation == 'asktami' );
// test site
	 
	// database, username & password
	$siteMap->Insert('db' = 'asktami');
	$siteMap->Insert('dbusername' = 'tamiw7');
	$siteMap->Insert('dbpassword' = 'jt9haw5');
	 
else;
// local hard drive
	 
	// database, username & password
	$siteMap->Insert('db' = 'asktami');
	$siteMap->Insert('dbusername' = 'root');
	$siteMap->Insert('dbpassword' = 'admin');

/if;


$siteMap->Insert('FileUsername'='fusn');			// Username for file permissions outside root
$siteMap->Insert('FilePassword'='fpwd');			// Password for file permissions outside root



local('temp' = '');
iterate($siteMap, #temp );
var( #temp->first = @($siteMap->Find(#temp->first)) );
/iterate;


/*
----------------------------------------------------------------------------
DATABASE connections
----------------------------------------------------------------------------

-Host=(Array(-Datasource='MySQLDS', -Name='localhost', -Username='root', -Password='admin')),  // MySQL (or FileMaker database) username and password
Datasource is either MySQLDS or filemakerds
-Name is the name you entered for that datasource in lasso9/Admin/ host name
-Username is the MySQL username OR the FileMaker database Username
-Password is the MySQL password OR the FileMaker database Password

MySQL usernames and passwords are defined with GRANT syntax
FileMaker usernames and passwords are defined via File->Manage->Security

ALTERNATE method, will use the one username and password defined in lasso9/Admin for ALL MySQL or FileMaker database connections; in Lasso8/LassoAdmin you can specify DIFFERENT usernames/passwords for different MySQL/FileMaker database connections but in Lasso9/Admin you can only specify 1 username/password for each Host

I would use this Alternate method for Lasso 8

var('readCon' = array(
	-username = $dbusername,
	-password = $dbpassword,
	-database = $db,
    -maxRecords = 'all') );

var('writeCon' = array(
	-username = $dbusername,
	-password = $dbpassword,
	-database = $db,
    -maxRecords = 'all') );
    

You can override the settings in individual inlines like this(
	-inline(
	$readCon,
	-table=$myTable,
	-maxRecords = '10',
	-search)
	);
*/


// Table Names
var(
'tP' = 'People'			// where the variable $tP is used in place of the actual table name 'People'
);


// Use this method for Lasso 9 ONLY if you need to specify a DIFFERENT username/password that what is assigned in the Lasso9/Admin for that host

// read Connection
var('readCon' = Array(-Datasource='MySQLDS', -Name='localhost', -Username=$dbusername, -Password=$dbpassword));
$readCon->insert(-database=$db);
$readCon->insert(-maxrecords='all');


// write Connection
var('writeCon' = Array(-Datasource='MySQLDS', -Name='localhost', -Username=$dbusername, -Password=$dbpassword));
$writeCon->insert(-database=$db);

]