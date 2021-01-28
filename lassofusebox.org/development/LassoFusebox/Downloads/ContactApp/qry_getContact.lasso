[Lasso_Comment]
<fusedoc fuse="qry_getContact.lasso" language="Lasso" specification="3.0">
	<responsibilities>I get the current people in the contacts table.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<in>
			<number name="ID" format="LDML" Scope="attributes"/>
		</in>
		<out>
			<recordset name="getContact" format="LDML" Scope="variables">
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

[FBX_Param: -Name='ID', -Default='-1']

[Inline: -Search,
    -Database=($datasource),
	-Username=($dbusername),
	-Password=($dbpassword),
    -Table='People',
    -KeyField='ID',
    'ID'= ($ID),
	-InlineName='getContact']
	
	[FBX_Param: -Name='getContact.ID', -Default=(Field:'ID')]
	[FBX_Param: -Name='getContact.Title', -Default=(Field:'Title')]
	[FBX_Param: -Name='getContact.First_Name', -Default=(Field:'First_Name')]
	[FBX_Param: -Name='getContact.Last_Name', -Default=(Field:'Last_Name')]
	[FBX_Param: -Name='getContact.Company', -Default=(Field:'Company')]
	[FBX_Param: -Name='getContact.Phone_Number', -Default=(Field:'Phone_Number')]
	[FBX_Param: -Name='getContact.Sex', -Default=(Field:'Sex')]
	[FBX_Param: -Name='getContact.Jobs', -Default=(Field:'Jobs')]
	
[/Inline]
