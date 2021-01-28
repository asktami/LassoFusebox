[
/*
<fusedoc fuse="fbx_Sessions.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I define any sessions needed within the application. There should be only one fbx_Sessions.inc file within the application and it should reside within the root folder.
	</responsibilities>	
   <properties>
	   <history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Update">
		 -------------------------------------------------------------------------------------------
		 From www.listsearch.com/ ID= 105874  
		 If action params are set to variables before [session_start] on the page then any existing session variable will overwrite user-injected variables. Action_Params/Client_PostArgs are set to variables inside the fusebox file prior to starting the session.
		 -------------------------------------------------------------------------------------------
	   </history>
	   <history author="Tami Williams" date="06/13/2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/28/2012" email="tami@asktami.com" type="Update" />
   </properties>
   <io>
		<out>
			<string name="sessionName" scope="variables" />
			<string name="gServerName" scope="variables" />
			<string name="someVar" scope="variables" />
		</out>
	</io>
</fusedoc>
*/

//		the session cookie expires in 15 minutes or whenever the user clicks the log out link

var(
'sessionName' = 'fbxCore',
'sessionTimeout' = 15		// Minutes
); 


//  I had problems if logout is done any other way - I think b/c cookies are not retrievable on the same page they are set

if($fuseaction >> 'logoutA');
// end the session immediately
// delete the session cookie too					 

Session_Start(-Name=$sessionName, -Expires=$sessionTimeout, -useAuto);
				   Cookie_Set(  
				   	'_SessionTracker_' + $sessionName = (Session_ID(-Name = $sessionName)),
					  -Path='/',
					  -Expires = -10);

					 Session_End(-Name=$sessionName);		
	
else;

// start a new session or load the exisiting session

	  if(lp_client_isbot == false);
						 Session_Start(-Name=$sessionName, -Expires=$sessionTimeout, -useAuto);
						 
						 // if sitting on any post-login page (use $circuit to figure that out but circuit isn't defined yet so use fuseaction) and the session timesout, when the user clicks on a link take them to the You Have Been Logged Out page
						 // don't trigger this loop if session timedout b/c just did the login, ie. start.login
						 // OR if on a pre-login page, ie. start.login_form
						
						 if(Session_Result == 'expire'  && $fuseaction !>> 'start');
								  // go immediately to the "you have been logged out" page
								  redirect_url('site.lasso?fuseaction=home.logoutA');
						 /if;   				 
						 
						 session_addvar(-name=$sessionName, 'someVar');				// some variable
						 session_addvar(-name=$sessionName, 'gServerName');
						 session_addvar(-name=$sessionName, 'lid');
				
	  /if;
/if;

]