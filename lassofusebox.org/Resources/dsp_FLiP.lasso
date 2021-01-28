[Lasso_Comment]
<fusedoc fuse="dsp_FLiP.lasso" language="Lasso">
	<responsibilities>
		I display information about the Fusebox Lifecycle Process.
	</responsibilities>
	<properties>
		<history author="Rich Tretola" date="1/29/2003" email="rich@lassofusebox.org" type="create"></history>
	</properties>
	<io>
		<in>
			<String name="xfa_personas" format="CFML" Scope="variables"/>
			<String name="xfa_wireframes" format="CFML" Scope="variables"/>
			<String name="xfa_prototyping" format="CFML" Scope="variables"/>
			<String name="xfa_architecting" format="CFML" Scope="variables"/>
			<String name="xfa_fusecoding" format="CFML" Scope="variables"/>
			<String name="xfa_unittesting" format="CFML" Scope="variables"/>
		</in>
	</io>	
</fusedoc>
[/Lasso_Comment]

<h1>Fusebox Lifecycle Process (FLiP)</h1>

<TABLE cellpadding="0" cellspacing="0" border="0">
	<TR>
		<TD><H2>Compliments of <a href="http://www.fusebox.org" target="_blank">Fusebox.org</a></H2>
<P>The Fusebox Lifecycle Process (FLiP) is a process for developing web applications. FLiP grew out of some of the best practices employed by Hal Helms and other members of the Fusebox community in the early days of Fusebox. Although, as the name indicates, FLiP came from the Fusebox community, its use is not intrinsically part of a Fusebox application. In fact, the ideas found in FLiP may be successfully employed in non-Fusebox projects as well.</P>
<P>The fundamental idea behind FLiP is to use a process that is at all times closely tied to client feedback, and one which follows steps allowing inexpensive changes in the design, to steps where changes become progressively more expensive. The idea is to encourage change in the early stages, where it can be managed with the least expense possible.</P>
<P>It is also important to note that FLiP is designed for the technical aspects of the project, starting at a point when you are ready to begin building an application. For many simple web projects, FLiP may be sufficient from the start of the project. For more complex projects, other research techniques may be necessary to understand the business model before starting on the application development with FLiP.</P>
<P>The steps in FLiP are:</P>

<STRONG>1. Personas and Goals</STRONG>
<P>Who will use this software? Why will they use it? A persona is a precise description of the application's user. Instead of designing feature based software, we design goal based software. This process helps deliver software desired by the end user.<BR>
<a href="[$self][$xfa_personas]">Read More >></a></P>

<STRONG>2. Wireframe</STRONG>
<P>Wireframing is a way to quickly model the proposed actions that will be performed by the application. The result of wireframing is a clickable model of the application that doesn't look anything like the finished project, but gives the architect an idea of how the client will help the persona acheive their goals.<BR>
<a href="[$self][$xfa_wireframes]">Read More >></a></P>

<STRONG>3. Prototype / Front-End Development</STRONG>
<P>A FLiP prototype is a clickable model of the finished application with no backend behind it. Prototyping is the largest step in the FLiP cycle, generally taking up to 70% of the project's effort. The result of prototyping is something that looks exactly like the finished application, with functionality limited to the client side. The objective is to discover exactly what the client expects from the application, and how they want it to look. Often a tool such as DevNotes is used to facilitate communication with the client about the prototype.  DevNotes is a tool that will be available soon to Lasso developers.</P>
<P>Prototyping is typically done in plain HTML, though if an alternative front-end technology (such as Flash) is being used the prototype may be done using that technology. The finished prototype will become the application's user interface, so the traditional sense of a prototype being a minor, throw-away version is not the case. All the effort made in this step is used in the final application.<BR>
<a href="[$self][$xfa_prototyping]">Read More >></a></P>

<STRONG>4. Application Architecting</STRONG>
<P>Once the prototype is finished, the application architect constructs the application design or schema, identifying fuseactions and organizing them into circuits. Each fuseaction's behavior is broken down into a set of fuses, and the architect writes a Fusedoc and a test harness for each fuse to be produced. Once the design has been constructed, coding can begin. There are some fantastic tools and techniques to use during this step.<BR>
<a href="[$self][$xfa_architecting]">Read More >></a></P>

<STRONG>5. FuseCoding</STRONG>
<P>Each coder employed on the project is sent one or more fuses and their corresponding test harnesses. The coder writes each fuse according to its Fusedoc. By using the Fusebox framework, the coder's work does not rely on the rest of the application. Each fuse can be coded and tested on its own, and can be plugged into the rest of the application. This step can be accomplished by one coder or many coders.<BR>
<a href="[$self][$xfa_fusecoding]">Read More >></a></P>

<STRONG>6. Unit Testing</STRONG>
<P>As each fuse is coded, it is unit tested against its test harness. This gives the coder a way to ensure the correct behavior is produced by the fuse, without being in constant contact with the architect. It also allows the architect to employ any number of coders, none of whom need to know anything about the project as a whole in order to successfully contribute to it. However, if the development team is tightly-knit or consists of only one person, unit testing creates an elegant quality control system for the basic building blocks of the application, ensuring reliability of the entire project.<BR>
<a href="[$self][$xfa_unittesting]">Read More >></a></P>

<STRONG>7. Application Integration</STRONG>
<P>As the fuses are completed, they are returned to the architect, who integrates them into the final application. Daily builds are employed, gradually transforming the prototype into a working application.</p>

<STRONG>8. Deployment</STRONG>
<P>Deployment is the least exciting phase of a FLiP project. Thanks to the high degree of communication between the client and architect, and the architect and coders, deployment day should hold no surprises for anyone.</p><BR>
						</TD>
					</TR>
				</TABLE>