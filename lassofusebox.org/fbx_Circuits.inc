[
/*
<fusedoc fuse="FBX_Circuits.cfm">
	<responsibilities>
		I define the Circuits structure used with Fusebox 3.0
	</responsibilities>	
	<io>
		<out>
			<string name="fusebox.circuits.*" comments="set a variable for each circuit name" />
		</out>
	</io>
</fusedoc>
*/

// $_Circuits->Insert('ALIAS NAME'='REAL NAME');


$_Circuits->(Insert:'home'='LassoFusebox');
$_Circuits->(Insert:'resources'='LassoFusebox/Resources');
$_Circuits->(Insert:'downloads'='LassoFusebox/Downloads');
$_Circuits->(Insert:'login'='LassoFusebox/Login');
$_Circuits->(Insert:'faq'='LassoFusebox/FAQ');

]