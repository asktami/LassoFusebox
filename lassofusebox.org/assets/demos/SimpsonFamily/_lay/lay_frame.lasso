<?LassoScript
Output_None;
/*
<fusedoc fuse="lay_frame.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the layout file.</responsibilities>
	<properties>
		<history author="Tami Williams" email="lassofusebox@asktami.com" date="May 2003" type="Create" />
		<history author="Tami Williams" email="lassofusebox@asktami.com" date="May 2008" type="Update" />
	</properties>
	<io>
		<in>
			<string name="fusebox.currentpath"/>
			<string name="fusebox.layout"/>
		</in>
	</io>
</fusedoc>
*/
/Output_None
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
        "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<title>LassoFusebox Nested Layouts Example: SimpsonFamily FrameSet</title>
	<meta name="robots" content="NOINDEX, NOFOLLOW">
	<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
[Output: $layout, -EncodeNone]
<hr>
This Layout Path: <strong> simpsonfamily/[$currentpath]</strong>
<br>This Layout File: <strong>[$layoutfile]</strong>
</body>
</html>