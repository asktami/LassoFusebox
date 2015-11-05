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
        <td colspan="2" bgcolor="cyan">[Include_URL($selfURL + 'main.banner&stopLayout=Y', -encodeNone)]</td>
    </tr>
    <tr>
        <td width="25%" bgcolor="Yellow">[Include_URL($selfURL + 'main.menu&stopLayout=Y', -encodeNone)]</td>
        <td width="75%" rowspan="2" valign="top" align="left" bgcolor="[$bgcolor]"><h3>[$pgTitle]</h3>
        [Output($layout, -encodeNone)]</td>
    </tr>
    <tr>
        <td bgcolor="Lime">[Include_URL($selfURL + 'news.menu&stopLayout=Y', -encodeNone)]</td>
    </tr>
    <tr>
        <td colspan="2" bgcolor="red">[Include_URL($selfURL + 'utilities.menu&stopLayout=Y', -encodeNone)]</td>
    </tr>
</table>
</body>
</html>