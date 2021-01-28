[
/*
<fusedoc fuse="lay_noframes.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the layout file.</responsibilities>
	<properties>
		<history author="Steve Nelson" email="m@secretagents.com" role="Architect" type="Create" />
		<history email="rich@lassofusebox.org" author="Rich Tretola" type="update" date="02/11/2003" role="FuseCoder" comments="Ported to Lasso"/>
		<history author="Tami Williams" email="lassofusebox@asktami.com" date="05/23/2008" type="Update" />
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
	<title>LassoFusebox Nested Layouts Example: SimpsonFamily</title>
	<meta name="robots" content="NOINDEX, NOFOLLOW">
	<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
<table border="3" width="100%" height="100%" bordercolor="000000" cellspacing="0" bgcolor="ffde07">
	<tr>
		<td valign="top" align="center" colspan="2">[FBX_Include($header)]</td>
	</tr>
	<tr valign="top">
		<td nowrap>[FBX_Include($nav)]
			<hr><a href="[$selfFrameY]">Switch to FRAMES</a><hr>
		</td>
		<td align="left">[$layout]</td>
	</tr>
	<tr>
		<td colspan="2">
				This Layout File: <strong>[$layoutfile]</strong>
		</td>
	</tr>
</table>
</body>
</html>