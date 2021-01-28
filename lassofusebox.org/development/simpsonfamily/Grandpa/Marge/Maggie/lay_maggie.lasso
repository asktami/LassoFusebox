[Lasso_Comment]
<fusedoc fuse="lay_maggie.lasso" language="Lasso" specification="3.0">
	<responsibilities>
		I display an html layout to the user
	</responsibilities>
	<properties>
		<history author="Steve Nelson" email="m@secretagents.com" role="Architect" type="Create">
		<history email="rich@lassofusebox.org" author="Rich Tretola" type="update" date="02/11/2003" role="FuseCoder" comments="Ported to Lasso"/>
	</properties>
	<io>
		<in>
			<string name="fusebox.currentpath"/>
			<string name="fusebox.layout"/>
		</in>
	</io>
</fusedoc>
[/Lasso_Comment]

<table width="90%" height="90%" align="center" valign="center" cellpadding="15" border="2" cellspacing="0" bordercolor="008080">
	<tr>
		<td colspan="2">
			<img src="images/maggie.gif">
			Maggie's Layout File
		</td>
	</tr>
	<tr height="100%">
		<td valign="top">
			<strong>Children:</strong><br>
			None
		</td>
		<td align="center" valign="center" width="100%">[Output:$fusebox->(Find:'layout'),-EncodeNone]</td>
	</tr>
	<tr>
		<td colspan="2">
			This Layout File: <strong> simpsonfamily/[Output:$fusebox->(Find:'currentpath'),-EncodeNone]lay_maggie.cfm</strong>
		</td>
	</tr>
</table>