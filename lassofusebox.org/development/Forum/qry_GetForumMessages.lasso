
<?LassoScript 
/*
<fusedoc fuse="qry_GetForumMessages
   <responsibilities>
      Runs a query to retrieve the list of messages in a particular forum.
   </responsibilities>
   <note>
   </note>
   <note>
      Data Rules: forumID - 
      Data Rules: messageList - 
   </note>
   <io>
   
      <in>
         <String name="self" optional="false" />
         <Numeric name="forumID"  optional="false" scope="request"/>
      </in>
      
      <out>
         <Recordset name="messageList"  optional="true" scope="request"/>
            <Numeric name="messageID"  optional="true" />
            <String name="authorName"  optional="true" />
            <String name="authorEmail"  optional="true" />
            <String name="subject"  optional="true" />
            <String name="messageBody"  optional="true" />
         </Recordset>
      </out>
      
      <passthrough>
      </passthrough>
      
   </io>
</fusedoc>
*/ 
?>
<br><br>qry_GetForumMessages<br>
