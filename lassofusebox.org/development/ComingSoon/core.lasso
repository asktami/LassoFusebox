<?LassoScript// -----------------------------------------------------------------------Variable:'_section' = 2;Library:'fbx_Library.lasso';Variable:'_error' = (Pair:0,(Error_NoError));Variable:'fusebox' = (Map);$fusebox->(Insert:'IsCustomTag'=false);$fusebox->(Insert:'IsHomeCircuit'=false);$fusebox->(Insert:'IsTargetCircuit'=false);$fusebox->(Insert:'fuseaction'='');$fusebox->(Insert:'circuit'='');$fusebox->(Insert:'HomeCircuit'='');$fusebox->(Insert:'TargetCircuit'='');$fusebox->(Insert:'thisCircuit'='');$fusebox->(Insert:'thislayoutpath'='');$fusebox->(Insert:'suppressErrors'=false);$fusebox->(Insert:'Circuits'=(Map));Variable:'_Circuits' = @($fusebox->(Find:'Circuits'));$fusebox->(Insert:'currentPath'='');$fusebox->(Insert:'rootPath'='');// -----------------------------------------------------------------------$_section = 3;Variable:'FB_' = (Map);// -----------------------------------------------------------------------$_section = 4;Iterate:(Action_Params),(Variable:'_temp');	If:!($_temp->First)->(BeginsWith:'-');		Variable:($_temp->First) = ($_temp->Second);	/If;/Iterate;// -----------------------------------------------------------------------$_section = 5;Include:'fbx_Circuits.lasso';// -----------------------------------------------------------------------$_section = 6;Fail_If:$_Circuits->Size == 0,-10001,'The circuits structure does not exist. This must be defined in the Fusebox application\'s root fbx_circuits.lasso file.';$FB_->(Insert:'ReverseCircuitPath'=(Map));Variable:'_ReverseCircuits' = @($FB_->(Find:'ReverseCircuitPath'));Iterate:$_Circuits,(Variable:'aCircuit');	$_ReverseCircuits->(Insert:$aCircuit->Second=$aCircuit->First);		If:$_Circuits->(Find:$aCircuit->First)->(Split:'/')->Size == 1;		$fusebox->(Insert:'HomeCircuit'=$aCircuit->First);		$fusebox->(Insert:'IsHomeCircuit'=true);	/If;/Iterate;// -----------------------------------------------------------------------$_section = 7;Include:'fbx_Settings.lasso';// -----------------------------------------------------------------------$_section = 8;$FB_->(Insert:'rawFA' = $fuseaction);If:$FB_->(Find:'rawFA')->(Split:'.')->Size == 2 && $FB_->(Find:'rawFA')->(EndsWith:'.');	$fusebox->(Insert:'fuseaction' = 'fusebox.defaultfuseaction');Else;	$fusebox->(Insert:'fuseaction' = $FB_->(Find:'rawFA')->(Split:'.')->(Get:2));/If;$fusebox->(Insert:'circuit' = $FB_->(Find:'rawFA')->(Split:'.')->(Get:1));$fusebox->(Insert:'TargetCircuit' = $fusebox->(Find:'circuit'));Fail_If:!(Variable_Defined:'fuseaction') || !($_Circuits->(Find:$fusebox->(Find:'circuit'))),-10003,'The variable "fuseaction" is not available or the Fusebox framework could not find the circuit you requested: "'+($fusebox->(Find:'circuit'))+'".';// -----------------------------------------------------------------------$_section = 9;$FB_->(Insert:'fullPath' =       (String_RemoveLeading:(String_RemoveLeading:$_Circuits->(Find:$fusebox->(Find:'TargetCircuit')),-Pattern=$_Circuits->(Find:$fusebox->(Find:'HomeCircuit'))),-Pattern='/'));$FB_->(Insert:'Corepath' = '');$fusebox->(Insert:'thisCircuit' = $fusebox->(Find:'HomeCircuit'));Iterate:$FB_->(Find:'fullPath')->(Split:'/'),(Variable:'aPath');	If:$FB_->(Find:'corePath')->Size;		$FB_->(Insert:'Corepath' = $FB_->(Find:'corePath') + '/' + $aPath);	Else;		$FB_->(Insert:'Corepath' = $aPath);	/If;		$fusebox->(Insert:'IsHomeCircuit' = false);	$fusebox->(Insert:'currentPath' = $FB_->(Find:'Corepath') + '/');		$fusebox->(Insert:'rootPath' = '');	Loop:(String_RemoveLeading:(String_RemoveTrailing:$fusebox->(Find:'currentPath'),-Pattern='/'),-Pattern='/')->(Split:'/')->Size;		$fusebox->(Insert:'rootPath' = $fusebox->(Find:'rootPath') + '../');	/Loop;		If:$_ReverseCircuits->(Find:$_Circuits ->(Find:$fusebox->(Find:'HomeCircuit')) + '/' + $FB_->(Find:'Corepath'));		$fusebox->(Insert:'thisCircuit' = $_ReverseCircuits->(Find:$_Circuits->(Find:$fusebox->(Find:'HomeCircuit')) + '/' + $FB_->(Find:'Corepath')));		If:$fusebox->(Find:'thisCircuit') == $fusebox->(Find:'TargetCircuit');			$fusebox->(Insert:'IsTargetCircuit' = true);		Else;			$fusebox->(Insert:'IsTargetCircuit' = false);		/If;		Include:$fusebox->(Find:'currentPath') + 'fbx_Settings.lasso';	/If;/Iterate;// -----------------------------------------------------------------------$_section = 10;$fusebox->(Insert:'thisCircuit' = $fusebox->(Find:'TargetCircuit'));$fusebox->(Insert:'IsTargetCircuit' = true);$FB_->(Insert:'fuseboxpath' = $FB_->(Find:'fullPath'));If:$FB_->(Find:'fuseboxpath')->Size;	$FB_->(Insert:'fuseboxpath' = $FB_->(Find:'fuseboxpath') + '/');	$fusebox->(Insert:'IsHomeCircuit' = false);Else;	$fusebox->(Insert:'IsHomeCircuit' = true);/If;$fusebox->(Insert:'currentPath' = $FB_->(Find:'fuseboxpath'));$fusebox->(Insert:'rootPath' = '');Loop:(String_RemoveLeading:(String_RemoveTrailing:$FB_->(Find:'fuseboxpath'),-Pattern='/'),-Pattern='/')->(Split:'/')->Size;	$fusebox->(Insert:'rootPath' = $fusebox->(Find:'rootPath') + '../');/Loop;FBX_SaveContent: -Variable='_layout';	Include:$FB_->(Find:'fuseboxpath') + 'fbx_Switch.lasso';/FBX_SaveContent;$fusebox->(Insert:'layout' = @$_layout);// -----------------------------------------------------------------------$_section = 11;$FB_->(Insert:'circuitalias' = $_Circuits->(Find:$fusebox->(Find:'TargetCircuit')));$FB_->(Insert:'layoutpath' = $_Circuits->(Find:$fusebox->(Find:'TargetCircuit')));While:$FB_->(Find:'layoutpath')->Size;	If:$_ReverseCircuits->(Find:$FB_->(Find:'circuitalias'));		Protect;			$fusebox->(Insert:'thisCircuit' = $_ReverseCircuits->(Find:$FB_->(Find:'circuitalias')));			Handle:false;				$fusebox->(Insert:'thisCircuit' = '');			/Handle;		/Protect;				If:$fusebox->(Find:'thisCircuit') == $fusebox->(Find:'TargetCircuit');			$fusebox->(Insert:'IsTargetCircuit' = true);		Else;			$fusebox->(Insert:'IsTargetCircuit' = false);		/If;		If:$fusebox->(Find:'thisCircuit') == $fusebox->(Find:'HomeCircuit');			$fusebox->(Insert:'IsHomeCircuit' = true);		Else;			$fusebox->(Insert:'IsHomeCircuit' = false);		/If;		$fusebox->(Insert:'ThisLayoutPath' =       (String_RemoveLeading:(String_RemoveLeading:$FB_->(Find:'layoutpath'),-Pattern=$_Circuits->(Find:$fusebox->(Find:'HomeCircuit'))),-Pattern='/'));		If:$fusebox->(Find:'ThisLayoutPath')->Size;			$fusebox->(Insert:'ThisLayoutPath' = $fusebox->(Find:'ThisLayoutPath') + '/');		/If;		$fusebox->(Insert:'currentPath' = $fusebox->(Find:'ThisLayoutPath'));				$fusebox->(Insert:'rootPath' = '');		Loop:(String_RemoveLeading:(String_RemoveTrailing:$fusebox->(Find:'ThisLayoutPath'),-Pattern='/'),-Pattern='/')->(Split:'/')->Size;			$fusebox->(Insert:'rootPath' = $fusebox->(Find:'rootPath') + '../');		/Loop;				Protect;			Include:$fusebox->(Find:'ThisLayoutPath') + 'fbx_Layouts.lasso';			Handle:false;				$fusebox->(Insert:'layoutfile' = '');				$fusebox->(Insert:'layoutdir' = '');			/Handle;		/Protect;				If:$fusebox->(Find:'layoutfile')->Size;			FBX_SaveContent: -Variable='_layout';				Include:$fusebox->(Find:'ThisLayoutPath') + $fusebox->(Find:'layoutdir') + $fusebox->(Find:'layoutfile');			/FBX_SaveContent;			$fusebox->(Insert:'layout' = @$_layout);		/If;	/If;		Variable:'_layoutpath' = $FB_->(Find:'layoutpath')->(Split:'/');	Variable:'_circuitalias' = $FB_->(Find:'circuitalias')->(Split:'/');	$_layoutpath->Remove;	$_circuitalias->Remove;	$FB_->(Insert:'layoutpath' = $_layoutpath->(Join:'/'));	$FB_->(Insert:'circuitalias' = $_circuitalias->(Join:'/'));	/While;?>[Output:$fusebox->(Find:'layout'), -EncodeNone]