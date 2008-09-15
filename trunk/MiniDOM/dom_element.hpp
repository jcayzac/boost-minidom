#if !defined(DOM_ELEMENT_INCLUDED)
#define DOM_ELEMENT_INCLUDED

#include "dom_node.hpp"

namespace dom {

/// Provides basic XML Namespaces support
struct NamespaceInfo {
	std::wstring	prefix;
	std::wstring	uri;
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
	Element(const std::wstring& name);
	virtual ~Element();

	const std::wstring&	tagName() const { return nodeName(); }

	// From Node
	NodePtr		childNodes() const	{ return firstChild(); }
	NodePtr		firstChild() const	{ return m_pFirstChild; }
	NodePtr		lastChild() const	{ return m_pLastChild; }
	NodePtr		attributes() const	{ return m_pFirstAttribute; }
	NodePtr		insertBefore(const NodePtr& newChild, const NodePtr& refChild);
	NodePtr		replaceChild(const NodePtr& newChild, const NodePtr& oldChild);
	NodePtr		removeChild(const NodePtr& oldChild);
	NodePtr		appendChild(const NodePtr& newChild);
	bool		hasChildNodes() const;
	bool		hasAttributes() const;
	NodePtr		cloneNode(bool deep=false) const;
	bool		textContent(std::wstring& output) const;
	void		setTextContent(const std::wstring& newContent);
	NodePtr		getAttribute(const std::wstring& name) const;
	void		setAttribute(const std::wstring& name, const std::wstring& value);
	NodePtr		getElementById(const std::wstring& id) const;
	NodeListPtr	getElementsByTagName(const std::wstring& name) const;

protected:
	// From Node
	void				_setOwnerDocument(const DocumentPtr&);
private:
	// Used by ElementImpl::getElementsByTagName()
	void _addElementsByTagName(NodeListPtr& output, const std::wstring& name) const;

	const NamespaceInfo* _getNamespaceInfoByURI(const std::wstring& uri) const;
	const NamespaceInfo* _getNamespaceInfoByPrefix(const std::wstring& prefix) const;

protected:
	NodePtr				m_pFirstChild;
	NodePtr				m_pLastChild;
	NodePtr				m_pFirstAttribute;
	NodePtr				m_pLastAttribute;
	std::vector<NamespaceInfo>	m_oNamespacesInfo;
};

};

#endif // DOM_ELEMENT_INCLUDED
