<?LassoScript

Select:$fuseaction;

case: 'defaultfuseaction';
// This will be the value returned if someone types in "circuitname.", omitting the actual fuseaction request
// EX: if in url fuseaction="maggie" or "maggie."
'DEFAULT FUSEACTION FOR THIS CIRCUIT ' + $circuit + ' WHEN NOT SPECIFIED IN URL' ;


case:'main';
		FBX_Include: 'dsp_maggie.lasso' ;
		
		
case;
	'This is the \"unknown fuseaction\" case tag in Maggie\'s circuit.' ;
	

/Select;

?>