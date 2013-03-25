<?xml version="1.0"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="xml">
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<body>
	<xsl:apply-templates />
</body>
</html>
</xsl:template>

<xsl:template match="a">
	<div id="page">
		<xsl:apply-templates/>
	</div>
</xsl:template>

<xsl:template match="b">
	<p>
		<xsl:apply-templates/>
	</p>
</xsl:template>

<xsl:template match="c">
	<strong>
		<xsl:apply-templates/>
	</strong>
</xsl:template>

</xsl:stylesheet>