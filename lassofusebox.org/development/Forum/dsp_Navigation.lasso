
<?LassoScript 
/*
<fusedoc fuse="dsp_Navigation
   <responsibilities>
   </responsibilities>
   <note>
   </note>
   <note>
      Data Rules: XFA_ListForums - 
      Data Rules: XFA_ListMessages - 
      Data Rules: fuseaction - 
   </note>
   <io>
   
      <in>
         <String name="self" optional="false" />
         <String name="XFA_ListForums"  optional="false" scope="request"/>
         <String name="XFA_ListMessages"  optional="false" scope="request"/>
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
<br><br>dsp_Navigation<br>
&nbsp;&nbsp;&nbsp;<a href="[LassoApp_Link:($self)]?fuseaction=[$XFA_ListForums]">[$XFA_ListForums]</a><br>
&nbsp;&nbsp;&nbsp;<a href="[LassoApp_Link:($self)]?fuseaction=[$XFA_ListMessages]">[$XFA_ListMessages]</a><br>
