#include "dom_document.hpp"
#include "dom_text.hpp"
#include "dom_attr.hpp"
#include "dom_element.hpp"
using namespace dom;

#define S(x) (const unsigned short* const)L##x

Document::Document()
: Element(S("#document"))
, m_oEncoding(S("utf-16"))
{
	m_eType=DOCUMENT_NODE;
}
Document::~Document() { }

NodePtr Document::createElement(const DOMString& name) {
	return constructNode(new Element(name));
}
NodePtr Document::createTextNode(const DOMString& data) {
	return constructNode(new Text(data));
}
NodePtr Document::createAttribute(const DOMString& name) {
	return constructNode(new Attr(name));
}
NodePtr Document::constructNode(Node* object) {
	if (object) {
		NodePtr domObject(object);
		domObject->_setSelf(domObject);
		domObject->_setOwnerDocument(ownerDocument());
		return domObject;
	}
	return NodePtr();
}

NodePtr Document::documentElement () const {
	return firstChild();
}
