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

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
        "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>[$gsitename]  -  [$pgtitle]</title>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<meta name="robots"  content="noindex,nofollow" />
<link rel="stylesheet" type="text/css" media="screen" href="[var('css')]core.css">
<script type="text/javascript" src="[var('js')]core.js"></script>
<script language="JavaScript" type="text/javascript">
[html_comment]

function IsPopupBlocker() {
var oWin = window.open("","testpopupblocker","width=100,height=50,top=5000,left=5000");
if (oWin==null || typeof(oWin)=="undefined") {
return true;
} else {
oWin.close();
return false;
}
}

/*
// To only run logout countdown IF this layout is not being loaded in a popup window
// and not just sitting at login page or logout page
// change opening IF tag to statements 1-4

1. [if($TargetCircuit == 'popups')]
window.name = "popwin";

2. [else($fuseaction >> 'logout' ||  $circuit == 'start' )]
3. window.name = "main";

4. [else]
[/if]

*/

[if($TargetCircuit !>> 'dothisineverycircuit')]

window.name = "main";

function IsPopupBlocker() {
var oWin = window.open("","testpopupblocker","width=100,height=50,top=5000,left=5000");
if (oWin==null || typeof(oWin)=="undefined") {
return true;
} else {
oWin.close();
return false;
}
}

var counter = 0;
var nbrminutes = 30;
var interval = nbrminutes * 60;

// call Countdown function in 2 seconds after first load
ID=window.setTimeout("Countdown();",2000);

function Countdown() {
  counter++;
  window.status="The counter is now at " + counter;
   
// increment counter variable every 1000 milliseconds / 1 second
 ID=window.setTimeout("Countdown();",1000);
  
// 60 seconds = 1 minute; interval is # seconds that = 14 minutes
// display logout dialog pop up window after 14 minutes have passed

if (counter == interval){
if (IsPopupBlocker()) {
var popblocker = "Yes";
}
}
if (counter == interval && popblocker == 'Yes') {
window.location = "site.lasso?fuseaction=home.logoutA"  ;
	  }
	  else
	  {
		if (counter == interval) {
		logwin = openlogoutwin('logout_dialog.lasso');
		window.clearTimeout(ID);
		}
	  }
}

function StopCountdown() {
window.clearTimeout(ID);
}
[/if]
[/html_comment]
</script>
<!-- check that cookies and javascript are turned on -->
<noscript>[if($fuseaction != 'cookietest')]<meta http-equiv="refresh" content="0; url=[$XFA_cookietest]">[/if]</noscript>
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