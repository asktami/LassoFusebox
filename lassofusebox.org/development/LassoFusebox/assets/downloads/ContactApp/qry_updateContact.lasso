[Lasso_Comment]
<fusedoc fuse="qry_updateContact.lasso" language="Lasso" specification="3.0">
	<responsibilities>I update the person table.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/11/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<in>
			<number name="ID" format="LDML" Scope="attributes"/>
			<String name="Title" format="LDML" Scope="attributes"/>
			<String name="First_Name" format="LDML" Scope="attributes"/>
			<String name="Last_Name" format="LDML" Scope="attributes"/>
			<String name="Company" format="LDML" Scope="attributes"/>
			<String name="Phone_Number" format="LDML" Scope="attributes"/>
			<String name="Sex" format="LDML" Scope="attributes"/>
			<String name="Jobs" format="LDML" Scope="attributes"/>
		</in>
	</io>
</fusedoc>
[/Lasso_Comment]

Title: [Output: $Title]

[Inline: -Update,
    -Database=($datasource),
	-Username=($dbusername),
	-Password=($dbpassword),
    -Table='People',
    -KeyField='ID',
    -KeyValue=($ID),
	'Title'=($Title),
    'First_Name'=($First_Name),
	'Last_Name'=($Last_Name),
	'Company'=($Company),
	'Phone_Number'=($Phone_Number),
	'Sex'= ($Sex),
	'Jobs'=($Jobs)]
[/Inline]