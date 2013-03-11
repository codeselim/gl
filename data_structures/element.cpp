

class Element : Node {
    list<Node*> * children;
    map<string, string> * attributes;
    string namespace;
    string name;

    public:
        Element(ElementName* en, map<string, string>* attrs, list<Node*> * children = new list<Node>());
};