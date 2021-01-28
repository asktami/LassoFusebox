
<?LassoScript 
/*
<fusedoc fuse="dsp_MessageDetail
   <responsibilities>
      I show the user the details of a message.  If the user wants to reply
      to a message then I will execute XFA_Reply.
   </responsibilities>
   <note>
   </note>
   <note>
      Data Rules: XFA_Reply - 
      Data Rules: authorEmail - EmailAddress, 
      Data Rules: authorName - Can Not Be Blank, 
      Data Rules: fuseaction - 
      Data Rules: messageBody - Max Length 5000, Can Not Be Blank, 
      Data Rules: messageID - All Numbers, 
      Data Rules: subject - Can Not Be Blank, 
   </note>
   <io>
   
      <in>
         <String name="self" optional="false" />
         <String name="XFA_Reply"  optional="false" scope="request"/>
         <Numeric name="messageID"  optional="false" scope="request"/>
         <String name="subject"  optional="false" scope="request"/>
         <String name="messageBody"  optional="false" scope="request"/>
         <String name="authorName"  optional="false" scope="request"/>
         <String name="authorEmail"  optional="false" scope="request"/>
      </in>
      
      <out>
         <String name="fuseaction"  optional="true" scope="request"/>
         <Numeric name="messageID"  optional="false" scope="request"/>
      </out>
      
      <passthrough>
      </passthrough>
      
   </io>
</fusedoc>
*/ 
?>
<br><br>dsp_MessageDetail<br>
&nbsp;&nbsp;&nbsp;<a href="[LassoApp_Link:($self)]?fuseaction=[$XFA_Reply]">[$XFA_Reply]</a><br>
