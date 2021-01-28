
<?LassoScript 
/*
<fusedoc fuse="qry_InsertMessage
   <responsibilities>
      I run an insert statement to save the users posting to the database.
   </responsibilities>
   <note>
   </note>
   <note>
      Data Rules: authorEmail - EmailAddress, 
      Data Rules: authorName - Can Not Be Blank, 
      Data Rules: messageBody - Max Length 5000, Can Not Be Blank, 
      Data Rules: messageList - 
      Data Rules: subject - Can Not Be Blank, 
   </note>
   <io>
   
      <in>
         <String name="self" optional="false" />
         <String name="authorName"  optional="false" scope="request"/>
         <String name="messageBody"  optional="false" scope="request"/>
         <String name="authorEmail"  optional="true" scope="request"/>
         <Recordset name="messageList"  optional="false" scope="request"/>
            <Numeric name="messageID"  optional="true" />
            <String name="authorName"  optional="false" />
            <String name="authorEmail"  optional="true" />
            <String name="subject"  optional="false" />
            <String name="messageBody"  optional="false" />
         </Recordset>
         <String name="subject"  optional="false" scope="request"/>
      </in>
      
      <out>
      </out>
      
      <passthrough>
      </passthrough>
      
   </io>
</fusedoc>
*/ 
?>
<br><br>qry_InsertMessage<br>
