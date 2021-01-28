[Lasso_Comment]
<fusedoc fuse="qry_deleteContact.lasso" language="Lasso" specification="3.0">
	<responsibilities>I delete the contact from the contacts table..</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/11/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<in>
			<number name="ID" format="LDML" Scope="attributes"/>
		</in>
	</io>
</fusedoc>
[/Lasso_Comment]

[Inline: -Delete,
    -Database=($datasource),
	-Username=($dbusername),
	-Password=($dbpassword),
    -Table='People',
    -KeyField='ID',
    -KeyValue=($ID)]
[/Inline]