[Lasso_Comment]
<fusedoc fuse="lay_ContactApp.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the layout file.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/07/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
</fusedoc>
[/Lasso_Comment]

<html>
<head>
<link rel="STYLESHEET" type="text/css" href="style.css">
</head>
<body bgcolor="#c0c0c0">
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
</body>
</html>