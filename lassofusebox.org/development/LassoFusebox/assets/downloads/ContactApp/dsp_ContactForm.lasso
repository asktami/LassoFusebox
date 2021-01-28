[Lasso_Comment]
<fusedoc fuse="dsp_ContactForm.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the contact edit form.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/07/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<in>
			<String name="XFA_submit" format="LDML" Scope="variables"/>
			<number name="getContact.ID" format="LDML" Scope="variables"/>
			<String name="getContact.First_Name" format="LDML" Scope="variables"/>
			<String name="getContact.Last_Name" format="LDML" Scope="variables"/>
			<String name="getContact.Company" format="LDML" Scope="variables"/>
			<String name="getContact.Phone_Number" format="LDML" Scope="variables"/>
			<String name="getContact.Title" format="LDML" Scope="variables"/>
			<String name="getContact.Sex" format="LDML" Scope="variables"/>
			<String name="getContact.Jobs" format="LDML" Scope="variables"/>
		</in>
		<out>
			<number name="ID" format="LDML" Scope="formOrUrl"/>
			<String name="First_Name" format="LDML" Scope="formOrUrl"/>
			<String name="Last_Name" format="LDML" Scope="formOrUrl"/>
			<String name="Company" format="LDML" Scope="formOrUrl"/>
			<String name="Phone_Number" format="LDML" Scope="formOrUrl"/>
			<String name="Title" format="LDML" Scope="formOrUrl"/>
			<String name="Sex" format="LDML" Scope="formOrUrl"/>
			<String name="Jobs" format="LDML" Scope="formOrUrl"/>
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]



<form name="people" action="[$self]?fuseaction=[$XFA_submit]" method="post">
<table align="center">
	<input type="hidden" name="ID" value="[$getContact.ID]">
	<tr>
		<td class="boldcopy">Title:</td>
		<td><input type="text" name="Title" size="40" value="[$getContact.Title]"></td>
	</tr>
	<tr>
		<td class="boldcopy">First Name:</td>
		<td><input type="text" name="First_Name" size="40" value="[$getContact.First_Name]"></td>
	</tr>
	<tr>
		<td class="boldcopy">Last Name:</td>
		<td><input type="text" name="Last_Name" size="40" value="[$getContact.Last_Name]"></td>
	</tr>	
	<tr>
		<td class="boldcopy">Company:</td>
		<td><input type="text" name="Company" size="40" value="[$getContact.Company]"></td>
	</tr>
	<tr>
		<td class="boldcopy">Phone Number:</td>
		<td><input type="text" name="Phone_Number" size="40" value="[$getContact.Phone_Number]"></td>
	</tr>
	<tr>
		<td class="boldcopy">Sex:</td>
		<td><select name="Sex">
			<option value="Male" [IF: ($getContact.Sex) == 'Male']selected[/IF]>Male</option>
			<option value="Female"[IF: ($getContact.Sex) == 'Female']selected[/IF]>Female</option>
		    </select></td>
	</tr>
	<tr>
		<td class="boldcopy">Jobs:</td>
		<td><input type="text" name="Jobs" size="60" value="[$getContact.Jobs]"></td>
	</tr>
	<tr>
		<td>&nbsp;</td>
		<td><input type="submit" value="Submit"></td>
	</tr>
</table>
</form>  
