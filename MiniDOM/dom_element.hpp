#if !defined(DOM_ELEMENT_INCLUDED)
#define DOM_ELEMENT_INCLUDED

#include "dom_node.hpp"

namespace dom {

/// Provides basic XML Namespaces support
struct NamespaceInfo {
	DOMString	prefix;
	DOMString	uri;
};
inline bool operator==(const NamespaceInfo &a,const NamespaceInfo &b) {
	return (a.prefix == b.prefix && a.uri == b.uri);
}


class Element: public Node {
private:
	friend class Node;
	friend class Document;
	Element(const Element&);
public:
	Element(const DOMString& name);
	virtual ~Element();

	const DOMString&	tagName() const { return nodeName(); }

	// From Node
	NodePtr				childNodes() const	{ return firstChild(); }
	NodePtr				firstChild() const	{ return m_pFirstChild; }
	NodePtr				lastChild() const	{ return m_pLastChild; }
	NodePtr				attributes() const	{ return m_pFirstAttribute; }
	NodePtr				insertBefore(const NodePtr& newChild, const NodePtr& refChild);
	NodePtr				replaceChild(const NodePtr& newChild, const NodePtr& oldChild);
	NodePtr				removeChild(const NodePtr& oldChild);
	NodePtr				appendChild(const NodePtr& newChild);
	bool				hasChildNodes() const;
	bool				hasAttributes() const;
	NodePtr				cloneNode(bool deep=false) const;
	bool				textContent(DOMString& output) const;
	void				setTextContent(const DOMString& newContent);
	NodePtr				getAttribute(const DOMString& name) const;
	void				setAttribute(const DOMString& name, const DOMString& value);
	NodePtr				getElementById(const DOMString& id) const;
	NodeListPtr			getElementsByTagName(const DOMString& name) const;

protected:
	// From Node
	void				_setOwnerDocument(const DocumentPtr&);
private:
	// Used by ElementImpl::getElementsByTagName()
	void _addElementsByTagName(NodeListPtr& output, const DOMString& name) const;

	const NamespaceInfo* _getNamespaceInfoByURI(const DOMString& uri) const;
	const NamespaceInfo* _getNamespaceInfoByPrefix(const DOMString& prefix) const;

protected:
	NodePtr						m_pFirstChild;
	NodePtr						m_pLastChild;
	NodePtr						m_pFirstAttribute;
	NodePtr						m_pLastAttribute;
	std::vector<NamespaceInfo>	m_oNamespacesInfo;
};

};

#endif // DOM_ELEMENT_INCLUDED
