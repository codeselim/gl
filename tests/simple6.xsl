<?xml version="1.0"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="xml">
<html>
<body>
	<xsl:apply-templates />
</body>
</html>
</xsl:template>

<xsl:template match="a">
	<bleh>
		<xsl:apply-templates/>
	</bleh>
</xsl:template>

<xsl:template match="b">
	<howto>
		<xsl:apply-templates/>
	</howto>
</xsl:template>

<xsl:template match="c">
	<span a="o" u="b" d="l">
		<xsl:apply-templates/>
	</span>
</xsl:template>


</xsl:stylesheet>