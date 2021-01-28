[Lasso_Comment]
<fusedoc fuse="url_redirect.lasso" language="Lasso" specification="3.0">
	<responsibilities>I redirect the user.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/07/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<in>
			<String name="XFA_redirect" format="LDML" Scope="variables"/>
		</in>
	</io>
</fusedoc>
[/Lasso_Comment]

[Redirect_URL: (String_Concatenate: ($self),'?fuseaction=',($XFA_redirect))]
