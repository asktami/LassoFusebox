[Lasso_Comment]
<fusedoc fuse="dsp_AllContacts.lasso" language="Lasso" specification="3.0">
	<responsibilities>I display all current contacts.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/10/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<in>
			<recordset name="qry_getAllContacts" format="LDML" Scope="variables">
				<number name="ID" format="LDML" Scope="variables"/>
				<String name="First_Name" format="LDML" Scope="variables"/>
				<String name="Last_Name" format="LDML" Scope="variables"/>
				<String name="Company" format="LDML" Scope="variables"/>
				<String name="Phone_Number" format="LDML" Scope="variables"/>
				<String name="Title" format="LDML" Scope="variables"/>
				<String name="Sex" format="LDML" Scope="variables"/>
				<String name="Jobs" format="LDML" Scope="variables"/>
		    </recordset>
			<String name="XFA_editContact" format="LDML" Scope="variables"/>
			<String name="XFA_deleteContact" format="LDML" Scope="variables"/>
			<String name="XFA_newContact" format="LDML" Scope="variables"/>
		</in>
		<out>
			<number name="ID" format="LDML" Scope="formOrUrl"/>
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]


<table width="100%" cellspacing="0" cellpadding="0">
	<tr bgcolor="#c0c0c0">
		<td class="boldcopy">ID</td>
		<td class="boldcopy">First Name</td>
		<td class="boldcopy">Last Name</td>
		<td class="boldcopy">Company</td>
		<td class="boldcopy">Edit</td>
		<td class="boldcopy">Delete</td>
	</tr>
	
	[Var: 'bgcolor' = "#F0F0F0"]
  	[Records: -InLineName='getAllContacts']
  	<tr bgcolor="[$bgcolor]">
    	<td class="bodycopy">[Field: 'ID']</td> 
		<td class="bodycopy">[Field: 'First_Name']</td> 
		<td class="bodycopy">[Field: 'Last_Name']</td> 
		<td class="bodycopy">[Field: 'Company']</td> 
		<td class="bodycopy"><a href="[$self]?fuseaction=[$XFA_editContact]&ID=[Field: 'ID']">Edit</a></td> 
		<td class="bodycopy"><a href="[$self]?fuseaction=[$XFA_deleteContact]&ID=[Field: 'ID']">Delete</a></td> 
 	</tr>
	[IF: ($bgcolor) == "#F0F0F0"]
		 [Var: 'bgcolor' = "#FFFFFF"]
	[ELSE]
		 [Var: 'bgcolor' = "#F0F0F0"]
	[/IF]
 	[/Records]
	<tr>
		<td colspan="6" align="center" class="bodycopy">
		<br>
		<a href="[$self]?fuseaction=[$XFA_newContact]">Add a New User</a></td>
	</tr>
 </table>