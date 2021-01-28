[
/*
<fusedoc fuse="val_loginForm.inc" language="Lasso" specification="3.0">
	<responsibilities>I validate the form.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/07/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/28/2012" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<in>
			<Number name="email_calc" format="LDML" Scope="attributes"/>
			<String name="web_password" format="LDML" Scope="attributes"/>
		</in>
		<out>
			<boolean name="isValid" format="LDML" Scope="variables"/>
		</out>
	</io>
</fusedoc>
*/

$isValid = 'No';


if(var('email_calc') == '' || (var('email_calc') != ''  &&  valid_email(string(var('email_calc'))) != 'true') );
		$valError->Insert('email_calc' = 'Enter a valid Email Address using this format: xxx@xxx.com' );
/if;


if(var('web_password') == '' );
$valError->Insert('web_password'= 'Password is required.');
/if;

if(var('web_password') != ''  && String_IsAlphaNumeric(var('web_password')) != 'true' );
$valError->Insert('web_password'= 'Only alphabetic characters or numerals (a-z, A-Z, or 0-9) are allowed in your Password.');
/if;
 

if($valError == (map));
$isValid = 'Yes';
/if;

]