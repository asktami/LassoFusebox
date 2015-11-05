[
/*
<fusedoc fuse="lay_noframes.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the layout file.</responsibilities>
	<properties>
		<history author="Steve Nelson" email="m@secretagents.com" role="Architect" type="Create" />
		<history email="rich@lassofusebox.org" author="Rich Tretola" type="update" date="02/11/2003" role="FuseCoder" comments="Ported to Lasso"/>
		<history author="Tami Williams" email="lassofusebox@asktami.com" date="05/23/2008" type="Update" />
		<history author="Tami Williams" date="4/22/2012" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<in>
			<string name="fusebox.currentpath"/>
			<string name="fusebox.layout"/>
		</in>
	</io>
</fusedoc>
*/
]

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
        "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<title>[$pgTitle]</title>
	<meta name="robots" content="noindex, nofollow">
</head>
<body>

<table width="800" border="1" cellpadding="4" cellspacing="0">
    <tr>
        <td colspan="2" bgcolor="cyan">[FBX_Include('main/dsp_banner.inc')]</td>
    </tr>
    <tr>
        <td width="25%" bgcolor="Yellow">[FBX_Include('main/dsp_mainmenu.inc')]</td>
        <td width="75%" rowspan="2" valign="top" align="left" bgcolor="[var('bgcolor')]"><h3>[$pgTitle]</h3>
        [Output($layout, -encodeNone)]</td>
    </tr>
    <tr>
        <td bgcolor="Lime">[FBX_Include('news/dsp_newsmenu.inc')]</td>
    </tr>
    <tr>
        <td colspan="2" bgcolor="red">[FBX_Include('utilities/dsp_utilitymenu.inc')]</td>
    </tr>
</table>
</body>
</html>