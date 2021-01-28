<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
        "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<title>getAppLocation</title>
	<meta name="generator" content="BBEdit 8.7" />
</head>
<body>


<?LassoScript


if: !(Global_Defined: 'gServerName');
		Global: 'gServerName' = (server_name) ;
/If;

If: $gServerName >> 'asktami';
				//	Public Server - asktami DBs, asktami upload folder
				var: 'appLocation' = 'asktami';
				
Else: $gServerName >> 'lassofusebox' ;
				//	Public  Server - Live DBs, lassofusebox upload folder
				var: 'appLocation' = 'lassofusebox';
Else;
	   //	Local Hard Drive, local upload folder
	   var: 'appLocation' = 'local';
/If;


?>

gServerName  = [$gServerName]

<br>
appLocation = [$appLocation]



</body>
</html>
