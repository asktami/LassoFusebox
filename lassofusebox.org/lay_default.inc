<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"
            "http://www.w3.org/TR/html4/strict.dtd"> 
<html>
<head>
<title>LassoFusebox</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<link rel="stylesheet" href="v4sheet.css" type="text/css">
<script type="text/javascript">
<!--

function MM_reloadPage(init) {  //Updated by PVII. Reloads the window if Nav4 resized
  if (init==true) with (navigator) {if ((appName=="Netscape")&&(parseInt(appVersion)==4)) {
    document.MM_pgW=innerWidth; document.MM_pgH=innerHeight; onresize=MM_reloadPage; }}
  else if (innerWidth!=document.MM_pgW || innerHeight!=document.MM_pgH) history.go(0);
}
MM_reloadPage(true);

function P7_StyleLoader(tS) { //v1.1 by PVII
 var tH='',tDoc='',tA='<LIN'+'K REL="stylesheet" HREF=',tB=' TYPE="text/css">';
 if(document.getElementsByTagName){var bb=document.getElementsByTagName("LINK");
 if(bb) {for(var k=0;k<bb.length;k++){if(bb[k].rel.toLowerCase()=="stylesheet"){
 var h=bb[k].href,x=h.lastIndexOf("/");if(x>0){tH=h.substring(0,x+1);}
 bb[k].disabled=true;tDoc=tA+'"'+ tH + tS + '"' +tB;
 document.write(tDoc);break;}}}}
}
P7_StyleLoader('w3csheet.css');
//-->
</script>
</head>
<body>
<div id="LayerLogo" style="position:absolute; left:0px; right:0px; top:0px; width:560px; z-index:1;"><img src="assets/images/topper.jpg" width="560" height="74" alt="PVII CSS Master Series"></div>
<div id="LayerBanner" style="position:absolute; left:18px; top:82px; z-index:2; width: 487px" class="navDiv">[If:($isLoggedIn)]Welcome [$Session_FirstName][Else]&nbsp;[/If]</div>
<div id="LayerSidebar" style="position:absolute; left:36px; top:156px; width:160px; z-index:3" class="navDiv"> 
<p class="navButts"><a href="[$self]home.welcome">Home</a></p>
<p class="navButts"><a href="[$self]home.gettingstarted">Getting Started</a></p>
<p class="navButts"><a href="[$self]resources.FLiP">What is FLiP?</a></p>
<p class="navButts"><a href="[$self]resources.whitepapers">White Papers</a></p>
<p class="navButts"><a href="[$self]resources.samples">Samples</a></p>
<p class="navButts"><a href="[$self]downloads.list">Downloads</a></p>
<p class="navButts"><a href="[$self]resources.faq">FAQ</a></p>
<hr>
[If:($isLoggedIn)]
<p class="navButts"><a href="[$self]login.logout">Logout</a></p>
<p class="navButts"><a href="[$self]login.myprofile">My Profile</a></p>
[Else]
<p class="navButts"><a href="[$self]login.login">Login</a></p>
<p class="navButts"><a href="[$self]login.register">Register</a></p>
[/If]
<p><img src="assets/images/clean_sidebar.gif" width="160" height="16" alt=""></p>
<!-- <h2 style="color:#336633;">Breaking News...</h2> -->
<p>Hosting sponsored by<br><a href="http://www.pointinspace.com"><img src="assets/images/pisbutton.gif"></a></p>
<p><a href="http://www.lassosoft.com/" target="_blank"><img src="assets/images/lassoLogo.png" border="0"></a></p>
</div>
<div id="LayerMain" style="position:absolute; left:250px; top:156px; z-index:4" class="maindiv"> 
[$layout]
<p class="copyrights">Copyright &copy;[Date->year] LassoFusebox, All Rights 
Reserved.</p>
<p class="footer">
Contact: <!-- <a href="mailto:[$BCCEmailAddress]">[$BCCEmailAddress]</a>, <a href="mailto:[$AltEmailAddress]">[$AltEmailAddress]</a> and  --><a href="mailto:[$EmailAddress]">Tami Williams</a></p>
<p><a href="https://github.com/asktami/LassoFusebox" target="_blank">
<img src="assets/images/gitHub-download-button.png" width="115" height="35" alt="Download from GitHub">
</a></p>
</div>
<div id="LayerMail" style="position:absolute; left:251px; top:156px; width:26px; z-index:5" class="icondiv"><a href="mailto:[$EmailAddress]"><img src="assets/images/mailv.gif" width="26" height="26" alt="Contact Us"></a></div>
</body>
</html>
