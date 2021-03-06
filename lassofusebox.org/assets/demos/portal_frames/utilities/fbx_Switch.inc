<?LassoScript


			
select: $fuseaction;

case: 'defaultfuseaction';
			// This will be the value returned if someone types in "circuitname." or "circuitname", omitting the actual fuseaction request
			'This is the default fuseaction for this circuit <b>" ' + $circuit + '"</b> when a fuseaction is not specified in the url.' ;


case: 'menu' ;
			FBX_Param: -Name='pgTitle', -Default='' ;
			var:'bgcolor' = 'red';
			FBX_Param: -Name='XFA_help', -Default=$self +'utilities.help' ;
			FBX_Param: -Name='XFA_credits', -Default=$self +'utilities.credits' ;
			FBX_Param: -Name='XFA_contact_me', -Default=$self +'utilities.contact_me' ;
			FBX_Include: 'dsp_utilitymenu.inc' ;


case: 'help' ;
			'Click on the links and see what happens.' ;
			FBX_Param: -Name='pgTitle', -Default='Help' ;

case: 'credits' ;
			'Converted to LassoFusebox by Tami Williams.' ;
			FBX_Param: -Name='pgTitle', -Default='Credits' ;

case: 'contact_me' ;
			'<A HREF=\"mailto:tami@asktami.com\">tami@asktami.com</A>
			<br>
			<A HREF=\"http://www.asktami.com\" TARGET=\"_blank\">http://www.asktami.com</A>' ; 
			FBX_Param: -Name='pgTitle', -Default='Contact Me' ;
			

case;
			// unknown fuseaction
			FBX_IncludeCommon: 'dsp_unknownfuseaction.inc' ;


/select;

?>