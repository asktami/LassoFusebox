      
   
   <?LassoScript
   /*
      <fusedoc fuse="FBX_Settings.lasso"> 
         <responsibilities> 
            I set up the environment settings for this circuit. If this settings file is being inherited, then  
            you can use Variable: to override a value set in a parent circuit or FBX_Param to a accept a value set by a parent circuit. 
         </responsibilities> 
      </fusedoc> 
   */
   ?>
      
   
   <?LassoScript
   /*
   Default FuseAction
   */
   ?>
   [FBX_Param: -Name='fuseaction', -Default='Forum.ListForums']
      
   
   <?LassoScript
   /*
   Useful Constants
   */
   ?>
   [FBX_Param: -Name='self', -Default='index.lasso']
      
   
   <?LassoScript
   /*
   Layout Files
   */
   ?>
   [$fusebox->(Insert:'layoutdir' = '')]
   [$fusebox->(Insert:'layoutfile' = '')]
      
   
   <?LassoScript
   /*
   Suppress Error Messages
   */
   ?>
   [$fusebox->(Insert:'suppressErrors'=false)]
      
   
   [If:($fusebox)->(Find:'IsHomeCircuit')]
   <?LassoScript
   /*
   Home-app execution
   */
   ?>
   [Else]
   <?LassoScript
   /*
   Circuit-app execution
   */
   ?>
      
   [/If]
