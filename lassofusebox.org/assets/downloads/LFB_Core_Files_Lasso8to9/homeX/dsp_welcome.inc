[
/*
<fusedoc fuse="dsp_Welcome.inc" language="Lasso" specification="3.0">
<responsibilities>I am the home page.</responsibilities>
<properties>
 <history author="Tami Williams" date="June 2008" email="tami@asktami.com" type="Create" />
 <history author="Tami Williams" date="4/28/2012" email="tami@asktami.com" type="Update" />
</properties>
<io>
 <in>
	 <String name="[$XFA_login]" format="LDML" Scope="variables"/>
	 <number name="lid" format="LDML" Scope="variables"/>
 </in>
 <out>
	 <number name="email_calc" format="LDML" Scope="formOrUrl"/>
	 <String name="web_password" format="LDML" Scope="formOrUrl"/>
 </out>
</io>
</fusedoc>
*/
]

<h1>Welcome to LassoFusebox</h1>

<hr>
<hr>
<p><a href="#" onClick="openwin('[$XFA_popupLasso]')">Example LassoPopUp Window</a></p>





[if(var('lid'))]
<hr>
<hr>
<h3><u>You are logged in!</u></h3>
<p><a href="[$XFA_secure]">Example Secure Circuit</a></p>

[else]

<form action="[$XFA_login]" method="post" name="loginform">
<h3>Login</h3>
Use any valid email address and any alphanumeric string for the password.
<p>Enter Logon Email: <input type="text" name="email_calc" value="[var('email_calc')]" size="20" />
<br>Enter Password: <input type="password" name="web_password" value="[var('web_password')]" size="20" maxlength="20" /></p>
<input type="submit" value="Go">

[/if]

