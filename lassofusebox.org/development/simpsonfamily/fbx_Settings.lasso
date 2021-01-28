[Lasso_Comment]
<fusedoc fuse="FBX_Settings.lasso">
	<responsibilities>
		I set up the enviroment settings for this circuit. If this settings file is being inherited, then you can use CFSET to override
		a value set in a parent circuit or FBX_PARAM to accept a value set by a parent circuit
	</responsibilities>	
	<properties>
		<history author="Rich Tretola" email="rich@lassofusebox.org" date="02/11/2003" type="create">
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

[FBX_Param: -Name='fuseaction', -Default='simpsonfamily.main']
[var:'myCircuit'=$fusebox->(Find:'circuit')]


