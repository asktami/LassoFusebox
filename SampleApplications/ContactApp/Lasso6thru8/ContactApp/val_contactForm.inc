<?LassoScript
/*
<fusedoc fuse="val_contactForm.inc" language="Lasso" specification="3.0">
	<responsibilities>I validate the form.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/07/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<in>
			<Number name="ID" format="LDML" Scope="attributes"/>
			<String name="Title" format="LDML" Scope="attributes"/>
			<String name="First_Name" format="LDML" Scope="attributes"/>
			<String name="Last_Name" format="LDML" Scope="attributes"/>
			<String name="Company" format="LDML" Scope="attributes"/>
			<String name="Phone_Number" format="LDML" Scope="attributes"/>
			<String name="Sex" format="LDML" Scope="attributes"/>
			<String name="Jobs" format="LDML" Scope="attributes"/>
		</in>
		<out>
			<boolean name="isValid" format="LDML" Scope="variables"/>
		</out>
	</io>
</fusedoc>
*/

$isValid = 'No';

var: 'requiredFields_list' = (array: 'Title' = 'Title' , 'First_Name' = 'First Name', 'Last_Name' = 'Last Name', 'Company' = 'Company', 'Phone_Number' = 'Phone Number', 'Sex' = 'Sex', 'Jobs' = 'Jobs');

local:'i' = '';
local: 'counter' = 0;
iterate: $requiredFields_list, #i ;
if: (var: #i->first) == '' ;
$valError->(Insert: (++#counter) = (#i->second) + ' is required.' );
$valErrorLabel->(Insert: #i->first = #i->second );
/if;
/iterate;

if: $valError->Size == 0;
$isValid = 'Yes';
/if;

?>