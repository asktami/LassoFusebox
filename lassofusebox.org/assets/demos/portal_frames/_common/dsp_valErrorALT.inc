[output_none]
<fusedoc fuse="dsp_valErrorALT.inc" language="Lasso" specification="3.0">
	<responsibilities>I display a generic form validation error message. There should be only one dsp_valErrorALT.inc file within the application and it should reside within the _common folder.</responsibilities>
	<properties>
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Create" />
		<history author="Tami Williams" date="05/08/2008" email="tami@asktami.com" type="Update" />
	</properties>
</fusedoc>
[/output_none]




[if: (var:'isValid') == 'No']
<span class="red"><strong>An error has occurred. Please enter the required information (with the red bullets) below and submit again.</strong></span>
[/if]