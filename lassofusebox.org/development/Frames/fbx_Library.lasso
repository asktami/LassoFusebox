[Define_Tag: 'FBX_Param', -Required='Name', -Required='Default']
  [If: !(Variable_Defined: #Name)][Variable: #Name = #Default][/If]
[/Define_Tag]

[Define_Tag:'FBX_SaveContent', -Container, -Required = 'Variable']
	[Variable_Set:#Variable = (Run_Children)]
[/Define_Tag]


[Define_Tag: 'FBX_Include']
	[FBX_SaveContent: -Variable="_temp"]
	[Include: ($fusebox->(Find:'currentpath') + (Params)->get:1)]
	[/FBX_SaveContent]
	[Return:$_temp]
[/Define_Tag]