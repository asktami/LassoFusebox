[Lasso_Comment]
<fusedoc fuse="frm_contact.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the contact us form.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="02/06/2003" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<in>
			<String name="xfa_Submit" format="LDML" Scope="variables"/>
		</in>
		<out>
			<String name="enail" format="LDML" Scope="formOrUrl"/>
			<String name="subject" format="LDML" Scope="formOrUrl"/>
			<String name="message" format="LDML" Scope="formOrUrl"/>
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]

<form name="contact" action="[$self]?fuseaction=[$xfa_Submit]" method="post">
<table align="center">
	<tr>
		<td class="bodycopy">Email Address:</td>
		<td><input type="text" name="email" size="40"></td>
	</tr>
	<tr>
		<td class="bodycopy">Subject:</td>
		<td><input type="text" name="subject" size="40"></td>
	</tr>
	<tr>
		<td class="bodycopy">Message:</td>
		<td><textarea name="message" cols="40" rows="10"></textarea></td>
	</tr>
	<tr>
		<td>&nbsp;</td>
		<td><input type="submit" value="Submit"></td>
	</tr>
</table>
</form>