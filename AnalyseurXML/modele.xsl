<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="H4114">

<xsl:template match="/">
	<html>
	<body>
		<xsl:apply-templates/>
	</body>
	</html>
</xsl:template>
<xsl:template match="titre">
	<html>
	<font color="red">
		<xsl:apply-templates/>
	</font>
	</html>
</xsl:template>
<xsl:template match="auteur">
	<html>
	<font color="purple">
		<xsl:apply-templates/>
	</font>
	</html>
</xsl:template>
<xsl:template match="resume">
	<html>
	<font color="teal">
		<xsl:apply-templates/>
	</font>
	</html>
</xsl:template>
<xsl:template match="chapitre">
	<html>
	<font color="salmon">
		<xsl:apply-templates/>
	</font>
	</html>
</xsl:template>

</xsl:stylesheet>