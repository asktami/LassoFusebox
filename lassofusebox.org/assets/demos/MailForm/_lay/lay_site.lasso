<?LassoScript
Output_None;
/*
<fusedoc fuse="lay_site.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the default layout file.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="02/06/2003" email="rich@lassofusebox.org" role="Architect" type="Create"/>
		<history author="Tami Williams" date="05/23/08" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
*/
/Output_None;
?>
<html>
<head>
	<title>[var:'gSitename'] - [TitleCase:(var:'fuseaction')]</title>
	<style>[FBX_Include: (LassoApp_Link: $css + 'style.css')]</style>
</head>
<body bgcolor="#c0c0c0">
<table width="75%" align="center" class="border" bgcolor="#FFFFFF">
	<tr>
		<td><br></td>
	</tr>
	<tr>
		<td align="center">[FBX_Include: (LassoApp_Link:'_lay/dsp_Header.lasso')]</td>
	</tr>
	
		<tr><td><br></td></tr>
<tr><td>
<!-- display error and feedback messages -->
[FBX_Include: (LassoApp_Link: $valErrormsg)]
[FBX_Include: (LassoApp_Link: $feedbackmsg)]
</td></tr>
	<tr><td><br></td></tr>
	
	<tr>
		<td>[Output: $layout, -EncodeNone]</td>
	</tr>
	<tr>
		<td><br></td>
	</tr>
	<tr>
		<td align="center">[FBX_Include: (LassoApp_Link:'_lay/dsp_Footer.lasso')]</td>
	</tr>
	<tr>
		<td><br></td>
	</tr>
</table>
<!-- display debug info -->
[FBX_Include: (LassoApp_Link: $debug)]
</body>
</html>