[Lasso_Comment]
<fusedoc fuse="dsp_fusecoding.lasso" language="Lasso">
	<responsibilities>
		I display information about the Fusebox Lifecycle Process.
	</responsibilities>
	<properties>
		<history author="Rich Tretola" date="1/29/2003" email="rich@lassofusebox.org" type="create"></history>
	</properties>
	<io>
		<in>
			<String name="xfa_unittesting" format="CFML" Scope="variables"/>
		</in>
	</io>	
</fusedoc>
[/Lasso_Comment]
<TABLE cellpadding="0" cellspacing="0" border="0">
	<TR>
		<TD>
<h2>Fusecoding</h2>
<p>
If you're a programmer, this is when the fun begins. Imagine only needing to worry about one file in an application
of 1000 files. This is the art of fusecoding. You're given a very specific blueprint (a fusedoc) for a specific fuse needs to work. The fusedoc does not explain how you will make it work, instead you will be given certain data and your fuse will be expected to perform a specific function. Even if the fusecoder and architect are the same person, fusecoding is a dream. Take off your intensive, "big-picture" hat, and roll up your sleeves for down and dirty fusecoding, without having to worry about how the pieces will all fit together.
<p>
If your fuse is coded according to the fusedoc, it should automatically plug back into the application.
Of course this does not always work the first time, which is why we <a href="[$self][$xfa_unittesting]">unit test</a> each fuse.
<br>
<br>
<h2>Tools</h2>
<p>Coming Soon<br>
To help develop new Lasso Fusebox tools please contact us.</p>
		</td>
	</tr>
</table>