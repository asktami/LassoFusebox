<?LassoScript

select: $fuseaction;

case: 'frameset';
FBX_Include: 'dsp_frameset.inc' ;

Case:'frmheader';
 FBX_Include: 'dsp_frmheader.inc' ;
 
Case:'frmmenu';
 FBX_Include: 'dsp_frmnav.inc' ;
 
case: 'main';
FBX_Include: 'dsp_simpsonfamily.lasso' ;

case;
// unknown fuseaction
FBX_IncludeCommon: 'dsp_unknownfuseaction.inc' ;

/select;


?>
