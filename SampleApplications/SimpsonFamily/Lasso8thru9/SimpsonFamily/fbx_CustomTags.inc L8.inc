﻿[

/*
<fusedoc fuse="fbx_CustomTags.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I hold the user defined custom tags used within the application. There should be only one fbx_CustomTags.inc file within the application and it should reside within the root folder.
	</responsibilities>	
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create" />
		<history author="Tami Williams" date="May 2008" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="4/5/2012" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
*/


var(
'myparams' = (action_params),
'myclientparams' = (client_postparams)
);

//


/*----------------------------------------------------------------------------
[lp_client_isBot]
Returns true if client is a bot, spider, validator, robot or crawler.

Author: Bil Corry
Last Modified: May. 03, 2006
License: Public Domain

Description:
Returns true if client is a bot, spider, validator, robot or crawler.  It's 
based on user-agent, so it won't identify any bot that doesn't identify itself 
via the user-agent.


Sample Usage:
if: lp_client_isBot;
'Hello automated friend!';
/if;


Downloaded from tagSwap.net on Jun. 27, 2007.
Latest version available from <http://tagSwap.net/lp_client_isBot>.

----------------------------------------------------------------------------
*/
		
define_tag('lp_client_isBot',
	-description='Returns true if client is a bot, spider, validator, robot or crawler.',
	-priority='replace',
	-optional='user_agent');

	// based on a tag from Fletcher Sandbeck

	// http://www.pgts.com.au/pgtsj/pgtsj0212d.html

	if(local_defined('user_agent'));
		local('client_browser' = #user_agent);
	else;
		local('client_browser' = client_browser);
	/if;

	local('bots' = array(
						'bot',
						'slurp',
						'crawler',
						'spider',
						'search',
						'checker',
						'creep',
						'robo',
						'worm',
						'leech',
						'validator',
						'siphon',
						'index',
						'Mediapartners-Google',
						'LinksManager',
						'ia_archiver',
						'Jeeves',
						'AvantGo',
						'ASPseek',
						'Appie',
						'Findlinks',
						'Httpget',
						'Grub',
						'Infoseek',
						'Larbin',
						'Scooter',
						'Scrubby',
						'Xenu',
						'wGet',
						'Sitecheck',
						'URL Control',
						'Knowledge',
						'InternetLinkAgent',
						'IlTrovatore',
						'LinkLint',
						'Internet Publishing Provider',
						'java',
						'php',
						'perl',
						'python',
						'lasso',
						'curl',
						'feed')
						);

	iterate(#bots, local('bot'));
    	if(#client_browser->contains(#bot));
			return(true);
		/if;
	/iterate;

	return(false);

/define_tag;


//


// FirstUpper Custom Tag v2
// Author Tami Williams (modified the "FirstUpper Custom Tag v1" tag created by Duncan Cameron obtained from www.lassoscripts.com)
// URL http://www.asktami.com/
// for Lasso Professional 6 & 7 & 8

// Examples:
// [FirstUpper('string')]
// [FirstUpper(Field('this_field'))]
// [FirstUpper(Action_Param('this_field'))]
// [FirstUpper($variable)]

/*
The FirstUpper Custom Tag allows a string to be passed and have the string converted so that the first letter of the first word is in uppercase and the remainder of the string in lowercase.  It does not modify the existing variable if a variable is passed to the tag.

Input: [FirstUpper('make it so')]
Output: Make it so

Input: [FirstUpper('make_It SO')]
Output: Make it so
*/

if(!lasso_tagexists('FirstUpper'));
Define_Tag('FirstUpper', -Required = 'XSentence',  -Priority='Replace');
Local('Sentence' = string(#XSentence) );
Local('Temp' = String_Replace(#Sentence, -Find=' ', -Replace=''));

// replace all underscores with spaces
#Sentence =String_Replace(#Sentence, -Find='_', -Replace=' ');

if(!#Temp);
	Return(#Temp);
	
else;
	(#Sentence)->Trim;
	
	local('FirstLetter' = @(#Sentence)->Get(1));
	
	#Sentence = String_Uppercase(#FirstLetter) +  String_Lowercase(String_Remove((#Sentence), -StartPosition=1, -EndPosition=1) );
	
	Return(#Sentence);
/if;
	
/Define_Tag;
/if;


//


// ShowClientParams Custom Tag v1
// Author Tami Williams
// URL http://www.asktami.com/
// for Lasso Professional 6 & 7 & 8

// Inside an Inline use:  [ShowClientParams((client_postparams) )]
// Outside an inline use: [ShowClientParams]

if(!lasso_tagexists('ShowClientParams'));
Define_Tag('ShowClientParams', -Optional='TheParamsX', -priority='Replace');
local('Output' = (array) );

if(Params->size == 0);
local('TheParams' = @($myclientparams));
else;
local('TheParams' = Params->Get(1) );
/if;

#Output =  '<b>ShowClientParams - Form Entries:</b>' ;

	iterate(#TheParams, local('temp'));
	#Output +=  '<br>' + (#temp->first) + ' = ' + (#temp->second);
	/iterate;

return(@#Output);
/Define_Tag;
/if;


//


// ShowVars Custom Tag v1
// Author Tami Williams
// URL http://www.asktami.com/
//	for Lasso Professional 6 & 7 & 8

// Example:  [ShowVars]

if(!lasso_tagexists('ShowVars'));
Define_Tag('ShowVars', -Optional='TheVars', -priority='Replace');
local('Output' = (string) );

if(Params->size == 0);
local('TheVars' = variables);
/if;
 

#Output +=  '<b>ShowVars:</b>' ;

loop((#TheVars)->size);
if(! (#TheVars)->get(loop_count)->first->BeginsWith('_' )  &&   ! (#TheVars)->get(loop_count)->first->BeginsWith('myparams' )  &&  ! (#TheVars)->get(loop_count)->first->BeginsWith('myclientparams' )  &&  ! (#TheVars)->get(loop_count)->first->BeginsWith('variables'));
#Output +=  '<br>' +  (#TheVars)->get(loop_count)->first + '  = ' + (#TheVars)->get(loop_count)-> second;
/if;
/loop;

return(@#Output);
/Define_Tag;
/if;


//


/*
// tw_Debug Custom Tag v1
// Author Tami Williams
// URL http://www.asktami.com/
// for Lasso Professional 6 & 7 & 8
// Uses: 
// so I can go back and BBEdit grep find '\[tw_Debug: (.*)\] to remove all debug vars when testing is done
[tw_Debug(var('x'), 'x')]
<br>
tw_Debug y<br>
[tw_Debug(var('y'), 'y')]
*/

if( !(lasso_tagexists('tw_Debug')));
define_tag('tw_Debug', 
    -priority='replace', 
    -required='val',
    -optional='label',
    -type='string'); 
 
if(Params->size == 1);
local('label' = #val ' = ');
else;
local('label' = #label ' = ');
/if;

    local('result'=''); 
        #result +='<code style="background: #CFECEC; color:maroon;padding:2px;display:inline">&nbsp;'; 
        #result += #label #val; 
        #result +='&nbsp;</code>'; 
     
    return(@#result); 
 
/define_tag;
/if;

 
 //


/*
************************************************
 FOR LASSO 8
************************************************
*/
//
// tw_ShowActionParams Custom Tag v2
// Author Tami Williams
// URL http://www.asktami.com/
// for Lasso Professional 6 & 7 & 8

// Inside an Inline use:  [tw_ShowActionParams(action_params) ]
// Outside an inline use: [tw_ShowActionParams]
// used in _common/dsp_debug.inc and dsp_debuginline.inc


if(!(lasso_tagexists('tw_ShowActionParams')) );
Define_Tag('tw_ShowActionParams', -Optional='TheParamsX', -priority='Replace');

local('Output' = array) ;

if(Params->(size) == 0 );
local('TheParams' = @($myparams));
else;
local('TheParams' = Params->Get(1)) ;
/if;

#Output =  '<b>tw_ShowActionParams:</b>' ;

iterate(#TheParams, local('temp'));
#Output +=  '<br>' + (#temp->first) + ' = ' + encode_html(#temp->second);
/iterate;

return(@#Output);

/Define_Tag;
/if;


//


// tw_TitleCase Custom Tag v2
// Author Tami Williams
// URL http://www.asktami.com/
// for Lasso Professional 6 & 7 & 8 & 9

// Examples:
// [tw_TitleCase('string')]
// [tw_TitleCase(Field('this_field'))]
// [tw_TitleCase(Action_Param('this_field'))]
// [tw_TitleCase($variable)]

/*	
The tw_TitleCase Custom Tag allows a string to be passed and have the string converted so that the first letter of every word is in uppercase and all the other letters of every word are in lowercase. It does not modify the existing variable if a variable is passed to the tag.

Input: [tw_TitleCase('make it so')]
Output: Make It So

Input: [tw_TitleCase('make_It SO')]
Output: Make It So
*/

if( !lasso_tagexists('tw_TitleCase') );
Define_Tag('tw_TitleCase', -Required = 'XSentence',  -Priority='Replace');

// if just use reference and not string + reference the Sentence var doesn't work!

Local(
'Sentence' = string(#XSentence),
'Output' = (string)
);

Local('Temp' = String_Replace(#Sentence, -Find=' ', -Replace='' ));

if(!#Temp);
	Return(encode_html(#Temp));	
else;

#Sentence->Trim;
#Sentence = (#Sentence)->split('_');

local('WordArray' = array);
//	create array of words in page title by splitting file name on all the  '_' and ' '
local('Fragment' = '');
iterate(#Sentence, #Fragment);
#WordArray->(merge(#Fragment->split(' '))) ;
/iterate;

loop(#WordArray->size);

			local('Word' = @(#WordArray->get(loop_count)));
			//	word for this iteration
			
			local('wordLength' = #Word->length);
			//	length of the word for this iteration
			
			if(#Word->Size > 1);
				#Word = string_uppercase(#Word)->substring(1,1) + string_lowercase(#Word)->substring(2, #wordLength);
			else;
				#Word = string_uppercase(#Word)->substring(1,1) + string_lowercase(#Word)->substring(1, #wordLength);
			/if;
			//	capitalize first letter of word and concatenate the remaing letters
			
			#Output += #Word;
			
			if(loop_count != #WordArray->size);
				#Output = #Output + ' ' ;
				//	add a space between words
			/if;
			
/loop;

return(encode_html(#Output));
/if;
/Define_Tag;
/if;

]