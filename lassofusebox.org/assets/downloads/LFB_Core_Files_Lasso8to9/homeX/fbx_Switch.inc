[
/*
<fusedoc fuse="fbx_Switch.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I am the Select statement that handles the fuseaction, delegating work to various fuses.
	</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/10/2002" email="rich@lassofusebox.org" type="create"></history>
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/28/2012" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<in>
			<structure name="fusebox">
				<string name="fuseaction" />
				<string name="circuit" />	
			</structure>
		</in>
	</io>	
</fusedoc>
*/


select($fuseaction);

case('defaultfuseaction');
// 	This will be the value returned if someone types in "circuitname." or "circuitname", omitting the actual fuseaction request
		redirect_url($self + 'home.welcome');
		
case('welcome');
		$pgtitle = 'Cookies and Javascript Needed' ;
		FBX_Include('dsp_welcome.inc');


case('cookietest');
		$pgtitle = 'Cookies and Javascript Needed' ;
		FBX_Include('dsp_cookietest.inc');
		

case('baduser');
$pgTitle = 'Invalid Access';
'<p>&nbsp;</p>
<p>&nbsp;</p>
Please do not edit the URL, use the Back button or use your browser History!
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>';

case(($fuseaction == 'login_form') || ($fuseaction == 'login') );

			if($fuseaction == 'login');
				  	 FBX_Include('val_loginform.inc');
					  if($isValid == 'Yes');
							  FBX_Include('qry_login.inc');
							   if(var('lid'));
								  Redirect_URL($XFA_secure);
							  /if;
					  /if;
			/if;
			
			FBX_Include('dsp_welcome.inc' );
		
		
case('logoutA' );
		redirect_url($self + 'home.logoutB' );
		
case('logoutB' );
		redirect_url($self + 'home.logout' );
			
case('logout' );
			FBX_Include('dsp_logout.inc' );		


case('login_Error');
// display the "you need to re-login" page
//	 this prevents users from coming back to a bookmarked page that requires login
			FBX_Include('dsp_loginError.inc');
		

case;
// unknown fuseaction
		FBX_IncludeCommon('dsp_unknownfuseaction.inc');

/select;
 
 ]