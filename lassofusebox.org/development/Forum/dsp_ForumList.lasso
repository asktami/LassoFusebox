
<?LassoScript 
/*
<fusedoc fuse="dsp_ForumList
   <responsibilities>
      I display a list of Forums that are available for the user to browse.
   </responsibilities>
   <note>
   </note>
   <note>
      Data Rules: XFA_ListMessages - 
      Data Rules: forumID - 
      Data Rules: fuseaction - 
   </note>
   <io>
   
      <in>
         <String name="self" optional="false" />
         <String name="XFA_ListMessages"  optional="false" scope="request"/>
      </in>
      
      <out>
         <String name="fuseaction"  optional="true" scope="request"/>
         <Numeric name="forumID"  optional="true" scope="request"/>
      </out>
      
      <passthrough>
      </passthrough>
      
   </io>
</fusedoc>
*/ 
?>
<br><br>dsp_ForumList<br>
&nbsp;&nbsp;&nbsp;<a href="[LassoApp_Link:($self)]?fuseaction=[$XFA_ListMessages]">[$XFA_ListMessages]</a><br>
