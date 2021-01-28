<?LassoScript
// the site session has a 15 minute limit and this page appears after 14 minutes of inactivity
// this window re-sets the site session limit to 14 minutes & will automatically log out & end the session in 2 minutes IF its not cancelled
// so 14 minutes + 14 minutes  BUT because of auto logout in 2 minutes its really 14 minutes + 2 minutes
// so the session will last 16 minutes total before automatic logout
	   
	   var: 'sessionName' = 'fbxCore';
	   Session_Start(-Name=$sessionName, -Expires=14, -UseAuto);

include('fbx_Library.inc');
include('fbx_Globals.inc');
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>[$gsitename] - Logout</title>
<meta  name="robots"  content="noindex,nofollow">
<link rel="stylesheet" type="text/css" media="screen" href="[var('css')]core.css">

<script language="JavaScript" type="text/javascript">
[html_comment]
// this window stays up for 2 minutes then automatically logs out if the user doesn't click on anything

function logout_submit() {
		window.opener.StopCountdown();
		window.opener.location.href='index.lasso?fuseaction=home.logoutA&[noCache]';
		self.close();
	}
	
	function logout_cancel() {
		window.opener.counter = 0;
		window.opener.Countdown();
		self.close();
	}
	
// 2 * 60 * 1000 => 1000 = 1 sec, x 60 = 1 min, 2 =  for 2 minutes
[/html_comment]
</script>
</head>

<body bgcolor="#FFFFFF" onBlur="window.focus();" onload="setTimeout('logout_submit()',2 * 60 *  1000)">

<div align="center">
  <table width="424" border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td colspan="3" bgcolor="#EEEEEE">
<table width="424" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="12" height="12">&nbsp;</td>
    <td height="12">&nbsp;</td>
    <td width="12" height="12">&nbsp;</td>
  </tr>
  <tr>
    <td width="12">&nbsp;</td>
    <td valign="top" width="400" bgcolor="#CCCCCC">
        <table width="388" border="0" cellspacing="0" cellpadding="3" align="center">
          <tr>
            <td valign="middle" align="left" height="36">
              <p><b>Logout</b></p>
            </td>
          </tr>
        </table>
        <table width="388" border="0" cellspacing="0" cellpadding="3" align="center">
          <tr>
            <td>Selecting the Logout button will erase the current session and clear the current username and password from your Web browser,
            making it impossible for another user to use your browser to visit the site with the authentication information you have provided.
            <br><br>If you do nothing your current session will be automatically logged out after 2 minutes of inactivity, after which you will need to sign in again to continue.
<br><br>
For maximum security, we recommend that all users close their browser window immediately after logging out.
            </td>
          </tr>
          <tr>
            <td align="right">
              <p>
		<form>
		<input type="button" name="Submit" value="Logout" onClick="logout_submit()" />
		<input type="button" name="Submit" value="Cancel" onClick="logout_cancel()" />
		</form>

              </p>
            </td>
          </tr>
        </table>
    </td>
    <td width="12">&nbsp;</td>
  </tr>
  <tr>
    <td width="12" height="12">&nbsp;</td>

    <td height="12">&nbsp;</td>
    <td width="12" height="12">&nbsp;</td>
  </tr>
</table>

      </td>
    </tr>
  </table>
</div>
</body>

</html>
