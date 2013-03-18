#ifndef __ENUMS_H__
#define __ENUMS_H__

enum Type {T_CDATA, ID, IDREF, IDREFS, NMTOKEN, NMTOKENS, ENTITY, ENTITIES, NOTATION, _ENUM};
enum Card {NONE, QMARK, C_PLUS, STAR};
enum ListType {CHOICE, SEQ};
enum EltType {TOKEN, T_PCDATA};
enum EltContentType {T_ANY, T_EMPTY, LIST};

#endif