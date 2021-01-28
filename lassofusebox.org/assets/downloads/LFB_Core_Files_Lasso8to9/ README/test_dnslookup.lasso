<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Test ServerName</title>
</head>

<body>
[

if(!(var('gServerNameXXX')));
   if(dns_lookup(server_ip) == array) ;
   // this is to handle local testing on Tami's server
   var('gServerNameXXX' = 'local');
   else;
   var('gServerNameXXX' = dns_lookup(server_ip)->get(1)); // Be nice to the DNS server and only do this once
   /if;
/If;
]

ServerName: [var('gServerNameXXX')]

</body>
</html>
