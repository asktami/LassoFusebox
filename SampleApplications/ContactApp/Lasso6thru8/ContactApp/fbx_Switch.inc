<?LassoScript
/*
<fusedoc fuse="fbx_Switch.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I am the Select statement that handles the fuseaction, delegating work to various fuses.
	</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/10/2002" email="rich@lassofusebox.org" type="create"></history>
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
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
*/

Select: $fuseaction;
	Case: 'defaultfuseaction';
	'This is the default fuseaction for this circuit <b>"' + $circuit + '"</b> when a fuseaction is not specified in the url.' ;

	Case:'list_Contacts';
		FBX_Include: (LassoApp_Link: 'qry_getAllContacts.inc') ;
		Var: 'XFA_editContact' = $self + 'ContactApp.edit_Contact';
		Var: 'XFA_deleteContact' = $self + 'ContactApp.delete_Contact';
		Var: 'XFA_newContact' = $self + 'ContactApp.new_Contact';
		FBX_Include: (LassoApp_Link: 'dsp_AllContacts.inc') ;
		
	Case:'new_Contact';
		Var: 'XFA_submit' = $self + 'ContactApp.insert_Contact';
		FBX_Include: (LassoApp_Link: 'dsp_ContactForm.inc') ;
		
	Case:'edit_Contact';
		FBX_Include: (LassoApp_Link: 'qry_getContact.inc') ;
				   if:  ($errckError) >>  'error while'  || ($errckCode) != 0 ;
				   		Var: 'XFA_submit' = '#';
				   else;	
				   		Var: 'XFA_submit' = $self + 'ContactApp.update_Contact';
				   /if;
		FBX_Include: (LassoApp_Link: 'dsp_ContactForm.inc') ;	
		
		
	Case:'insert_Contact';
		Var: 'XFA_submit' = $self + 'ContactApp.insert_Contact';
		FBX_Include: (LassoApp_Link: 'val_contactForm.inc') ;
		If: ($isValid) == 'Yes';
			 FBX_Include: (LassoApp_Link: 'qry_insertContact.inc') ;
			
				   if:  ($errckError) >>  'error while'  || ($errckCode) != 0 ;
							Var: 'XFA_submit' = '#';
				   else;
						   Redirect_URL:  $self + 'ContactApp.list_Contacts';
				   /if;
		/if;
		
		FBX_Include: (LassoApp_Link:  'dsp_ContactForm.inc') ;
		
	Case:'update_Contact';
		Var: 'XFA_submit' = $self + 'ContactApp.update_Contact';
		FBX_Include: (LassoApp_Link:  'val_contactForm.inc') ;
		If: ($isValid) == 'Yes';
			 FBX_Include: (LassoApp_Link: 'qry_updateContact.inc') ;
			
				   if:  ($errckError) >>  'error while'  || ($errckCode) != 0 ;
							Var: 'XFA_submit' = '#';
				   else;
						   Redirect_URL:  $self + 'ContactApp.list_Contacts';
				   /if;
		/if;
	
		FBX_Include: (LassoApp_Link:  'dsp_ContactForm.inc') ;
		
		
	Case:'delete_Contact';
		FBX_Include: (LassoApp_Link:  'qry_deleteContact.inc') ;
				   if:  ($errckError) >>  'error while'  || ($errckCode) != 0 ;
				   else;	
				   		Redirect_URL: $self + 'ContactApp.list_Contacts';
				   /if;
		
	Case;
		FBX_IncludeCommon: (LassoApp_Link: 'dsp_unknownfuseaction.inc') ;
		// '<p>This is the default case tag. I received a fuseaction called ' $fuseaction ' and I don't know what to do with it.</p>' ;

/Select;
 ?>