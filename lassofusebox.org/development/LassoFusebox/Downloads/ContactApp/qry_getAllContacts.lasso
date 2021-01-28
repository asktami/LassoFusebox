[Lasso_Comment]
<fusedoc fuse="qry_getAllContacts.lasso" language="Lasso" specification="3.0">
	<responsibilities>I get the all current contacts in the contacts table.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/07/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<out>
			<recordset name="getAllContacts" format="LDML" Scope="variables">
				<number name="ID" format="LDML" Scope="variables"/>
				<String name="First_Name" format="LDML" Scope="variables"/>
				<String name="Last_Name" format="LDML" Scope="variables"/>
				<String name="Company" format="LDML" Scope="variables"/>
				<String name="Phone_Number" format="LDML" Scope="variables"/>
				<String name="Title" format="LDML" Scope="variables"/>
				<String name="Sex" format="LDML" Scope="variables"/>
				<String name="Jobs" format="LDML" Scope="variables"/>
		    </recordset>
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]

[Inline: -FindAll,
    -Database=($datasource),
	-Username=($dbusername),
	-Password=($dbpassword),
    -Table='People',
    -KeyField='ID',
	-InlineName='getAllContacts']
[/Inline]