[

// a custom tag to get the real server name from the headers from greg willits
// use because the [server_name] tag sometimes has problems with multiple virtual hosts on the same IP
// Example: [thisServerName]

if( !(lasso_tagexists('getServerNameXXX')) );
define_tag('getServerNameXXX');
local('host'=string_findregexp(client_headers,-find='(.*)HOST(.*)',-ignorecase)->get(3));
local('subHost'=#host->split('.')->get(2));
	#host->trim;
	#subHost->trim;
return(string(#subHost));
/define_tag;
/if;

	
//

// this protects against malicious site Cross-Site Request Forgery Attack (CSRF)
if(string(referrer_URL) != ''  &&  !(string(referrer_URL)->Contains(getServerNameXXX)) );
output('<br>Invalid Access!');
abort;
/if;
]

got here - test servername not invalid

<br>
[getServerNameXXX]
<br>
[string(referrer_URL)->Contains(getServerNameXXX)]
<br>
[var('x' = string_findregexp(client_headers,-find='(.*)HOST(.*)',-ignorecase)->get(3))]
<br><br>
[$x->split('.')]