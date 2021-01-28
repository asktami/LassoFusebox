[Lasso_Comment]
<fusedoc fuse="act_validate.lasso" language="Lasso" specification="3.0">
	<responsibilities>I validate the form.</responsibilities>
	<properties>
		<history author="Rich Tretola" date="10/07/2002" email="rich@lassofusebox.org" role="Architect" type="Create"/>
	</properties>
	<io>
		<in>
			<number name="ID" format="LDML" Scope="variables"/>
			<String name="Title" format="LDML" Scope="variables"/>
			<String name="First_Name" format="LDML" Scope="variables"/>
			<String name="Last_Name" format="LDML" Scope="variables"/>
			<String name="Company" format="LDML" Scope="variables"/>
			<String name="Phone_Number" format="LDML" Scope="variables"/>
			<String name="Sex" format="LDML" Scope="variables"/>
			<String name="Jobs" format="LDML" Scope="variables"/>
		</in>
		<out>
			<boolean name="isValid" format="LDML" Scope="variables"/>
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]

[FBX_Param: -Name='isValid', -Default='NO']

[Var: 'Error' = (Array)]

[IF: ($Title) == '']
	[$Error->(Insert: 'Title is Required.')]
[/IF]

[IF: ($First_Name) == '']
	[$Error->(Insert: 'First Name is Required.')]
[/IF]

[IF: ($Last_Name) == '']
	[$Error->(Insert: 'Last Name is Required.')]
[/IF]

[IF: ($Company) == '']
	[$Error->(Insert: 'Company is Required.')]
[/IF]

[IF: ($Phone_Number) == '']
	[$Error->(Insert: 'Phone Number is Required.')]
[/IF]

[IF: ($Sex) == '']
	[$Error->(Insert: 'Sex is Required.')]
[/IF]

[IF: ($Jobs) == '']
	[$Error->(Insert: 'Jobs is Required.')]
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