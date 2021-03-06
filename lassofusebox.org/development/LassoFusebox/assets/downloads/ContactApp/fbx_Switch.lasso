[Lasso_Comment]
<fusedoc fuse="FBX_Switch.lasso">
	<responsibilities>
		I am the cfswitch statement that handles the fuseaction, delegating work to various fuses.
	</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/10/2002" email="rich@lassofusebox.org" type="create"></history>
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
	[Case:'listContacts']
		[FBX_Include: 'qry_getAllContacts.lasso']
		[Var: 'XFA_editContact' = 'ContactApp.editContact']
		[Var: 'XFA_deleteContact' = 'ContactApp.deleteContact']
		[Var: 'XFA_newContact' = 'ContactApp.newContact']
		[FBX_Include: 'dsp_AllContacts.lasso']
	[Case:'newContact']
		[FBX_Include: 'qry_getContact.lasso']
		[Var: 'XFA_submit' = 'ContactApp.insertContact']
		[FBX_Include: 'dsp_ContactForm.lasso']
	[Case:'editContact']
		[FBX_Include: 'qry_getContact.lasso']
		[Var: 'XFA_submit' = 'ContactApp.updateContact']
		[FBX_Include: 'dsp_ContactForm.lasso']	
	[Case:'insertContact']
		[FBX_Include: 'act_validate.lasso']
		[If: ($isValid) == 'Yes']
			[FBX_Include: 'qry_insertContact.lasso']
			[Var: 'XFA_redirect' = 'ContactApp.listContacts']
			[FBX_Include: 'url_redirect.lasso']
		[/IF]
	[Case:'updateContact']
		[FBX_Include: 'act_validate.lasso']
		[If: ($isValid) == 'Yes']
			[FBX_Include: 'qry_updateContact.lasso']
			[Var: 'XFA_redirect' = 'ContactApp.listContacts']
			[FBX_Include: 'url_redirect.lasso']
		[/IF]
	[Case:'deleteContact']
		[FBX_Include: 'qry_deleteContact.lasso']
		[Var: 'XFA_redirect' = 'ContactApp.listContacts']
		[FBX_Include: 'url_redirect.lasso']
	[Case]
		<p>This is the default case tag. I received a fuseaction called "[$fuseaction]" and I don't know what to do with it.</p>
[/Select]
[/Encode_Set]