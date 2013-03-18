#ifndef COMMUN_H
#define COMMUN_H

using namespace std;
#include <list>
#include <utility>
#include <string>
#include <exception>

typedef pair<string,string> Attribut;
typedef list<Attribut> AttList;
typedef pair<string,string> ElementName; // convention : name, namespace

#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif


struct NotYetImplementedException : std::exception {
	const char* what() {return "Not Yet Implemented.";}
};

#endif
