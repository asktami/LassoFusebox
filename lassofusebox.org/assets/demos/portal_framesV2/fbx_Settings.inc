<?LassoScript
/*
<fusedoc fuse="fbx_Settings.inc" language="Lasso" specification="3.0">
	<responsibilities>
		I set up the enviroment settings for this circuit. If this settings file is being inherited, then you can use VARIABLE to override
		a value set in a parent circuit or FBX_PARAM to accept a value set by a parent circuit
	</responsibilities>	
	<properties>
		<history author="Rich Tretola" email="rich@lassofusebox.org" date="10/07/2002" type="Create">
		<history author="Tami Williams" date="May 2003" email="tami@asktami.com" type="Update" />
		<history author="Tami Williams" date="05/23/08" email="tami@asktami.com" type="Update" />
	</properties>
	<io>
		<in>
			<structure name="fusebox">
				<boolean name="isRootCircuit" comments="Is the circuit currently executing the root circuit?" />
			</structure>
		</in>
		<out>
			<string name="self" scope="variables" />
			<string name="fuseaction" scope="variables" />
			<string name="selfURL" scope="variables" />
			<string name="frame" scope="variables" />
		</out>
	</io>
</fusedoc>
*/


FBX_Param: -Name='self', -Default='index.lasso?'+ (noCache) + '&frame=' + $frame + '&fuseaction=' ;


// must use the full URL, this var will be called with selfURL
If: $appLocation == 'lassofusebox' ;
// live site (default)

FBX_Param: -Name='selfURL', -Default='http://www.lassofusebox.org/test/portal_framesV2/index.lasso?'+ (noCache) + '&frame=' + $frame + '&fuseaction=' ;


else: $appLocation == 'asktami' ;
// test site

FBX_Param: -Name='selfURL', -Default='http://www.asktami.com/portal_framesV2/index.lasso?'+ (noCache) + '&frame=' + $frame + '&fuseaction=' ;

else: $appLocation == 'local' ;
// local hard drive

FBX_Param: -Name='selfURL', -Default='http://127.0.0.1/portal_framesV2/index.lasso?'+ (noCache) + '&frame=' + $frame + '&fuseaction=' ;

/if;



// default background color, overriden in child fbx_Switch.inc files by var:'bgcolor'
FBX_Param: -Name='bgcolor', -Default='white' ;


			FBX_Param: -Name='XFA_home', -Default=$self +'home.welcome' ;
			FBX_Param: -Name='XFA_tutorials', -Default=$self +'home.tutorials' ;
			FBX_Param: -Name='XFA_essays', -Default=$self +'main.essays' ;
			FBX_Param: -Name='XFA_hire_me', -Default=$self +'home.hire_me' ;
			
			
			FBX_Param: -Name='XFA_one', -Default=$self +'news.one' ;
			FBX_Param: -Name='XFA_two', -Default=$self +'news.two' ;
			FBX_Param: -Name='XFA_three', -Default=$self +'news.three' ;
			
			
			FBX_Param: -Name='XFA_help', -Default=$self +'utilities.help' ;
			FBX_Param: -Name='XFA_credits', -Default=$self +'utilities.credits' ;
			FBX_Param: -Name='XFA_contact_me', -Default=$self +'utilities.contact_me' ;
	
?>