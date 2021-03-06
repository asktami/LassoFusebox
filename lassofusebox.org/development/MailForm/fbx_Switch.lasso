[Lasso_Comment]
<fusedoc fuse="FBX_Switch.lasso">
	<responsibilities>
		I am the cfswitch statement that handles the fuseaction, delegating work to various fuses.
	</responsibilities>
	<properties>
		<history author="r" date="" email="" type="create"></history>
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
	[Case:'Welcome']
		[Var: 'xfa_Submit' = 'home.validate']
		[FBX_Include: 'frm_contact.lasso']
	[Case:'validate']
		[FBX_Include: 'act_validate.lasso']
		[If: ($isValid) == 'Yes']
			[Var: 'xfa_Submit' = 'home.validate']
			[FBX_Include: 'act_email.lasso']
			[Var: 'xfa_redirect' = 'home.thankyou']
			[FBX_Include: 'url_redirect.lasso']
		[/IF]
	[Case:'thankyou']
		[FBX_Include: 'dsp_thankyou.lasso']
	[Case]
		<p>This is the default case tag. I received a fuseaction called "[$fuseaction]" and I don't know what to do with it.</p>
[/Select]
[/Encode_Set]