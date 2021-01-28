[Var: 'subject' = 'New! LassoFusebox Core Files']
[Var: 'body' = 'New core files have now been uploaded at the www.lassofusebox.org site. There are several updates and enhancements:

- Converted main "fbx_fusebox30_LP6.lasso" to LassoScript to increase execution speed.

- Updated all core files to support the creation of LassoApps from a Fusebox 3 app. Simply use the [LassoApp_Link] command in all includes, redirects, links and form actions. Application can then be either run normally or converted to a LassoApp.

- Added a new framework core file named "fbx_Sessions.lasso". Use this file to initialize and open sessions. The file should exist only once within the application and be placed within the root folder.

- A new tag named [FBX_Redirect] has been added to the "fbx_Library.lasso" file. Use of this tag for redirects allows session keys to be passed with the redirect. Examples:

  To redirect when using cookies to pass session keys:
  [FBX_Redirect:\'somewhere.lasso\']
  
  To redirect when using links to pass session keys:
  [FBX_Redirect:\'somewhere.lasso\', -UseLink]
  
  To enable redirects and creation of a LassoApp add the LassoApp_Link command:
  [FBX_Redirect:(LassoApp_Link:\'somewhere.lasso\')]
  
  Original code and concept courtesy of Bil Corry.
  
- The file "URL_Redirect.lasso" has been deprecated. Use the [FBX_Redirect] tag instead.

I have also posted samples of the ContactApp and the Mail Form running as LassoApps.

Regards,
Michael S. McKellip
']


	[Email_Send: -Host='mail.pointinspace.com',
		-To='michael@lassofusebox.org',
		-From='rich@lassofusebox.org',
		-Subject=($subject),
		-Body=($body)]
