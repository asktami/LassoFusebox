<?LassoScript
Encode_Set: -EncodeNone;
   			
select: $fuseaction;

case: 'defaultfuseaction';
// 	This will be the value returned if someone types in "circuitname." or "circuitname", omitting the actual fuseaction request
		FBX_Include: 'dsp_welcome.inc' ;

case: 'welcome';  
		FBX_Include: 'dsp_welcome.inc' ;
		
case;
// unknown fuseaction
		FBX_IncludeCommon:  'dsp_unknownfuseaction.inc' ;

/select;
 
/Encode_Set;
?>
