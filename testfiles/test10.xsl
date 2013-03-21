<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="helloworld">
	<HTML>
		<HEAD>
			<TITLE></TITLE>
		</HEAD>
		<BODY>
			<xsl:apply-templates />
		</BODY>
	</HTML>
</xsl:template>
</xsl:stylesheet>
