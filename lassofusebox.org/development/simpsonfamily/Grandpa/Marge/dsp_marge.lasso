[Lasso_Comment]
<fusedoc  fuse="dsp_marge.lasso" language="Lasso" specification="3.0">
	<responsibilities>
		I display a picture
	</responsibilities>
	<properties>
		<history author="Steve Nelson" email="m@secretagents.com" role="Architect" type="Create">
		<history email="rich@lassofusebox.org" author="Rich Tretola" type="update" date="02/11/2003" role="FuseCoder" comments="Ported to Lasso"/>
	</properties>
	<io>
		<in>
			<string name="fusebox.currentpath"/>
		</in>
	</io>
</fusedoc>
[/Lasso_Comment]
<img src="[Output:$fusebox->(Find:'currentpath'),-EncodeNone]images/marge.gif" alt="" border="0">