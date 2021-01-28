[
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
		</out>
	</io>
</fusedoc>
*/


// other required vars (do not remove)

// FMP timestamp format (%D %r) looks like this: 09/02/2006 03:33:25 PM
// MySQL datetime & timestamp format (%Q %T) looks like: 2006-09-02 15:33:25
Date_SetFormat: -Format='%Q %T';


// -------------------------------------------------------------------------------------------
//	SITEWIDE NAVIGATION - PRE AND POST LOGIN
// -------------------------------------------------------------------------------------------

// Examples:

FBX_Param(-Name='XFA_cookietest', -Default=$self + 'home.cookietest' );		// used to check if cookies and javascript are turned on
FBX_Param(-Name='XFA_logout', -Default= $self + 'home.logoutA' );				// used for Logout button
FBX_Param(-Name='XFA_welcome', -Default= $self + 'home.welcome' );			// home page
FBX_Param(-Name='XFA_secure', -Default= $self + 'secure.welcome' );			// post-login circuit


/*
-------------------------------------------------------------------------------------------
TO OVERRIDE A SESSION VAR
-------------------------------------------------------------------------------------------
IF sometimes "someVariable" comes from URL and then its stored in a session variable do the following
(if this was not here then the session variable would ALWAYS override the URL variable)
-------------------------------------------------------------------------------------------

if(action_param('someVariable') != '' );
	var('someVariable' = encode_sql(action_param('someVariable') ));
/if;

*/



var('siteMap' = Map);

If($appLocation == 'lassofusebox');
// live site (default)

	// database, username & password
	$siteMap->Insert('db' = 'thisDB');
	$siteMap->Insert('dbusername' = 'thisDbusn');
	$siteMap->Insert('dbpassword' = 'thisDbpwd');
	 
	 
else($appLocation == 'asktami' );
// test site
	 
	// database, username & password
	$siteMap->Insert('db' = 'asktami');
	$siteMap->Insert('dbusername' = 'asktamiUN');
	$siteMap->Insert('dbpassword' = 'asktamiPW');
	 
else;
// local hard drive
	 
	// database, username & password
	$siteMap->Insert('db' = 'otherDb');
	$siteMap->Insert('dbusername' = 'otherUN');
	$siteMap->Insert('dbpassword' = 'otherPW');

/if;


$siteMap->Insert('FileUsername'='YOUR FILE USERNAME');				// Username for file permissions outside root
$siteMap->Insert('FilePassword'='YOUR FILE PASSWORD');				// Password for file permissions outside root


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