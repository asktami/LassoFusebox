[output_none]
<fusedoc fuse="dsp_valError.inc" language="Lasso" specification="3.0">
	<responsibilities>I display form validation error messages. There should be only one dsp_valError.inc file within the application and it should reside within the _common folder.</responsibilities>
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create" />
		<history author="Tami Williams" date="05/08/2008" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
[/output_none]


<center>
[Encode_Set: -EncodeNone]
[if: $isValid == 'No']
<span class="red"><strong>An error has occurred. Please enter the required information and submit again.</strong></span>
<span class="messagefont">
		[local:'x' = '']
		[iterate: $valError, #x ]
		<br />	[if: $valError->Type == 'map']
			   			[#x->second]
			  		 [else]
			   			[#x]
			   		[/if]
		  [/iterate]
	</span>
[/if]
[/Encode_Set]
</center>