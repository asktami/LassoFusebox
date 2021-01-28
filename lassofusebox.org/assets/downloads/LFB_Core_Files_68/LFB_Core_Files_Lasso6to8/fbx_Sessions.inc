<?LassoScript
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
   </properties>
</fusedoc>
*/


var: 'sessionName' = 'fbxCore';
					 
if: $fuseaction >> 'logoutA';
// IF you have a login section, then you need to allow logouts
// end the session immediately
// delete the session cookies too					 
				   Cookie_Set:
				   		$sessionName=Session_ID: -Name = '_SessionTracker_' + $sessionName,
				   		-Path='/',
				   		-Expires = -10;

					 Session_End: -Name=$sessionName;		
	
else;
// start a new session or load the exisiting session

						   Session_Start: -Name=$sessionName, -Expires=15, -useAuto;
						   // the session cookie expires in 15 minutes or whenever the user clicks the log out link
						   
						   if: Session_Result == 'expire';
								 // go immediately to the "you have been logged out" page
								 redirect_url: 'site.lasso?fuseaction=home.logoutA' ;
					  		/if;
						   
						   session_addvar: -name=$sessionName, 'someVar';				// some variable
							
/if;
?>