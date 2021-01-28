
<?LassoScript 
/*
<fusedoc fuse="qry_GetForumList
   <responsibilities>
      I query the database and returns a list of available forums.
   </responsibilities>
   <note>
   </note>
   <note>
      Data Rules: forumList - 
   </note>
   <io>
   
      <in>
         <String name="self" optional="false" />
      </in>
      
      <out>
         <Struct name="forumList"  optional="true" scope="request"/>
            <Numeric name="forumID"  optional="true" />
            <String name="forumName"  optional="true" />
            <String name="description"  optional="true" />
         </Struct>
      </out>
      
      <passthrough>
      </passthrough>
      
   </io>
</fusedoc>
*/ 
?>
<br><br>qry_GetForumList<br>
