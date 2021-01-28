[
/*
<fusedoc fuse="lay_simple.lasso" language="Lasso" specification="3.0">
	<responsibilities>I am the layout file.</responsibilities>
	<properties>
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Create" />
		<history author="Tami Williams" date="4/27/2012" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
*/
]
<html>
<head>
<title>[$gsitename]  -  [$pgtitle]</title>
<link rel="stylesheet" type="text/css" media="screen" href="[var('css')]core.css">
<script type="text/javascript" src="[var('js')]core.js"></script>
</head>
<body>


<div>
<h1><a href="[$XFA_welcome]">HOME</a>&nbsp;&nbsp;&nbsp;&nbsp;<a href="[$XFA_secure]">SECURE</a>&nbsp;&nbsp;&nbsp;&nbsp;<a href="[$XFA_logout]">LOGOUT</a></h1>
<hr>
<hr>
</div>

<div>
[include($valErrormsg)]
[include($feedbackmsg)]
</div>

<div>
[Output($layout,-EncodeNone)]
</div>


<div>
[include($debug)]
</div>
</body>
</html>
