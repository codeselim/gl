<xsl:stylesheet>
	<xsl:template match="xml">
		<html>
			<body>
				<xsl:apply-templates />
			</body>
		</html>
</xsl:template>
	<xsl:template match="truc">
		<p>
			<xsl:apply-templates />
		</p>
</xsl:template>
</xsl:stylesheet>
