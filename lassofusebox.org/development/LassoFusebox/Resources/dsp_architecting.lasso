[Lasso_Comment]
<fusedoc fuse="dsp_architecting.lasso" language="Lasso">
	<responsibilities>
		I display information about the Fusebox Lifecycle Process.
	</responsibilities>
	<properties>
		<history author="Rich Tretola" date="1/29/2003" email="rich@lassofusebox.org" type="create"></history>
	</properties>
	<io>
		<in>
			<String name="xfa_fusecoding" format="CFML" Scope="variables"/>
		</in>
	</io>	
</fusedoc>
[/Lasso_Comment]
<TABLE cellpadding="0" cellspacing="0" border="0">
	<TR>
		<TD>
<h2>Application Architecting</h2>
This area of FLiP is primarily based on experience and personal style. Experienced architects know when to create one circuit instead of two, or two circuits instead of one. Architects also learn when and how to apply nested layouts most effectively. They can combine design patterns like MVC, other language resources like Java libraries in ColdFusion applications, as well as object-oriented requirements into a clean, extensible, maintanable and robust architecture.<br><br>
Regardless of how you get there, you should end up with:
<ul>
<li>Circuits</li>
<li>Fuseactions</li>
<li>XFAs</li>
<li>Fuses (uncoded, AKA FuseStubs)</li>
<li>Fusedocs</li>
</ul>
<p>
Even with this structure, we still have not yet defined exactly how the code will work. We have simply defined the data interactions between the various pieces of the application. How will data be sent from one fuseaction to another? How will fuseactions be linked together? What data will come out of one fuse and be passed into another?
<p>
Since this is such a large topic, and oftentimes very specific to the individual application, check out the articles below.
<p>
When you're done architecting the application, now it's time to move onto the fun part: <a href="[$self]?fuseaction=[$xfa_fusecoding]">Fusecoding</a>
<br>
<br>
<h2>Tools</h2>
<p>Coming Soon<br>
To help develop new Lasso Fusebox tools please contact us.</p>
		</td>
	</tr>
</table>