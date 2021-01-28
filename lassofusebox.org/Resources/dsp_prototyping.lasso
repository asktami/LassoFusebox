[Lasso_Comment]
<fusedoc fuse="dsp_prototyping.lasso" language="Lasso">
	<responsibilities>
		I display information about the Fusebox Lifecycle Process.
	</responsibilities>
	<properties>
		<history author="Rich Tretola" date="1/29/2003" email="rich@lassofusebox.org" type="create"></history>
	</properties>
	<io>
		<in>
			<String name="xfa_architecting" format="CFML" Scope="variables"/>
		</in>
	</io>	
</fusedoc>
[/Lasso_Comment]
<TABLE cellpadding="0" cellspacing="0" border="0">
	<TR>
		<TD>
<h2>Prototyping</h2>
Change requests are natural. When your client begins to ask for change requests, they are beginning
to understand the application. Until they can picture the end result of the application, 
they won't know to ask for the change request. The longer they wait to ask
for that change request, the more it's going to cost you. 
<p>
Here is an example to prove this point. When your client says: "I want to allow my user to enter multiple addresses, 
they might have a home or an office, hmmm maybe two offices.".
<p>
Which is easier?
<p>
a) (later in the process) Modifying a database schema (you stored the address data in the same table as the user data), changing the SQL select, insert, update, delete statements,
adding new ones for the new tables, then changing the Lasso code to reflect these changes in the database, then
changing the HTML to support multiple addresses instead of one address
<p>
b) (earlier in the process) Changing the HTML to show the change in the front end for single vs multiple addresses
<p>
If you can encourage your client to ask for those changes early on, you'll save yourself time, money and headaches.
To help your client picture the end result of the application, FLiP recommends that you build a prototype. A prototype in FLiP 
is the front end of the application. You do not need a database, you do not need if statements or loops.
All you need is the front end. In web applications, we build prototypes in pure html. 
<p>
A FLiP prototype is a clickable html application. It should mirror your wireframe. At least at the beginning. 
You may have left out major areas of the wireframe, because you and/or your client couldn't see what the end result would be. The prototype
should help open your eyes and your client's eyes to make a decision whether the application ultimately solves the
persona's goals.
<p>
If the final application will display data on a page, just
hardcode the data into the HTML. We're not worried about the database design or anything else that is purely technical.
At this point, we want to continue to build and modify our prototype until our client says "That's it! THAT is what i want!"
When they say that (or something similiar), it's time to begin the <a href="[$self][$xfa_architecting]">application architecture.</a>
<br>
<br>
<h2>Tools</h2>
<p>Coming Soon<br>
To help develop new Lasso Fusebox tools please contact us.</p>
		</td>
	</tr>
</table>