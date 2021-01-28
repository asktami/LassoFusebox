
<?LassoScript 
/*
<fusedoc fuse="qry_GetMessage
   <responsibilities>
      I query the database to retrieve a specific message.  Instead of
      returning a RecordSet with one record, I return all of the colums as
      individual data elements.  
   </responsibilities>
   <note>
   </note>
   <note>
      Data Rules: authorEmail - EmailAddress, 
      Data Rules: authorName - Can Not Be Blank, 
      Data Rules: messageBody - Max Length 5000, Can Not Be Blank, 
      Data Rules: messageID - All Numbers, 
      Data Rules: postedDate - 
      Data Rules: subject - Can Not Be Blank, 
   </note>
   <io>
   
      <in>
         <String name="self" optional="false" />
         <Numeric name="messageID"  optional="false" scope="request"/>
      </in>
      
      <out>
         <String name="messageBody"  optional="true" scope="request"/>
         <String name="authorEmail"  optional="true" scope="request"/>
         <String name="authorName"  optional="true" scope="request"/>
         <Numeric name="messageID"  optional="false" scope="request"/>
         <String name="subject"  optional="true" scope="request"/>
         <Date/Time name="postedDate"  optional="true" scope="request"/>
      </out>
      
      <passthrough>
      </passthrough>
      
   </io>
</fusedoc>
*/ 
?>
<br><br>qry_GetMessage<br>
