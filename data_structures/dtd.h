/* DTD */
#include <map>

using namespace std;

enum Card {qmark, plus, star};

typedef map<string, DtdElt> DtdEltMap;

class Dtd {
	DtdEltMap* elements;
};