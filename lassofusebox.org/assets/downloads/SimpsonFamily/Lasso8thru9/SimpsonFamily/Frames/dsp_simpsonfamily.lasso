<table>
<tr>
	<td width="400">
The following example was originally written by Steve Nelson of <a href="http://www.secretagents.com" target="_blank">Secretagents.com</a> and is an open source sample available at <a href="http://www.Fusebox.org" target="_blank">Fusebox.org</a>.  
It was ported to <a href="http://www.lassofusebox.org" target="_blank">LassoFusebox</a> by <a href="mailto:rich@lassofusebox.org?subject=Lasso Fusebox Simpsons Nested Circuits Example">Rich Tretola</a>, the lastest version (last modified 05/23/2008) by <a href="mailto:lassofusebox@asktami.com?subject=Lasso Fusebox Simpsons Nested Circuits Example">Tami Williams</a>.
<p>
Fusebox 3.0 offers the very powerful ability to "nest" circuits. What this means is that when you call one circuit
it can obtain both variables an layouts from it's parent circuits. In this example code we're going to look at how  to nest layouts using the Simpson Family as our metaphor. We'll look at how variables are affected by nesting in another example.
<p> I have attempted to simplify this example as much as possible. There are a LOT of directories in this example. Don't get overwhelmed, each
one is basically the same thing with a different Simpson family member.
<br>
<br>
Each directory also has it's own "/images" directory This is a very powerful concept of Fusebox 3.0. &lt;img&gt; tags will remain in tact when dragging and dropping one circuit under another. Be sure to look at how images are called in this example.
<br>
<br>
When going through this code, start at the top circuit and look at the fbx_circuits.lasso file. fbx_circuits.lasso will give you a map of all the circuits in the application. Next, walk  through each circuit and look at the fbx_switch.lasso file. fbx_switch.lasso will give you a map of all the fuseactions  in that circuit.
<br>
<br>
Next, look at the fbx_layouts.lasso file in each circuit. fbx_layouts.lasso gives you a map of all the layouts in that circuit.
<br>
<br>
Finally, there are two user defined fuses in each circuit: [noprocess]<br> lay_[name].lasso<br> and<br> dsp_[name].lasso
<br>
<br>
Look at those two files to see how the nesting works. The important variable to understand is the [$layout] variable. It is in each of the lay_[name].lasso files.[/noprocess]
</p>
</td>
</tr>
</table>