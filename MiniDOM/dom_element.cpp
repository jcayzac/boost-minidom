#include <vector>
#include "dom_attr.hpp"
#include "dom_element.hpp"
#include "dom_document.hpp"
#include "dom_utils.hpp"
using namespace dom;

#define S(x) (const unsigned short* const)L##x

Element::Element(const DOMString& name)
: Node(name, ELEMENT_NODE)
{ }

Element::~Element() {
	// TODO: Detach all child nodes
}

NodePtr Element::getAttribute(const DOMString& name) const {
	if (!hasAttributes()) return NodePtr();
	NodePtr child = m_pFirstAttribute;
	while (child) {
		if (child->nodeName()==name) return child;
		child = child->nextSibling();
	}
	return NodePtr();
}
void Element::setAttribute(const DOMString& name, const DOMString& value) {
	std::vector<DOMString> attrNameParts;
	DOMUtils::explodeString(name,S(":"),attrNameParts);
	if (attrNameParts.size()==2) {
		if (attrNameParts[0]==S("xmlns")) {
			// Attribute is a XML Namespace declaration
			NamespaceInfo info;
			info.prefix	= attrNameParts[1];
			info.uri	= value;
			m_oNamespacesInfo.push_back(info);
			return;
		}
	}
	if (name==S("xmlns")) {
		// Default namespace
			NamespaceInfo info;
			info.uri	= value;
			m_oNamespacesInfo.push_back(info);
			return;
	}

	NodePtr attr = ownerDocument()->createAttribute(name);
	reinterpret_cast<Attr*>(attr.get())->setValue(value);
	appendChild(attr);
}

NodePtr Element::insertBefore(const NodePtr& newChild, const NodePtr& refChild) {
	if (!newChild || !refChild)
		return NodePtr();
	// Cannot insert Node if it already has a parent.
	if (newChild->parentNode())
		return NodePtr();
	// Cannot insert Node if refChild parent is not this Node.
	if (!isSameNode(refChild->parentNode()))
		return NodePtr();
	// Cannot insert an Attr before a non Attr or a non Attr before an Attr
	if ((newChild->nodeType()==ATTRIBUTE_NODE && refChild->nodeType()!=ATTRIBUTE_NODE) ||
		(newChild->nodeType()!=ATTRIBUTE_NODE && refChild->nodeType()==ATTRIBUTE_NODE))
		return NodePtr();

	newChild->_setParent(_myself());
	//
	NodePtr previous = refChild->previousSibling();
	if (previous) {
		newChild->_setPreviousSibling(previous);
		previous->_setNextSibling(newChild);
	}
	else if (newChild->nodeType()==ATTRIBUTE_NODE)
		m_pFirstAttribute = newChild;
	else
		m_pFirstChild = newChild;
	//
	newChild->_setNextSibling(refChild);
	refChild->_setPreviousSibling(newChild);
	return newChild;
}

NodePtr Element::replaceChild(const NodePtr& newChild, const NodePtr& oldChild) {
	if (!newChild || !oldChild)
		return NodePtr();
	// Cannot insert Node if it already has a parent.
	if (newChild->parentNode())
		return NodePtr();
	// Cannot insert Node if refChild parent is not this Node.
	if (!isSameNode(oldChild->parentNode()))
		return NodePtr();
	// Cannot replace an Attr with a non Attr or a non Attr with an Attr
	if ((newChild->nodeType()==ATTRIBUTE_NODE && oldChild->nodeType()!=ATTRIBUTE_NODE) ||
		(newChild->nodeType()!=ATTRIBUTE_NODE && oldChild->nodeType()==ATTRIBUTE_NODE))
		return NodePtr();
	//
	newChild->_setParent(_myself());
	newChild->_setOwnerDocument(ownerDocument());
	//
	NodePtr previous = oldChild->previousSibling();
	if (previous) {
		newChild->_setPreviousSibling(previous);
		previous->_setNextSibling(newChild);
	}
	else if (newChild->nodeType()==ATTRIBUTE_NODE)
		m_pFirstAttribute = newChild;
	else
		m_pFirstChild = newChild;
	//
	NodePtr next = oldChild->nextSibling();
	if (next) {
		newChild->_setNextSibling(next);
		next->_setPreviousSibling(newChild);
	}
	else if (newChild->nodeType()==ATTRIBUTE_NODE)
		m_pLastAttribute = newChild;
	else
		m_pLastChild = newChild;
	//
	return newChild;
}

