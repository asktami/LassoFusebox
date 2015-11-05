[
/*
<fusedoc fuse="lay_site.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the layout file.</responsibilities>
	<properties>
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/5/2012" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>

*/
]

<html>
<head>
	<title>[var('gSitename')] - [tw_TitleCase(var('fuseaction'))]</title>
	<style>[include($css + 'style.css')]</style>
</head>
<body bgcolor="#c0c0c0">
<table width="75%" align="center" class="border" bgcolor="#FFFFFF">
	<tr><td><br></td></tr>
	<tr><td align="center">[FBX_Include('_lay/dsp_Header.inc')]</td></tr>
	<tr><td><br></td></tr>
<tr><td>
<!-- display error and feedback messages -->
[include($valErrormsg)]
[include($feedbackmsg)]
</td></tr>
	<tr><td><br></td></tr>
	<tr><td>[Output($layout, -EncodeNone)]</td></tr>
	<tr><td><br></td></tr>
	<tr><td align="center">[FBX_Include('_lay/dsp_Footer.inc')]</td></tr>
	<tr><td><br></td></tr>
</table>
<!-- display debug info -->
[include($debug)]
</body>
</html>