#ifndef __ENUMS_H__
#define __ENUMS_H__

enum Type {T_CDATA, ID, IDREF, IDREFS, NMTOKEN, NMTOKENS, ENTITY, ENTITIES, NOTATION, _ENUM};
enum Card {NONE, QMARK, C_PLUS, STAR};
enum ListType {CHOICE, SEQ};
enum EltType {T_ANY, T_EMPTY, LIST, T_PCDATA, TOKEN};
enum SpecialNodeType { SNT_DOCTYPE, SNT_XML_VER, SNT_SPECIAL };

#endif
