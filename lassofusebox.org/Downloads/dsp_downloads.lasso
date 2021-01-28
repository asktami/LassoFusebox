[Lasso_Comment]
<fusedoc fuse="dsp_downloads.lasso" language="Lasso" specification="3.0">
	<responsibilities>I display the current downloads available..</responsibilities>
	<properties>
		<history author="Rich Tretola" date="01/31/2003" email="rich@lassofusebox.org" role="Architect" type="Create"/>
		<history author="Tami Williams" date="06/13/2008" email="tami@asktami.com" type="Update"/>
	</properties>
</fusedoc>
[/Lasso_Comment]

<TABLE cellpadding="0" cellspacing="0" border="0">
	<TR>
		<TD>
		<h1>Downloads</h1>
		<p>The core files below will allow you to begin developing Fusebox applications. Applications developed in Fusebox will have advantages such as inheritance, modular code reuse and drag and drop components.</p>
		<p>Sample applications are provided for downloading and viewing. Study the source code and see how they were built.</p>
		<h2>Fusebox Core Files</h2>
		
		<p><a href="assets/downloads/LFB_Core_Files_89.zip">These core files work with Lasso Professional 8.5 thru 9.1.5.</a> - 04/22/2012</p>
		
		<p><a href="assets/downloads/LFB_Core_Files_68.zip">These core files work with Lasso Professional 6.0 thru 8.0.</a> - 01/27/2010</p>
		
		
		<p><i>The original LassoFusebox core, which was called "fbx_fusebox30_LP6.lasso", has been updated with changes from "asktami_LassoFusebox" (including protection against cross-site scripting and cross-site request forgery attacks).  Additional functions have also been added.  The new core is called "fbx_LassoFusebox3.inc".</i></p>
		
		<p>If you have any problems or questions with the core files please <a href="mailto:tami@asktami.com?subject=LFB_Core_Files download issues">email Tami Williams</a>.</p>
		
		
		<h2>Sample Applications</h2>
		<p>Listed below are sample applications (for Lasso 6 thru 9). Study them and learn how they were built. Do you have a sample to contribute? <a href="mailto:[$EmailAddress]?subject=LassoFusebox Sample Application">Send it to us!</a></p>
		
		<table cellpadding="4" cellspacing="0" border="0" width="100%">
		<tr bgcolor="#336633" style="color:white;" valign="middle">
			<td width="40%">Name</td>
			<td width="10%">View</td>
			<td width="15%">Download</td>
			<td width="25%">Author</td>
			<td width="10%">Date</td>
		</tr>
		[If:$getSamples.Found_Count > 0]
		[Records: -InlineName='getSamples']
		<tr valign="top">
			<td><strong>[Field:'Name']</strong></td>
			<td>
			[If:(Field:'Folder')->EndsWith:'LassoApp']
			<a href="assets/demos/[Field:'Folder']" target="_blank">View</a>
			[Else]
			<a href="assets/demos/[Field:'Folder']/index.lasso" target="_blank">View</a>
			[/If]
			</td>
			<td>[If:(Field:'Filename')->size > 0]<a href="assets/downloads/[Field:'Filename']">Download</a>[Else]&nbsp;[/If]</td>
			<td>[If:(Field:'Email')->size > 0]<a href="mailto:[Field:'Email']?subject=RE:[Field:'Name']">[Field:'Author']</a>[else][Field:'Author'][/If]</td>
			<td>04/28/2012<!-- [Date_Format: (Field:'Date'), -Format='%D'] --></td>
		</tr>
		[/Records]
		[Else]
		<tr>
			<td colspan="4" align="center">There are currently no sample applications.</td>
		</tr>
		[/If]
		</table>
		
		<h2>Tools</h2>
		[If:$getTools.Found_Count > 0]
		<table cellpadding="4" cellspacing="0" border="0" width="100%">
		<tr bgcolor="#336633" style="color:white;" valign="middle">
			<td width="60%">Name</td>
			<td width="15%">Download</td>
			<td width="25%">Author</td>
		</tr>
		[Records: -InlineName='getTools']
		<tr valign="top">
			<td><strong>[Field:'Name']</strong></td>
			<td><a href="javascript:;">Download</a></td>
			<td>[If:(Field:'Email')->size > 0]<a href="mailto:[Field:'Email']?subject=RE:[Field:'Name']">[Field:'Author']</a>[else][Field:'Author'][/If]</td>
		</tr>
		[/Records]
		</table>
		[Else]
		<p>There are a number of tools used in the Fusebox community to aid in the development process. Unfortunately, none have yet been ported to LassoFusebox. We are working on them as fast as we can. Would you like to help? <a href="mailto:[$EmailAddress]">Email us!</a></p>
		[/If]
		</TD>
	</TR>
 </TABLE>