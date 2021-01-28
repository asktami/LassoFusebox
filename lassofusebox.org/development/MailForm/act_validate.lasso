[Lasso_Comment]
<fusedoc fuse="act_validate.lasso" language="Lasso" specification="3.0">
	<responsibilities>I validate the form.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="02/06/2003" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<in>
			<String name="email" format="CFML" Scope="variables"/>
			<String name="subject" format="CFML" Scope="variables"/>
			<String name="message" format="CFML" Scope="variables"/>
		</in>
		<out>
			<boolean name="isValid" format="CFML" Scope="variables"/>
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]


[FBX_Param: -Name='isValid', -Default='NO']

[Var: 'Error' = (Array)]

[If: !(Valid_Email: ($email))]
	[$Error->(Insert: 'Email Address is not valid.')]
[/IF]

[IF: ($subject) == '']
	[$Error->(Insert: 'Subject is Required.')]
[/IF]

[IF: ($message) == '']
	[$Error->(Insert: 'Message is Required.')]
[/IF]

<table align="center">
[Iterate: $Error, (Variable: 'temp')]
	<tr>
		<td class="messagefont" align="center">[Output: $temp]</td>
	</tr>
[/Iterate] 


[IF: ($Error->(Size) == 0)]
	[Var: 'isValid' = 'YES']
[Else]
	<tr>
		<td class="bodycopy" align="center">Please use your back button and make the corrections.</td>
	</tr>
[/IF]
</table>