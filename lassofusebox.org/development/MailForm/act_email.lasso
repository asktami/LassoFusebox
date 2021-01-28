[Lasso_Comment]
<fusedoc fuse="act_email.lasso" language="Lasso" specification="3.0">
	<responsibilities>I send the email.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="02/06/2003" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<in>
			<String name="mailHost" format="LDML" Scope="variables"/>
			<String name="emailAddress" format="LDML" Scope="variables"/>
			<String name="email" format="LDML" Scope="variables"/>
			<String name="subject" format="LDML" Scope="variables"/>
			<String name="body" format="LDML" Scope="variables"/>
		</in>
		<out>
		
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]

[Email_Send: -Host=($mailHost),
-To=($email),
-From=($emailAddress),
-Subject=($subject),
-Body=($message)]


