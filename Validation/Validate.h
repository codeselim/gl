
class Validate {

protected:
	Document *xml;
	Dtd *dtd;

public:

	Validate(Document *xmlFile, Dtdt *dtdFile);
	bool isValid();

};