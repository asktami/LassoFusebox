[Lasso_Comment]
<fusedoc fuse="lay_grandpa.lasso" language="ColdFusion 4.5.2" specification="2.0">
	<responsibilities>
		I display an html layout to the user
	</responsibilities>
	<properties>
		<history author="Steve Nelson" email="m@secretagents.com" role="Architect" type="Create">
		<history email="rich@lassofusebox.org" author="Rich Tretola" type="update" date="02/11/2003" role="FuseCoder" comments="Ported to Lasso"/>
	</properties>
	<io>
		<in>
			<string name="fusebox.currentpath"/>
			<string name="fusebox.layout"/>
		</in>
	</io>
</fusedoc>
[/Lasso_Comment]

<table border="2" height="90%" width="90%" bordercolor="0000ff" cellpadding="15"  cellspacing="0">
	<tr>
		<td colspan="2">
			<img src="images/grandpa.gif">
			Grandpa's Layout File
		</td>
	</tr>
	<tr height="100%">
		<td valign="top" nowrap>
			<strong>Children:</strong><br>
			<img src="images/homer.gif"><a href="index.lasso?fuseaction=homer.main">Homer</a><br>
			<img src="images/Marge.gif"><a href="index.lasso?fuseaction=Marge.main">Marge</a><br>
		</td>
		<td align="center" valign="center" width="100%">[Output:$fusebox->(Find:'layout'),-EncodeNone]</td>
	</tr>
	<tr>
		<td colspan="2">
			This Layout File: <strong> simpsonfamily/[Output:$fusebox->(Find:'currentpath'),-EncodeNone]lay_maggie.cfm</strong>
		</td>
	</tr>
</table>