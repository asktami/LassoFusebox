<TITLE>LassoFusebox and Frames Example: FrameSet</TITLE>
<FRAMESET ROWS="120,*,120" FRAMESPACING="0" FRAMEBORDER="0">
	<FRAME SRC="[$self]main.banner" NAME="head" ID="head" FRAMEBORDER="0" SCROLLING="No">
	<FRAMESET COLS="150, *" FRAMESPACING="0" FRAMEBORDER="0">
        <FRAMESET ROWS="50%,50%" FRAMESPACING="0" FRAMEBORDER="0">
    		<FRAME NAME=nav SRC="[$self]main.menu" FRAMEBORDER="0" SCROLLING="No">
    		<FRAME NAME=nav SRC="[$self]news.menu" FRAMEBORDER="0" SCROLLING="No">
        </FRAMESET>
		<FRAME NAME=content SRC="[$self]main.welcome">
	</FRAMESET>
	<FRAME NAME=foot SRC="[$self]utilities.menu" FRAMEBORDER="0" SCROLLING="No">
</FRAMESET>