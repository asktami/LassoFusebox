[Lasso_Comment]
<fusedoc fuse="lay_mailForm.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the default layout file.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="02/06/2003" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
</fusedoc>
[/Lasso_Comment]
<head>
<link rel="STYLESHEET" type="text/css" href="style.css">
</head>
<body bgcolor="#c0c0c0">
[Encode_Set: -EncodeNone]
<table width="75%" align="center" class="border" bgcolor="#FFFFFF">
	<tr>
		<td><br></td>
	</tr>
	<tr>
		<td align="center">[FBX_Include: 'dsp_Header.lasso']</td>
	</tr>
	<tr>
		<td><br></td>
	</tr>
	<tr>
		<td>[Output:$fusebox->(Find:'layout'),-EncodeNone]</td>
	</tr>
	<tr>
		<td><br></td>
	</tr>
	<tr>
		<td align="center">[FBX_Include: 'dsp_Footer.lasso']</td>
	</tr>
	<tr>
		<td><br></td>
	</tr>
</table>
[/Encode_Set]
</body>
</html>