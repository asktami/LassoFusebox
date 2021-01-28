[Session_Start: -Name='LFB3', -Expires=1440, -UseCookie]
[Session_AddVariable: -Name='LFB3', 'Session_ID']
[Session_AddVariable: -Name='LFB3', 'Session_FirstName']

[FBX_Param: -Name='Session_ID', -Default=0]
[FBX_Param: -Name='Session_FirstName', -Default='']
[FBX_Param: -Name='isLoggedIn', -Default=false]

[If:($Session_ID) > 0]
	[$isLoggedIn = true]
[/If]