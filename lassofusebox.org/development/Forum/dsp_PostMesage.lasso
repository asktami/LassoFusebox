
<?LassoScript 
/*
<fusedoc fuse="dsp_PostMesage
   <responsibilities>
      I show the user a form that can be used to post a new message or reply
      to an existing one.
   </responsibilities>
   <note>
   </note>
   <note>
      Data Rules: XFA_Post - 
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
         <String name="XFA_Post"  optional="false" scope="request"/>
         <String name="authorEmail"  optional="true" scope="request"/>
         <String name="authorName"  optional="true" scope="request"/>
         <String name="messageBody"  optional="true" scope="request"/>
         <Numeric name="messageID"  optional="true" scope="request"/>
         <String name="subject"  optional="true" scope="request"/>
      </in>
      
      <out>
         <String name="fuseaction"  optional="true" scope="request"/>
         <String name="authorEmail"  optional="true" scope="request"/>
         <String name="authorName"  optional="true" scope="request"/>
         <String name="messageBody"  optional="true" scope="request"/>
         <Numeric name="messageID"  optional="true" scope="request"/>
         <String name="subject"  optional="true" scope="request"/>
      </out>
      
      <passthrough>
      </passthrough>
      
   </io>
</fusedoc>
*/ 
?>
<br><br>dsp_PostMesage<br>
&nbsp;&nbsp;&nbsp;<a href="[LassoApp_Link:($self)]?fuseaction=[$XFA_Post]">[$XFA_Post]</a><br>
