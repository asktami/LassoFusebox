[Lasso_Comment]
<fusedoc fuse="FBX_Switch.lasso">
	<responsibilities>
		I am the Select statement that handles the fuseaction, delegating work to various fuses.
	</responsibilities>
	<properties>
		<history author="Rich Tretola" date="02/11/2003" email="rich@lassofusebox.org" type="create"></history>
	</properties>
	<io>
		<in>
			<structure name="fusebox">
				<string name="fuseaction" />
				<string name="circuit" />	
			</structure>
		</in>
	</io>	
</fusedoc>
[/Lasso_Comment]

[Encode_Set: -EncodeNone]
[Select:$fusebox->(Find:'fuseaction')]
	[Case:'main']
		[FBX_Include: 'dsp_simpsonfamily.lasso']
	[Case]
		<p>This is the default case tag. I received a fuseaction called "[$fuseaction]" and I don't know what to do with it.</p>
[/Select]
[/Encode_Set]