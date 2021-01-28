<?LassoScript

			
select: $fuseaction;

case: 'defaultfuseaction';
// 	This will be the value returned if someone types in "circuitname." or "circuitname", omitting the actual fuseaction request
		'This is the default fuseaction for this circuit <b>" ' + $circuit + '"</b> when a fuseaction is not specified in the url.' ;


case: 'menu' ;
			FBX_Param: -Name='pgTitle', -Default='' ;
			var:'bgcolor' = 'Lime';
			FBX_Include: 'dsp_newsmenu.inc' ;


case: 'one' ;
			'In News Article One, today, the new government...' ;
			FBX_Param: -Name='pgTitle', -Default='News Article One' ;

case: 'two' ;
			'Article Two was more interesting, however...' ;
			FBX_Param: -Name='pgTitle', -Default='News Article Two' ;

case: 'three' ;
			'News Article Three is not at all interesting.' ;
			FBX_Param: -Name='pgTitle', -Default='News Article Three' ;
			

case;
			// unknown fuseaction
			FBX_IncludeCommon: 'dsp_unknownfuseaction.inc' ;


/select;


?>