NodePtr Element::appendChild(const NodePtr& n) {
	if (!n)
		return NodePtr();
	// Cannot append Node if it already has a parent.
	if (n->parentNode())
		return NodePtr();
	//
	n->_setParent(_myself());
	n->_setOwnerDocument(ownerDocument());
	//
	NodePtr last = (n->nodeType()==ATTRIBUTE_NODE)?m_pLastAttribute:m_pLastChild;
	if (last)
		last->_setNextSibling(n);
	n->_setPreviousSibling(last);
	if (n->nodeType()==ATTRIBUTE_NODE) {
		m_pLastAttribute=n;
		if (!m_pFirstAttribute) m_pFirstAttribute=n;
	}
	else {
		m_pLastChild=n;
		if (!m_pFirstChild) m_pFirstChild=n;
	}

	return n;
}
NodePtr Element::removeChild(const NodePtr& n) {
	if (!n)
		return NodePtr();
	// Cannot remove a Node if we don't own it.
	if (n->parentNode()!=_myself())
		return NodePtr();

	NodePtr& first = (n->nodeType()==ATTRIBUTE_NODE)?m_pFirstChild:m_pLastChild;
	NodePtr& last  = (n->nodeType()==ATTRIBUTE_NODE)?m_pLastAttribute:m_pLastChild;

	if (n->isSameNode(first))
		first=n->nextSibling();
	if (n->isSameNode(last))
		last=n->previousSibling();
	if (n->previousSibling())
		n->previousSibling()->_setNextSibling(n->nextSibling());
	if (n->nextSibling())
		n->nextSibling()->_setPreviousSibling(n->previousSibling());
	n->_setParent(NodePtr());
	return n;
}
bool Element::hasChildNodes() const {
	return (m_pFirstChild.get()!=0);
}
bool Element::hasAttributes() const {
	return (m_pFirstAttribute.get()!=0);
}

NodePtr Element::cloneNode(bool deep) const {
	if (ownerDocument()) {
		NodePtr newElement = ownerDocument()->createElement(tagName());
		Element* newImpl = reinterpret_cast<Element*>(newElement.get());
		if (!newImpl) return NodePtr();

		// Clone attributes
		NodePtr child = m_pFirstAttribute;
		while(child) {
			Attr* attr = reinterpret_cast<Attr*>(child.get());
			newImpl->setAttribute(attr->name(), attr->value());
			child = child->nextSibling();
		}

		if (deep) {
			// Clone children
			child = m_pFirstChild;
			while(child) {
				newImpl->appendChild(child->cloneNode(deep));
				child = child->nextSibling();
			}
		}
		return newElement;
	}
	return NodePtr();
}

bool Element::textContent(DOMString& output) const {
	bool result=false;
	NodePtr child = m_pFirstChild;
	while (child) {
		//FIXME: slow (many reallocs and copies)
		DOMString tmp;
		bool tmpr = child->textContent(tmp);
		if (tmpr) {
			result=true;
			output+=tmp;
		}
		child=child->nextSibling();
	}
	return result;
}

void Element::setTextContent(const DOMString& newContent) {
	if (nodeType()==DOCUMENT_NODE) return;
	// Remove all child nodes
	while (m_pFirstChild) removeChild(m_pFirstChild);
	// Create and append a new child with the requested content
	NodePtr textNode = ownerDocument()->createTextNode(newContent);
	if (textNode) appendChild(textNode);
}

NodePtr Element::getElementById(const DOMString& id) const {
	NodePtr child = m_pFirstChild;
	while (child) {
		if (child->nodeType()==ELEMENT_NODE) {
			NodePtr attr = child->getAttribute(S("id"));
			if (attr && attr->nodeValue()==id) return child;
		}
		child=child->nextSibling();
	}
	return NodePtr();
}
NodeListPtr Element::getElementsByTagName(const DOMString& name) const {
	NodeListPtr output(new NodeList);
	if (output) _addElementsByTagName(output,name);
	return output;
}
void Element::_addElementsByTagName(NodeListPtr& output, const DOMString& name) const {
	NodePtr child = m_pFirstChild;
	while (child) {
		if (child->nodeType()==ELEMENT_NODE && child->nodeName()==name) {
			output->push_back(child);
			reinterpret_cast<Element*>(child.get())->_addElementsByTagName(output,name);
		}
		child=child->nextSibling();
	}
}
void Element::_setOwnerDocument(const DocumentPtr& document) {
	Node::_setOwnerDocument(document);
	NodePtr child = m_pFirstAttribute;
	while (child) {
		child->_setOwnerDocument(ownerDocument());
		child = child->nextSibling();
	}
	child = m_pFirstChild;
	while (child) {
		child->_setOwnerDocument(ownerDocument());
		child = child->nextSibling();
	}
}

const NamespaceInfo* Element::_getNamespaceInfoByURI(const DOMString& uri) const {
	std::vector<NamespaceInfo>::const_iterator it = m_oNamespacesInfo.begin();
	while(it!=m_oNamespacesInfo.end()) {
		const NamespaceInfo& info = *it; ++it;
		if (info.uri==uri) return &info;
	}
	return 0;
}

const NamespaceInfo* Element::_getNamespaceInfoByPrefix(const DOMString& prefix) const {
	std::vector<NamespaceInfo>::const_iterator it = m_oNamespacesInfo.begin();
	while(it!=m_oNamespacesInfo.end()) {
		const NamespaceInfo& info = *it; ++it;
		if (info.prefix==prefix) return &info;
	}
	return 0;
}

