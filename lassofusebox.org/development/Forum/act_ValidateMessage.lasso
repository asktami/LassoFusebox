
<?LassoScript 
/*
<fusedoc fuse="act_ValidateMessage
   <responsibilities>
      I validate that all the needed message information is provided.  If
      all all of the necessary information is not provided, the user will be
      sent back to the PostMessage screen.  If there are problems with the
      data and a messageID was submitted then I know that this post is
      actually a reply and I will set FailedReply to true, this will cause
      the user to be sent to XFA_FailedReply instead of XFA_FailedPost.
   </responsibilities>
   <note>
      
      Requirement: Message Subject Required - Users can not post forum
      messages with a blank subject.
      If a users tries to post a message with a blank subject, they should
      be returned to the post page and given a message to please add a subject.
      
      Requirement: Valid Email Required - Require user to provide a UserName.
      In order to post a message to the forum, the user must supply an email
      address.  While the email will not be used, it must at least be a well
      formed email address in order to ensure a minimum level of data
      validation and identity verification.
      
      Requirement: Message Length - Limited to 5000 characters.
      User messages will be limited to a maximum of 5000 characters.
      
      Requirement: Message Body Required - Blank Posts Not Allowed
      Users must not be allowed to post blank messages.  If they try to post
      a blank message they should be returned to the posting page and given
      a polite error message asking them to enter content into the body of the post.
   </note>
   <note>
      Data Rules: XFA_FailedPost - 
      Data Rules: XFA_FailedReply - 
      Data Rules: XFA_Success - 
      Data Rules: authorEmail - EmailAddress, 
      Data Rules: authorName - Can Not Be Blank, 
      Data Rules: forumID - 
      Data Rules: fuseaction - 
      Data Rules: messageBody - Max Length 5000, Can Not Be Blank, 
      Data Rules: messageID - All Numbers, 
      Data Rules: subject - Can Not Be Blank, 
   </note>
   <io>
   
      <in>
         <String name="self" optional="false" />
         <String name="messageBody"  optional="false" scope="request"/>
         <Numeric name="messageID"  optional="true" scope="request"/>
         <String name="subject"  optional="false" scope="request"/>
         <String name="authorName"  optional="false" scope="request"/>
         <String name="authorEmail"  optional="false" scope="request"/>
         <Numeric name="forumID"  optional="false" scope="request"/>
         <String name="XFA_FailedReply"  optional="false" scope="request"/>
         <String name="XFA_FailedPost"  optional="false" scope="request"/>
         <String name="XFA_Success"  optional="false" scope="request"/>
      </in>
      
      <out>
         <String name="fuseaction"  optional="true" scope="request"/>
      </out>
      
      <passthrough>
      </passthrough>
      
   </io>
</fusedoc>
*/ 
?>
<br><br>act_ValidateMessage<br>
&nbsp;&nbsp;&nbsp;<a href="[LassoApp_Link:($self)]?fuseaction=[$XFA_FailedPost]">[$XFA_FailedPost]</a><br>
&nbsp;&nbsp;&nbsp;<a href="[LassoApp_Link:($self)]?fuseaction=[$XFA_FailedReply]">[$XFA_FailedReply]</a><br>
