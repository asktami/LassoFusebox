<?LassoScript

Select:$fuseaction;

case: 'defaultfuseaction';
// This will be the value returned if someone types in "circuitname.", omitting the actual fuseaction request
// EX: if in url fuseaction="homer" or "homer."
'DEFAULT FUSEACTION FOR THIS CIRCUIT ' + $circuit + ' WHEN NOT SPECIFIED IN URL' ;

case:'main';
		FBX_Include: 'dsp_homer.lasso' ;
		
		
case;
	// unknown fuseaction
		FBX_IncludeCommon: 'dsp_unknownfuseaction.inc' ;
/Select;


?>