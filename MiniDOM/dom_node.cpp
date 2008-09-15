#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <vector>
#include "dom_node.hpp"
#include "dom_element.hpp"
#include "dom_utils.hpp"
using namespace dom;

Node::Node(const std::wstring& name, TNodeType type)
: m_eType(type)
, m_oName(name)
{
	// Try to deduce a prefix and a localname
	std::vector<std::wstring> nameParts;
	boost::algorithm::split(nameParts, name, boost::algorithm::is_any_of(L":"));
	if (nameParts.size()<2)
		m_oLocalName=m_oName;
	else {
		m_oPrefix	= nameParts[0];
		m_oLocalName	= nameParts[1];
	}
}

bool operator==(const Node& a, const Node& b) {
	return (&a==&b);
}

bool operator!=(const Node& a, const Node& b) {
	return (&a!=&b);
}

bool Node::isSameNode(const NodePtr& n) const {
	return (n.get()==this);
}

bool Node::isEqualNode(const NodePtr& n) const {
	if (isSameNode(n)) return true;
	if (	(nodeType()!=n->nodeType()) ||
			(nodeName()!=n->nodeName()) ||
			(localName()!=n->localName()) ||
			(namespaceURI()!=n->namespaceURI()) ||
			(prefix()!=n->prefix()) ||
			(nodeValue()!=n->nodeValue()))
		return false;
	NodePtr child		= attributes();
	NodePtr otherChild	= n->attributes();
	bool childrenOK;
	while (true==(childrenOK=(child.get() && child.get()==otherChild.get() && child->isEqualNode(otherChild)))) {
		child		= child->nextSibling();
		otherChild	= otherChild->nextSibling();
	}
	if (!childrenOK) return false;
	child		= firstChild();
	otherChild	= n->firstChild();
	while (true==(childrenOK=(child.get() && child.get()==otherChild.get() && child->isEqualNode(otherChild)))) {
		child		= child->nextSibling();
		otherChild	= otherChild->nextSibling();
	}
	if (!childrenOK) return false;
	return false;
}

NodePtr Node::_myself() const {
	return m_pSelf.lock();
}

void Node::_setParent(const NodePtr& parent) {
	if (nodeType()==DOCUMENT_NODE) return;
	m_pParent = parent;
	if (parent && parent->ownerDocument())
		_setOwnerDocument(parent->ownerDocument());
}

void Node::_setOwnerDocument(const DocumentPtr& document) {
	m_pOwnerDocument = document;
}

const std::wstring& Node::namespaceURI() const {
	return lookupNamespaceURI(prefix());
}

const std::wstring& Node::lookupPrefix(const std::wstring& namespaceURI) const {
	if (nodeType()==ELEMENT_NODE) {
		const Element* impl = reinterpret_cast<const Element*>(this);
		const NamespaceInfo* info = impl->_getNamespaceInfoByURI(namespaceURI);
		if (info) return info->prefix;
	}
	NodePtr parent = parentNode();
	while (parent) {
		if (parent->nodeType()==ELEMENT_NODE)
			return parent->lookupPrefix(namespaceURI);
		parent = parent->parentNode();
	}
	return m_oEmpty;
}

bool Node::isDefaultNamespace(const std::wstring& namespaceURI) const {
	return namespaceURI.empty();
}
const std::wstring& Node::lookupNamespaceURI(const std::wstring& prefix) const {
	if (nodeType()==ELEMENT_NODE) {
		const Element* impl = reinterpret_cast<const Element*>(this);
		const NamespaceInfo* info = impl->_getNamespaceInfoByPrefix(prefix);
		if (info) return info->uri;
	}
	NodePtr parent = parentNode();
	while (parent) {
		if (parent->nodeType()==ELEMENT_NODE)
			return parent->lookupPrefix(prefix);
		parent = parent->parentNode();
	}
	return DOMUtils::emptyString();
}

unsigned long Node::nodePosition() const {
	if (!parentNode()) return 0;
	unsigned long position=1;
	NodePtr previous = previousSibling();
	while(previous) {
		++position;
		previous = previous->previousSibling();
	}
	return position;
}

// Supports walking a list of nodes from the first element:
NodePtr Node::operator[](int i) {
	if (i>0) {
		if (nextSibling())
			return (*nextSibling())[--i];
		else
			return NodePtr();
	}
	else if (i==0) return _myself();
	else return NodePtr();
}
