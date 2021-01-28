<?LassoScript
Output_None;

if: $stopLayout == 'Y' ;
	$layoutFile = '';

else;
// just use the layout specified by the child circuit's fbx_Layouts.inc file
	$layoutFile = 'lay_bart.lasso';

/if;

$layoutDir = '';

//	Uncomment the following line if you wish to hide any higher level layouts
// $stopLayout = 'Y' ;

/Output_None;
?>