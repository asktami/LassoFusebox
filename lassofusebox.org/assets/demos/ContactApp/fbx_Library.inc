<?LassoScript
encode_set: -encodenone;

/*
<fusedoc fuse="fbx_Library.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I hold the default Fusebox custom tags. There should be only one fbx_Library.inc file and it should reside within the root folder.
	</responsibilities>	
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create" />
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
*/


var:
'myparams' = (action_params),
'myclientparams' = (client_postparams);

//


// a custom tag to get the real server name from the headers from greg willits
// use because the [server_name] tag sometimes has problems with multiple virtual hosts on the same IP
// Example: [getServerName]

if: !(lasso_tagexists:'getServerName');
define_tag:'getServerName';
local:'host'=((string_findregexp:
		(client_headers),
		-find='(.*)HOST:(.*)',
		-ignorecase)->get:3);
	local:'subHost'=(#host->(split:'.')->(get:2));
	#host->trim;
	#subHost->trim;
return: (string: #subHost);
/define_tag;
/if;


//



// Example: FBX_Param: -Name='self', -Default='index.lasso' ;
If:!(Lasso_TagExists:'FBX_Param');
	Define_Tag: 'FBX_Param', -Required='Name', -Required='Default';
  		If: !(Variable_Defined: #Name) || !(Variable: #Name);
  		Variable: #Name = #Default;
  		/If;
	/Define_Tag;
/If;


//


// FBX_Include
// a custom tag so I don't have to keep writing: 
// include: $currentPath + #filename ;
// Example: FBX_Include: 'filename' ;

if: !(lasso_tagexists:'FBX_Include');
define_tag:'FBX_Include', -required='filename';
local:'includethis' =  include: $currentPath + #filename ;
return: @#includethis;
/define_tag;
/if;


//


// FBX_IncludeCommon
// a custom tag so I don't have to keep writing: 
// include:  '_common/' + #filename;
// for including files from the application's root/_common folder
// Example: FBX_IncludeCommon: 'filename' ;

if: !(lasso_tagexists:'FBX_IncludeCommon');
define_tag:'FBX_IncludeCommon', -required='filename';
local:'includethat' = include:  '_common/' + #filename;
return: @#includethat;
/define_tag;
/if;


//


// To defeat Safari's aggressive page caching:
// Used as follows:
// <a href="anotherpage.lasso?id=[var:'id']&amp;[noCache]">

Define_Tag:'noCache',-Priority='Replace';
    return:'r=' + (string:(Date_Format:(Date),-Format='%H%M')) +
(string:((Date)->Millisecond));
/Define_Tag;


//
// ShowActionParams Custom Tag v1
// Author Tami Williams
// URL http://www.asktami.com/
// for Lasso Professional 6 & 7 & 8

// Inside an Inline use:  [ShowActionParams: (action_params) ]
// Outside an inline use: [ShowActionParams]
// used in _common/dsp_debug.inc and dsp_debuginline.inc


if: !(lasso_tagexists:'ShowActionParams');
Define_Tag: 'ShowActionParams', -Optional='TheParamsX', -priority='Replace';

local: 'Output' = (array) ;

if: (Params->(size)) == 0;
local: 'TheParams' = @($myparams);
else;
local: 'TheParams' = (Params->(Get:1)) ;
/if;

#Output =  '<b>ShowActionParams:</b>' ;

iterate: (#TheParams), (local:'temp' );
#Output +=  '<br />' + (#temp->first) + ' = ' + encode_html:(#temp->second);
/iterate;

return: @#Output ;

/Define_Tag;
/if;


//


// TitleCase Custom Tag v1
// Author Tami Williams
// URL http://www.asktami.com/
// for Lasso Professional 6 & 7 & 8

// Examples:
// [TitleCase: 'string']
// [TitleCase: (Field: 'this_field')]
// [TitleCase: (Action_Param: 'this_field')]
// [TitleCase: $variable]

/*	
The TitleCase Custom Tag allows a string to be passed and have the string converted so that the first letter of every word is in uppercase and all the other letters of every word are in lowercase. It does not modify the existing variable if a variable is passed to the tag.

Input: [TitleCase: 'make it so']
Output: Make It So

Input: [TitleCase: 'make_It SO']
Output: Make It So
*/

if: !(lasso_tagexists:'TitleCase');
Define_Tag: 'TitleCase', -Required = 'XSentence',  -Priority='Replace';

// if just use reference and not string + reference the Sentence var doesn't work!

Local: 'Sentence' = (string: #XSentence) ,
'Output' = (string);

Local: 'Temp' = (String_Replace: #Sentence, -Find=' ', -Replace='' );

if: !#Temp;
	Return: encode_html:(#Temp);	
else;

(#Sentence)->Trim;
#Sentence = (#Sentence)->(split:'_');

local:'WordArray' = (array);
//	create array of words in page title by splitting file name on all the  '_' and ' '
local:'Fragment' = '' ;
iterate: #Sentence, #Fragment ;
#WordArray->(merge: (#Fragment)->(split:' ')  ) ;
/iterate;

loop:(#WordArray)->(size);

			local:'Word' = @( #WordArray->(get:(loop_count)) );
			//	word for this iteration
			
			local:'wordLength' = (#Word)->(length);
			//	length of the word for this iteration
			
			#Word = (string_uppercase:(#Word)->(substring:1,1)) + (string_lowercase: (#Word)->(substring:2,(#wordLength)) );
			//	capitalize first letter of word and concatenate the remaing letters
			
			#Output += #Word;
			
			if:(loop_count) != (#WordArray)->(size);
				#Output = #Output + ' ' ;
				//	add a space between words
			/if;
			
/loop;

return: encode_html:(#Output) ;
/if;
/Define_Tag;
/if;

/encode_set;
?>