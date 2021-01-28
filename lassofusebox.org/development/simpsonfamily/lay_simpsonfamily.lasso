[Lasso_Comment]
<fusedoc fuse="lay_simpsonfamily.lasso" language="Lasso" specification="3.0">
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

<style>
	h1{font-size:25pt; font-family:Helvetica}
	A {COLOR: #000000;font-size:10pt}
	A:hover {COLOR: #6666ff}
</style>

<table border="3" width="100%" height="100%" bordercolor="000000" cellspacing="0" bgcolor="ffde07">
	<tr>
		<td valign="top" align="center" colspan="2">
			<h1>Fusebox 3.0 Nested Circuits Example</h1>
		</td>
	</tr>
	<tr valign="top" height="100%">
		<td nowrap>
			<a href="index.lasso?fuseaction=simpsonfamily.main"><strong>Family:</strong></a><br>
			<img src="[Output:$fusebox->(Find:'currentpath'),-EncodeNone]images/grandpa.gif"><a href="index.lasso?fuseaction=grandpa.main">Grandpa</a><br>
			&nbsp;&nbsp;&nbsp;<img src="[Output:$fusebox->(Find:'currentpath'),-EncodeNone]images/homer.gif"><a href="index.lasso?fuseaction=homer.main">Homer</a><br>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="[Output:$fusebox->(Find:'currentpath'),-EncodeNone]images/Bart.gif"><a href="index.lasso?fuseaction=Bart.main">Bart</a><br>
			&nbsp;&nbsp;&nbsp;<img src="[Output:$fusebox->(Find:'currentpath'),-EncodeNone]images/Marge.gif"><a href="index.lasso?fuseaction=Marge.main">Marge</a><br>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="[Output:$fusebox->(Find:'currentpath'),-EncodeNone]images/Lisa.gif"><a href="index.lasso?fuseaction=Lisa.main">Lisa</a><br>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="[Output:$fusebox->(Find:'currentpath'),-EncodeNone]images/Maggie.gif"><a href="index.lasso?fuseaction=Maggie.main">Maggie</a><br>
		</td>
		<td align="center" valign="center" width="100%">[Output:$fusebox->(Find:'layout'),-EncodeNone]</td>
	</tr>
	<tr>
		<td colspan="2">
			This Layout File: <strong> simpsonfamily/[Output:$fusebox->(Find:'currentpath'),-EncodeNone]lay_maggie.cfm</strong>
		</td>
	</tr>
</table>