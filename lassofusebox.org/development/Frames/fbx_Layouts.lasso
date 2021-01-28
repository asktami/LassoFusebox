[Lasso_Comment]
<fusedoc fuse="FBX_Layouts.lasso">
	<responsibilities>
		This file contains all the conditional logic for determining which layout file, if any, 
		should be used for this circuit. It should result in the setting of the Fusebox public 
		API variables fusebox.layoutdir and fusebox.layoutfile 
	</responsibilities>	
	<io>
		<out>
			<string name="fusebox.layoutDir" />
			<string name="fusebox.layoutFile" />
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]

[FBX_Param: -Name='ignoreLayout', -Default='false']
[If: ($ignoreLayout) == 'true']
    [$fusebox->(Insert:'layoutfile' = '')]
	[$fusebox->(Insert:'layoutdir' = '')]
[Else]
    [$fusebox->(Insert:'layoutfile' = 'lay_ContactApp.lasso')]
	[$fusebox->(Insert:'layoutdir' = '')]
[/IF]
