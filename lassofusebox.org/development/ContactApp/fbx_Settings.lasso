[Lasso_Comment]
<fusedoc fuse="FBX_Settings.lasso">
	<responsibilities>
		I set up the enviroment settings for this circuit. If this settings file is being inherited, then you can use CFSET to override
		a value set in a parent circuit or FBX_PARAM to accept a value set by a parent circuit
	</responsibilities>	
	<properties>
		<history author="Rich Tretola" email="rich@lassofusebox.org" date="10/07/2002" type="create">
	</properties>
	<io>
		<in>
			<structure name="fusebox">
				<boolean name="isHomeCircuit" comments="Is the circuit currently executing the home circuit?" />
			</structure>
		</in>
		<out>
			<string name="self" scope="variables" />
			<string name="self" scope="request" />
			<string name="fusebox.layoutDir" />
			<string name="fusebox.layoutFile" />
			<boolean name="fusebox.suppressErrors" />
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]

[FBX_Param: -Name='fuseaction', -Default='ContactApp.listContacts']
[FBX_Param: -Name='self', -Default='index.lasso']
[FBX_Param: -Name='dbusername', -Default='LFB_lassofusebox']
[FBX_Param: -Name='dbpassword', -Default='xobesufossal']
[FBX_Param: -Name='datasource', -Default='LFB_Database2']
[$fusebox->(Insert:'suppressErrors'=false)]


