[
/*
<fusedoc fuse="qry_deleteContact.lasso" language="Lasso" specification="3.0">
	<responsibilities>I delete the contact from the contacts table..</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/11/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
		<history author="Tami Williams" date="5/1/2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/5/2012" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<in>
			<number name="ID" format="LDML" Scope="attributes" />
		</in>
	</io>
</fusedoc>
*/


Inline(
	$writeCon,
    -Table=$tP,
    -keyField = 'ID',
    -KeyValue= $ID,
	-Delete);
    
    include($debuginline);
 
/Inline;

]