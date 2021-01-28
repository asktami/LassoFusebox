[Lasso_Comment]
<fusedoc fuse="dsp_samples.lasso" language="Lasso" specification="3.0">
	<responsibilities>I display the current samples available.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="01/31/2003" email="rich@lassofusebox.org" role="Architect" type="Create"/>
		<history author="Tami Williams" date="06/15/2008" email="tami@asktami.com" type="Update"/>
	</properties>
</fusedoc>
[/Lasso_Comment]

<TABLE cellpadding="0" cellspacing="0" border="0">
	<TR>
		<TD>
<h1>White Papers</h1>
<p>Listed below are white papers and presentations about Fusebox. Fusebox being
  a methodology is not language specific. The same principles apply regardless
  of what language you develop in. Therefore, some of the documents below will
  be Lasso specific and others will be more generic.</p>

		<table cellpadding="4" cellspacing="0" border="0" width="100%">
		<tr bgcolor="#336633" style="color:white;" valign="middle">
			<td width="65%">Name</td>
			<td width="10%">View</td>
			<td width="25%">Author</td>
		</tr>
		[If:$getWhitepapers.Found_Count > 0]
		[Records: -InlineName='getWhitePapers']
		<tr valign="top">
			<td><strong>[Field:'Name']</strong></td>
			<td><a href="assets/whitepapers/[Field:'Filename']">Word</a>&nbsp;&nbsp;<a href="assets/whitepapers/LFB_Specification.pdf">PDF</a></td>
			<td>[If:(Field:'Email')->size > 0]<a href="mailto:[Field:'Email']?subject=RE:[Field:'Name']">[Field:'Author']</a>[else][Field:'Author'][/If]</td>
		</tr>
		<tr>
			<td colspan="3"><p>[Field:'Description', -EncodeNone]</p><hr></td>
		</tr>
		[/Records]
		[Else]
		<tr>
			<td colspan="4" align="center">There are currently no white papers or presentations.</td>
		</tr>
		[/If]
		</table>
		</TD>
	</TR>
 </TABLE>