
<?LassoScript 
/*
<fusedoc fuse="dsp_MessageList
   <responsibilities>
      I show the user list of messages and allow them to drill down on a
      particular message by clicking on it.  I also let the user post a new message.
   </responsibilities>
   <note>
      
      Requirement: Message Per Page - All messages listed
      For simplicity sake, when a user clicks on a particular forum, all of
      the message in that forum will be displayed.  

In future releases, we
      may choose to implement a record scrolling mechanism.
   </note>
   <note>
      Data Rules: XFA_PostMessage - 
      Data Rules: XFA_ViewMessage - 
      Data Rules: fuseaction - 
      Data Rules: messageID - All Numbers, 
   </note>
   <io>
   
      <in>
         <String name="self" optional="false" />
         <String name="XFA_PostMessage"  optional="false" scope="request"/>
         <String name="XFA_ViewMessage"  optional="false" scope="request"/>
      </in>
      
      <out>
         <String name="fuseaction"  optional="true" scope="request"/>
         <Numeric name="messageID"  optional="true" scope="request"/>
      </out>
      
      <passthrough>
      </passthrough>
      
   </io>
</fusedoc>
*/ 
?>
<br><br>dsp_MessageList<br>
&nbsp;&nbsp;&nbsp;<a href="[LassoApp_Link:($self)]?fuseaction=[$XFA_PostMessage]">[$XFA_PostMessage]</a><br>
&nbsp;&nbsp;&nbsp;<a href="[LassoApp_Link:($self)]?fuseaction=[$XFA_ViewMessage]">[$XFA_ViewMessage]</a><br>
