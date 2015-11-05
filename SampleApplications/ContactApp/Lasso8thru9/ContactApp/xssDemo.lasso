[

var('search') = (action_param('search'));

if($search->size);
	'You searched for: ';
	if(action_param('protect')->size);
		encode_html($search);
	else;
		$search;
	/if;
	'<hr>';
/if;

]

<form>
Search for: <input type="text" name="search"> Try &lt;script&gt;alert(&#39;pwned!&#39;)&lt;/script&gt;<br>
<br>
Protect against attack? <input type="checkbox" name="protect" value="protect">
<br>
<br>
<input type="submit" value="submit" name="submit">
</form>

<em>original cross-site scripting attack example from Bill Corry at the 2008 Lasso Developer Conference</em>
