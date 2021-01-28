[
/*
<fusedoc fuse="qry_login.inc" language="Lasso" specification="3.0">
	<responsibilities>I login.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="" email="rich@lassofusebox.org" role="Architect" type="Create"/>
		<history author="Tami Williams" date="5/1/2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/20/2012" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<in>
			<text name="email_calc" format="LDML" Scope="attributes"/>
			<text name="web_password" format="LDML" Scope="attributes"/>
		</in>
		<out>
			<recordset name="getLogin" format="LDML" Scope="variables">
				<number name="lid" format="LDML" Scope="variables"/>
				<String name="First_Name" format="LDML" Scope="variables"/>
				<String name="Last_Name" format="LDML" Scope="variables"/>
		    </recordset>
		</out>
	</io>
</fusedoc>
*/


// since this is just for demonstration purposes I'm hardcoding a variable for the LID here
// in a real example you would do a database query

var('lid' = 'passed' );

]