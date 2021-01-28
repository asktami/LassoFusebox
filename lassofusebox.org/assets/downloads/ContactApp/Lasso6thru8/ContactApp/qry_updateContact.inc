[Output_None]
<fusedoc fuse="qry_updateContact.lasso" language="Lasso" specification="3.0">
	<responsibilities>I update the person table.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/11/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
		<history author="Tami Williams" date="5/1/2008" email="tami@asktami.com" type="Update" />
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
[/Output_None]


[Inline: -Update,
	$writeCon,
    -Table='People',
    -KeyValue=($ID),
	'Title'=($Title),
    'First_Name'=($First_Name),
	'Last_Name'=($Last_Name),
	'Company'=($Company),
	'Phone_Number'=($Phone_Number),
	'Sex'= ($Sex),
	'Jobs'=($Jobs)]
	
	[include: (LassoApp_Link: $debuginline)]
	
[/Inline]