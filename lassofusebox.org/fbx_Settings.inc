[Lasso_Comment]
<fusedoc fuse="FBX_Settings.inc">
	<responsibilities>
		I set up the enviroment settings for this circuit. If this settings file is being inherited, then you can use CFSET to override
		a value set in a parent circuit or CFPARAM to accept a value set by a parent circuit
	</responsibilities>	
	<properties>
		<history author="Michael McKellip" email="mmckellip@lassofusebox.org" date="1/5/2003" type="create">
	</properties>
	<io>
		<in>
			<structure name="fusebox">
				<boolean name="isHomeCircuit" comments="Is the circuit currently executing the home circuit?" />
			</structure>
		</in>
		<out>
			<string name="self" scope="variables" />
			<string name="fuseaction" scope="variables" />
			<string name="datasource" scope="variables" />
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]

[FBX_Param: -Name='fuseaction', -Default='home.welcome']
[FBX_Param: -Name='self', -Default='index.lasso?fuseaction=']
[FBX_Param: -Name='datasource', -Default='LFB_database1']
[FBX_Param: -Name='EmailHost', -Default='mail.pointinspace.com']
[FBX_Param: -Name='EmailAddress', -Default='tami@asktami.com']
[FBX_Param: -Name='AltEmailAddress', -Default='rich@lassofusebox.org']
[FBX_Param: -Name='BCCEmailAddress', -Default='michael@lassofusebox.org']
[FBX_Param: -Name='FBX_username', -Default='LFB_lassofusebox']
[FBX_Param: -Name='FBX_password', -Default='fuse1972xob']


<!--  fuse1972xob -->