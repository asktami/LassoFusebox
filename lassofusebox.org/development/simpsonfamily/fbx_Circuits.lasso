[Lasso_Comment]
<fusedoc fuse="FBX_Circuits.lasso">
	<responsibilities>
		I define the Circuits structure used with Fusebox 3.0
	</responsibilities>	
	<io>
		<out>
			<string name="fusebox.circuits.*" comments="set a variable for each circuit name" />
		</out>
	</io>
</fusedoc>
[/Lasso_Comment]

[$_Circuits->(Insert:'SimpsonFamily'='SimpsonFamily')]
[$_Circuits->(Insert:'Grandpa'='Simpsonfamily/Grandpa')]
[$_Circuits->(Insert:'Homer'='Simpsonfamily/Grandpa/Homer')]
[$_Circuits->(Insert:'Bart'='Simpsonfamily/Grandpa/Homer/Bart')]
[$_Circuits->(Insert:'Marge'='Simpsonfamily/Grandpa/Marge')]
[$_Circuits->(Insert:'Lisa'='Simpsonfamily/Grandpa/Marge/Lisa')]
[$_Circuits->(Insert:'Maggie'='Simpsonfamily/Grandpa/Marge/Maggie')]
