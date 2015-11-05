[
/*
<fusedoc fuse="fbx_Switch.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I am the Select statement that handles the fuseaction, delegating work to various fuses.
	</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/10/2002" email="rich@lassofusebox.org" type="create"></history>
		<history author="Tami Williams" date="05/23/08" email="tami@asktami.com" type="Update" />
	   <history author="Tami Williams" date="4/20/2012" email="tami@asktami.com" type="Update" />
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

Select($fuseaction);
	Case('defaultfuseaction');
	'This is the default fuseaction for this circuit <b>"' + $circuit + '"</b> when a fuseaction is not specified in the url.' ;

	Case('welcome');
		Var('XFA_submit' = $self + 'home.validate' );
		FBX_Include('dsp_contact.inc');
		
		
	Case('validate');
		FBX_Include('val_email.inc');
		
		If(($isValid) == 'Yes' );
			FBX_Include('act_email.inc');
			Redirect_URL($self + 'home.thank_you' );
			
		else;
			Var('XFA_submit' = $self + 'home.validate' );
			FBX_Include('dsp_contact.inc');
		/if;
		
		
	Case('thank_you');
		FBX_Include('dsp_thankyou.inc');
		
		
	Case;
		FBX_IncludeCommon('dsp_unknownfuseaction.inc');
		// '<p>This is the default case tag. I received a fuseaction called ' + $fuseaction + ' and I don't know what to do with it.</p>' ;

/Select;

]