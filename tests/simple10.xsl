
<?xml version="1.0"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="helloworld">
		<HTML>
			<HEAD>
				<TITLE> </TITLE>
			</HEAD>
			<BODY>
				<H1> </H1>
				<xsl:apply-templates/>
			</BODY>
		</HTML>
	</xsl:template>
	<xsl:template match="greeter">
		<DIV>from
			<I><xsl:apply-templates/></I>
		</DIV>
	</xsl:template>
</xsl:stylesheet>
