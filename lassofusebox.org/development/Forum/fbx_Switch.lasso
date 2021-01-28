<?LassoScript
/*
<fusedoc fuse="FBX_Switch.lasso">
   <responsibilities>
      Threaded message forum.
      
      I allow users to participate in online discussions on specific topics
      of interest.  I allow users to browse lists of messages, view
      individual messages and post messages.
   </responsibilities>
</fusedoc>
*/
?>
[Variable:'fuseSuccess' = true ]
[Variable:'fuseFailure' = false ]

[Encode_Set: -EncodeNone]
[Select:$fusebox->(Find:'fuseaction')]
   <?LassoScript
   /*
     Allows users to list available forums.
   */
   ?>
   [Case:'ListForums']
      [FBX_Include:(LassoApp_Link:'qry_GetForumList.lasso')]
      [Variable:'XFA_ListMessages' = 'Forum.ListMessages']
      [FBX_Include:(LassoApp_Link:'dsp_ForumList.lasso')]
   
   
   <?LassoScript
   /*
     Allows users to list forum messages.
   */
   ?>
   [Case:'ListMessages']
      [FBX_Include:(LassoApp_Link:'qry_GetForumMessages.lasso')]
      [Variable:'XFA_PostMessage' = 'Forum.PostMessage']
      [Variable:'XFA_ViewMessage' = 'Forum.ViewMessage']
      [FBX_Include:(LassoApp_Link:'dsp_MessageList.lasso')]
   
   
   <?LassoScript
   /*
     Allows users to post messages to the message board.
   */
   ?>
   [Case:'PostMessage']
      [Variable:'XFA_Post' = 'Forum.SaveMessage']
      [FBX_Include:(LassoApp_Link:'dsp_PostMesage.lasso')]
   
   
   <?LassoScript
   /*
     Allows users to save messages.
   */
   ?>
   [Case:'SaveMessage']
      [FBX_Param: -Name='FailedReply', -Default='']
      [Variable:'XFA_FailedPost' = 'Forum.PostMessage']
      [Variable:'XFA_FailedReply' = 'Forum.PostReply']
      [FBX_Include:(LassoApp_Link:'act_ValidateMessage.lasso')]
      [FBX_Include:(LassoApp_Link:'qry_InsertMessage.lasso')]
      [If: success ]
         [FBX_Redirect:(LassoApp_Link:($self)) + '?fuseaction=XFA_Success']
      [/If]
      [If: faulure ]
         [If: FailedReply ]
            [FBX_Redirect:(LassoApp_Link:($self)) + '?fuseaction=XFA_FailedReply']
         [/If]
         [FBX_Redirect:(LassoApp_Link:($self)) + '?fuseaction=XFA_FailedPost']
      [/If]
   
   
   <?LassoScript
   /*
     Allows users to view messages.
   */
   ?>
   [Case:'ViewMessage']
      [FBX_Include:(LassoApp_Link:'qry_GetMessage.lasso')]
      [Variable:'XFA_Reply' = 'Forum.PostReply']
      [FBX_Include:(LassoApp_Link:'dsp_MessageDetail.lasso')]
   
   
   <?LassoScript
   /*
     Allows users to post a replt to a message
   */
   ?>
   [Case:'PostReply']
      [FBX_Include:(LassoApp_Link:'qry_GetMessage.lasso')]
      [Variable:'XFA_Post' = 'Forum.SaveMessage']
      [FBX_Include:(LassoApp_Link:'dsp_PostMesage.lasso')]
   
   
   [Case:'DrawNavigation']
      [Variable:'XFA_ListForums' = 'Forum.ListForums']
      [Variable:'XFA_ListMessages' = 'Forum.ListMessages']
      [FBX_Include:(LassoApp_Link:'dsp_Navigation.lasso')]
   
   
   
   <?LassoScript
   /*
   Default Execution
   */
   ?>
   [Case]
      <p>This is the default case tag. I received a fuseaction called "[$fuseaction]" and I don't know what to do with it.</p>
   
   
   [/Select]
   [/Encode_Set]
