<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
	<title>BrowserTest</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<meta name="distribution" content="global">
<meta name="language" content="en">
<meta name="robots"  content="noindex,nofollow">
</head>
<body bgcolor="#FFFFFF">
<p>Checking Browser ... </p>

[$browserVerStr->(Replace( ')', ''))]

[if($browserOK != 1)]
  [if($failReason == 'incompatible')]
<p>Your web browser ([$browser]) is not compatible with this website.
You must use a different web browser such as <a href="http://www.mozilla.org/products/firefox/">Firefox</a> or <a href="http://www.microsoft.com/windows/ie/downloads/default.mspx">Internet Explorer</a>.</p>
  [else]
<p>Your web browser ([$browser] [$browserVerStr]) is too old to work with this website.
You must upgrade to version [$minMajorVer].[$minMinorVer] or higher.
</p>
  [/if]
[/if]

[html_comment]
Client_Browser= [Client_Browser]
<br>Browser = [$browser]
<br>BrowserVerStr = [$browserVerStr]
<br>BrowserMajorVer = [$browserMajorVer]
<br>BrowserMinorVer = [$browserMinorVer]
<br>minMajorVer = [$minMajorVer]
<br>minMinorVer = [$minMinorVer]
<br>failReason = [$failreason]
[/html_comment]
</body>
</html>