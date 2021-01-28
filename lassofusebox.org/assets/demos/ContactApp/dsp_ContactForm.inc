[Output_None]
<fusedoc fuse="dsp_ContactForm.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the contact edit form.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/07/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
		<history author="Tami Williams" date="5/1/2008" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<in>
			<String name="XFA_submit" format="LDML" Scope="variables"/>
			<number name="ID" format="LDML" Scope="variables"/>
			<String name="First_Name" format="LDML" Scope="variables"/>
			<String name="Last_Name" format="LDML" Scope="variables"/>
			<String name="Company" format="LDML" Scope="variables"/>
			<String name="Phone_Number" format="LDML" Scope="variables"/>
			<String name="Title" format="LDML" Scope="variables"/>
			<String name="Sex" format="LDML" Scope="variables"/>
			<String name="Jobs" format="LDML" Scope="variables"/>
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
[/Output_None]



<form name="people" action="[$XFA_submit]" method="post">
<table align="center">
	<input type="hidden" name="ID" value="[var:'ID']">
	<tr>
		<td class="boldcopy">Title:</td>
		<td>
		<select name="Title">
			<option value="Mr."[If:(var:'Title')=='Mr.'] SELECTED[/If]>Mr.</option>
			<option value="Mrs."[If:(var:'Title')=='Mrs.'] SELECTED[/If]>Mrs.</option>
			<option value="Ms."[If:(var:'Title')=='Ms.'] SELECTED[/If]>Ms.</option>
			<option value="Dr."[If:(var:'Title')=='Dr.'] SELECTED[/If]>Dr.</option>
		</select>
		</td>
	</tr>
	<tr>
		<td class="boldcopy">[if:($valErrorLabel)->(Find:'First_Name')]<span class="red">First Name:</span>[else]First Name:[/if]</td>
		<td><input type="text" name="First_Name" size="40" value="[var:'First_Name']"></td>
	</tr>
	<tr>
		<td class="boldcopy">[if:($valErrorLabel)->(Find:'Last_Name')]<span class="red">Last Name:</span>[else]Last Name:[/if]</td>
		<td><input type="text" name="Last_Name" size="40" value="[var:'Last_Name']"></td>
	</tr>	
	<tr>
		<td class="boldcopy">[if:($valErrorLabel)->(Find:'Company')]<span class="red">Company:</span>[else]Company:[/if]</td>
		<td><input type="text" name="Company" size="40" value="[var:'Company']"></td>
	</tr>
	<tr>
		<td class="boldcopy">[if:($valErrorLabel)->(Find:'Phone_Number')]<span class="red">Phone Number:</span>[else]Phone Number:[/if]</td>
		<td><input type="text" name="Phone_Number" size="40" value="[var:'Phone_Number']"></td>
	</tr>
	<tr>
		<td class="boldcopy">Sex:</td>
		<td><select name="Sex">
			<option value="Male" [IF: (var:'Sex') == 'Male']selected[/IF]>Male</option>
			<option value="Female"[IF: (var:'Sex') == 'Female']selected[/IF]>Female</option></td>
	</tr>
	<tr>
		<td class="boldcopy">[if:($valErrorLabel)->(Find:'Jobs')]<span class="red">Jobs:</span>[else]Jobs:[/if]</td>
		<td><input type="text" name="Jobs" size="60" value="[var:'Jobs']"></td>
	</tr>
	<tr>
		<td>&nbsp;</td>
		<td><input type="submit" value="Submit"></td>
	</tr>
</table>
</form>  
