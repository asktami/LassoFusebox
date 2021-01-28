[
/*
<fusedoc fuse="qry_getContact.lasso" language="Lasso" specification="3.0">
	<responsibilities>I get the current people in the contacts table.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="" email="rich@lassofusebox.org" role="Architect" type="Create"/>
		<history author="Tami Williams" date="5/1/2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/5/2012" email="tami@asktami.com" type="Update" />
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
*/


Inline(
	$readCon,
	-InlineName='getContact',
    -Table=$tP,
    'ID'= $ID,
	-Search);
	
	FBX_Param(-Name='ID', -Default=Field('ID'));
	FBX_Param(-Name='Title', -Default=Field('Title'));
	FBX_Param(-Name='First_Name', -Default=Field('First_Name'));
	FBX_Param(-Name='Last_Name', -Default=Field('Last_Name'));
	FBX_Param(-Name='Company', -Default=Field('Company'));
	FBX_Param(-Name='Phone_Number', -Default=Field('Phone_Number'));
	FBX_Param(-Name='Sex', -Default=Field('Sex'));
	FBX_Param(-Name='Jobs', -Default=Field('Jobs'));
	
	include($debuginline);
	
/Inline;

]