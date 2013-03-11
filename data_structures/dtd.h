#ifndef __DTD_H_

#define __DTD_H_

/* DTD */
#include <map>

using namespace std;

enum Card {qmark, plus, star};

typedef map<string, DtdElt> DtdEltMap;

class Dtd {
	DtdEltMap* elements;
};

#endif
