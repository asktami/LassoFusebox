[
/*
<fusedoc fuse="fbx_Circuits.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I define the Circuits structure used with Fusebox 3.0
	</responsibilities>	
	<properties>
		<history author="???" date="???" email="???" type="Create" />
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update">
		  there MUST be 1 line that holds the circuitname and aliasname for the root directory of this application
		  
		  NO SPACES are allowed in circuit names or aliasnames
		  
		  the root directory is the folder in the root directory of your webserver that contains this application
		  
		  the folder this file sits in can have a name that is different from the root directory aliasname in the circuit definition
		  
		  the most IMPORTANT thing is that whatever is defined as the ROOT directory aliasname for this application
		  is also what's used as the first parameter for subdirectories in this folder in your circuit definitions;
		  the root directory aliasname does not have to be defined on the first line but it MUST be defined
		  
		  text on the left side of the equal sign is the circuitname, text on the right side of the equal sign is the folder's REAL name,
		  EXCEPT on the right side of the equal sign the root directory name must be the same as the root directory aliasname
		  
		  HERE'S THE LOGIC:
		  a) pretend this fbx_Circuits.inc file is in a folder called "testFusebox" sitting in the root directory of your webserver
		  and
		  b) testFusebox/home and testFusebox/childx are real subfolders
		  
		  WORKS:
		  // root directory
		  $_Circuits->Insert('rootCircuitname' = 'testFusebox');
		  
		  // subdirectories (folders inside the root directory)
		  $_Circuits->Insert('homeCircuitname' = 'testFusebox/home');
		  $_Circuits->Insert('childxCircuitname' = 'testFusebox/childx');
		  
		  "fuseaction=childxCircuitname.child" takes you to the folder testFusebox/childx/
		  then looks at testFusebox/childx/fbx_Switch.inc
		  
		  THIS WORKS TOO:
		  // root directory
		  $_Circuits->Insert('home' = 'root/home');
		  
		  // subdirectories (folders inside the root directory)
		  $_Circuits->Insert('people' = 'root/childx');
		  $_Circuits->Insert('children' = 'root/childx');
		  $_Circuits->Insert('rootdir' = 'root');
		  
		  "fuseaction=people.child" AND fuseaction=children.child" take you to the folder testFusebox/childx/
		  then looks at testFusebox/childx/fbx_Switch.inc
		  
		  
		  AND SO DOES THIS:
		  // root directory
		  $_Circuits->Insert('xxx' = 'xxx');
		  
		  // subdirectories (folders inside the root directory)
		  $_Circuits->Insert('home' = 'xxx/home');
		  $_Circuits->Insert('child1' = 'xxx/childx');
		  
		  "fuseaction=child1.child" takes you to the folder testFusebox/childx/
		  then looks at testFusebox/childx/fbx_Switch.inc
		  
		  
		  DOES NOT WORK:
		  // no root directory circuit set
		  $_Circuits->Insert('home' = 'xxx/home');
		  
		  DOES NOT WORK:
		  // does not work because root directory aliasname is "home" not "rootdir" and so
		  "xxx" needs to replace "rootdir" on the right side of the equals sign in the first line
		  $_Circuits->Insert('home' = 'rootdir/home');
		  $_Circuits->Insert('xxx' = 'home');
		  
		  DOES NOT WORK:
		  // does not work because root directory is "xxx" not "ZZZ" and so
		  "xxx" needs to replace "ZZZ" on the right side of the equals sign in the first line
		  $_Circuits->Insert('home' = 'ZZZ/home');
		  $_Circuits->Insert('rootdir' = 'xxx');
		  
		  -------------------------------------------------------------------------------------------
		  // here is the template circuit definition for the Fusebox core
		  // If "xxx" is my alias for the real name of the folder that this file is in
		  // $_Circuits->Insert('home'='xxx') would work
		  // $_Circuits->Insert('home'='LFB_Core_Files') also works (it uses real name of of folder this file is in)
		  // NOTE: bad circuit names use the RootCircuit's switch file to call the "unknown fuseaction'
		</history>
		<history author="Tami Williams" date="4/22/2012" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<out>
			<string name="fusebox.circuits.*" comments="set a variable for each circuit name" />
		</out>
	</io>
</fusedoc>
*/

// $_Circuits->Insert('ALIAS NAME'='REAL NAME');


$_Circuits->Insert('LFBCore'='LFB_Core_Files_v89');
$_Circuits->Insert('home'='LFB_Core_Files_v89/homeX');
$_Circuits->Insert('popups'='LFB_Core_Files_v89/popups');
$_Circuits->Insert('secure'='LFB_Core_Files_v89/secure');


]