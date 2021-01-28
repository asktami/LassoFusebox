[
/*
<fusedoc fuse="fbx_Library.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I hold the default Fusebox custom tags. There should be only one fbx_Library.inc file and it should reside within the root folder.
	</responsibilities>	
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create" />
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/5/2012" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
*/


// a custom tag to get the real server name from the headers from greg willits
// use because the [server_name] tag sometimes has problems with multiple virtual hosts on the same IP
// Example: [getServerName]

if( !(lasso_tagexists('getServerName')) );
define_tag('getServerName');
local('host'=string_findregexp(client_headers,-find='(.*)HOST(.*)',ignorecase)->get(3));
local('subHost'=#host->split('.')->get(2));
	#host->trim;
	#subHost->trim;
return(string(#subHost));
/define_tag;
/if;


//



// Example: FBX_Param(-Name='self', -Default='index.lasso');
If(!(Lasso_TagExists('FBX_Param')) );
	Define_Tag('FBX_Param', -Required='Name', -Required='Default');
  		If(!(Variable_Defined(#Name)) || !(Variable(#Name)) );
  		Variable(#Name = #Default);
  		/If;
	/Define_Tag;
/If;


//


// FBX_Include
// a custom tag so I don't have to keep writing: 
// include($currentPath + #filename);
// Example: FBX_Include('filename');

if(!(lasso_tagexists('FBX_Include')) );
define_tag('FBX_Include', -required='filename');
local('includethis' =  include($currentPath + #filename));
return(@#includethis);
/define_tag;
/if;


//


// FBX_IncludeCommon
// a custom tag so I don't have to keep writing: 
// include( '_common/' + #filename);
// for including files from the application's root/_common folder
// Example: FBX_IncludeCommon('filename');

if(!(lasso_tagexists('FBX_IncludeCommon')) );
define_tag('FBX_IncludeCommon', -required='filename');
local('includethat' = include('_common/' + #filename));
return(@#includethat);
/define_tag;
/if;


//


// To defeat Safari's aggressive page caching:
// Used as follows:
// <a href="anotherpage.lasso?id=[var('id')]&amp;[noCache]">

Define_Tag('noCache',-Priority='Replace');
    return('r=' + string(Date_Format(Date,-Format='%H%M')) + string(Date->Millisecond) );
/Define_Tag;

]