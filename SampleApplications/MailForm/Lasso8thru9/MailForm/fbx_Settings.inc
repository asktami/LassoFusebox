[
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
	   <history author="Tami Williams" date="4/20/2012" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<in>
			<structure name="fusebox">
				<boolean name="isRootCircuit" comments="Is the circuit currently executing the root circuit?" />
			</structure>
		</in>
		<out>
			<string name="FileUsername" scope="variables" />
			<string name="FilePassword" scope="variables" />
		</out>
	</io>
</fusedoc>
*/

// Username for file permissions outside root
FBX_Param(-Name='FileUsername', -Default='fusn');

// Password for file permissions outside root
FBX_Param(-Name='FilePassword', -Default='fpwd');


]