[Lasso_Comment]
<fusedoc fuse="FBX_Settings.lasso">
	<responsibilities>
		I set up the enviroment settings for this circuit. If this settings file is being inherited, then you can use CFSET to override
		a value set in a parent circuit or CFPARAM to accept a value set by a parent circuit
	</responsibilities>	
	<properties>
		<history author="r" email="" date="" type="create">
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
[FBX_Param: -Name='mailHost', -Default='mail.pointinspace.com']
[FBX_Param: -Name='emailAddress', -Default='rich@lassofusebox.org']
[FBX_Param: -Name='variables.self', -Default='index.lasso']
[FBX_Param: -Name='self', -Default='index.lasso']
[FBX_Param: -Name='fuseaction', -Default='home.welcome']

[Lasso_Comment]<p>I am the <strong>Home</strong> fbx_Settings.lasso file</p>
<p>The DEFAULT fuseaction is: [$fuseaction]</p>[/Lasso_Comment]

