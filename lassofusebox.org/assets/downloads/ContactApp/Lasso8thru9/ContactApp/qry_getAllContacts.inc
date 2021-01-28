[
/*
<fusedoc fuse="qry_getAllContacts.lasso" language="Lasso" specification="3.0">
<responsibilities>I get the all current contacts in the contacts table.</responsibilities>
<properties>
 <history author="Rich Tretola" date="10/07/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
 <history author="Tami Williams" date="5/1/2008" email="tami@asktami.com" type="Update" />
 <history author="Tami Williams" date="4/5/2012" email="tami@asktami.com" type="Update" />
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
*/

Inline(
	$readCon,
	-InlineName='getAllContacts',
	-Table=$tP,
	-FindAll);
	
	include($debuginline);
	
/Inline;

]