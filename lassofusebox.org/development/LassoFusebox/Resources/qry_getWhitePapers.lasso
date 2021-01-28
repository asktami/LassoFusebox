[Lasso_Comment]
<fusedoc fuse="qry_getWhitepapers.lasso" language="Lasso" specification="3.0">
	<responsibilities>I get all the downloads of type "White Paper" from the downloads table.</responsibilities>
	<properties>
		<history author="Michael McKellip" date="01/31/2003" email="michael@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<out>
			<recordset name="getWhitePapers" format="LDML" Scope="variables">
				<number name="ID" format="LDML" Scope="variables"/>
				<String name="Type" format="LDML" Scope="variables"/>
				<String name="Name" format="LDML" Scope="variables"/>
				<String name="Description" format="LDML" Scope="variables"/>
				<String name="Filename" format="LDML" Scope="variables"/>
				<String name="Folder" format="LDML" Scope="variables"/>
				<String name="Author" format="LDML" Scope="variables"/>
				<String name="Email" format="LDML" Scope="variables"/>
		    </recordset>
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]

[Inline: -Search,
    -Datasource=($datasource),
	-Username=($FBX_username),
	-Password=($FBX_password),
    -Table='Downloads',
    'Type'='White Paper',
	-InlineName='getWhitePapers']
	
	[FBX_Param: -Name='getWhitePapers.Found_Count', -Default=(Found_Count)]
	
[/Inline]