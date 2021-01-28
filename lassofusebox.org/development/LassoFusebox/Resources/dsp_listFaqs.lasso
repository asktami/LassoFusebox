[Lasso_Comment]
<fusedoc fuse="dsp_listFaq.lasso" language="Lasso">
	<responsibilities>
		I display a list of FAQ's.
	</responsibilities>
	<properties>
		<history author="Michael McKellip" date="1/11/2003" email="mmckellip@lassofusebox.org" type="create"></history>
	</properties>
	<io>
		<in>
			<structure name="fusebox">
				<string name="fuseaction" />
				<string name="circuit" />	
			</structure>
			<recordset name="getFaqs" format="LDML" Scope="variables">
				<number name="ID" format="LDML" Scope="variables"/>
				<String name="Question" format="LDML" Scope="variables"/>
				<String name="Answer" format="LDML" Scope="variables"/>
		    </recordset>
		</in>
	</io>	
</fusedoc>
[/Lasso_Comment]

<h1>FAQ's</h1>

[Records:-InlineName='getFaqs']
	<a href="#FAQ[Field:'ID']">[Field:'Question']</a><br>
[/Records]
<hr>
[Records:-InlineName='getFaqs']
<p><a name="FAQ[Field:'ID']"><strong>[Field:'Question']</strong></a><br>
[Field:'Answer', -EncodeNone]</p>
[/Records]