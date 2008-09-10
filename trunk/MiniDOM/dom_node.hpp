#if !defined(DOM_NODE_INCLUDED)
#define DOM_NODE_INCLUDED

#include "dom_types.hpp"

/** @brief Base class for all DOM nodes.
  * @note Nodes may or may not have a parent element.
  * @note Nodes always have an owner. i.e.) ownerDocument() never returns null.
  */
class Node {
private:
	friend class DOMImplementation;	// Needed for all those create*() methods in DOM
	friend class Element;			// Needed for attaching/detaching child nodes
	friend class Document;			// Needed for attaching/detaching the document element.
public:
	enum TNodeType {
		ELEMENT_NODE	= 1,			//<! An element.
		ATTRIBUTE_NODE,					//<! An element attribute.
		TEXT_NODE,						//<! Some text
		CDATA_SECTION_NODE,				//<! Not implemented.
		ENTITY_REFERENCE_NODE,			//<! Not implemented.
		ENTITY_NODE,					//<! Not implemented.
		PROCESSING_INSTRUCTION_NODE,	//<! Not implemented.
		COMMENT_NODE,					//<! Not implemented.
		DOCUMENT_NODE,					//<! A document.
		DOCUMENT_TYPE_NODE,				//<! Not implemented.
		DOCUMENT_FRAGMENT_NODE,			//<! Not implemented.
		NOTATION_NODE,					//<! Not implemented.
	};
private:
	Node();
	Node(const Node&);
protected:
	Node(const DOMString& name, TNodeType type);
public:
	virtual ~Node() { }

	const DOMString&	nodeName() const		{ return m_oName; }
	const DOMString&	nodeValue() const		{ return m_oValue; }
	TNodeType			nodeType() const		{ return m_eType; }

	const DOMString&	namespaceURI() const;
	const DOMString&	prefix() const			{ return m_oPrefix; }
	const DOMString&	localName() const		{ return m_oLocalName; }
	const DOMString&	lookupPrefix(const DOMString& namespaceURI) const;
	bool				isDefaultNamespace(const DOMString& namespaceURI) const;
	const DOMString&	lookupNamespaceURI(const DOMString& prefix) const;

	DocumentPtr			ownerDocument() const	{ return m_pOwnerDocument.lock(); }
	NodePtr				parentNode() const		{ return m_pParent.lock(); }

	virtual NodePtr		firstChild() const		{ return NodePtr(); }
	virtual NodePtr		lastChild() const		{ return NodePtr(); }
	NodePtr				previousSibling() const	{ return m_pPreviousSibling.lock(); }
	NodePtr				nextSibling() const		{ return m_pNextSibling; }
	unsigned long		nodePosition() const;

	virtual NodePtr		childNodes() const		{ return NodePtr(); }
	virtual NodePtr		attributes() const		{ return NodePtr(); }
	NodePtr				operator[](int);

	virtual NodePtr		insertBefore(const NodePtr& newChild, const NodePtr& refChild)	{ return NodePtr(); }
	virtual NodePtr		replaceChild(const NodePtr& newChild, const NodePtr& oldChild)	{ return NodePtr(); }
	virtual NodePtr		removeChild(const NodePtr& oldChild)							{ return NodePtr(); }
	virtual NodePtr		appendChild(const NodePtr& newChild)							{ return NodePtr(); }
	virtual bool		hasChildNodes() const											{ return false;  }
	virtual bool		hasAttributes() const											{ return false;  }

	virtual NodePtr		getAttribute(const DOMString& name) const					{ return NodePtr(); }
	virtual void		setAttribute(const DOMString& name, const DOMString& value)	{ }
	virtual NodePtr		getElementById(const DOMString& id) const					{ return NodePtr(); }
	virtual NodeListPtr	getElementsByTagName(const DOMString& name) const			{ return NodeListPtr(); }

	virtual NodePtr		cloneNode(bool deep=false) const = 0;
	virtual bool		textContent(DOMString& output) const = 0;
	virtual void		setTextContent(const DOMString& newContent) = 0;
	// Comparison
	friend bool			operator==(const Node& a, const Node& b);
	friend bool			operator!=(const Node& a, const Node& b);
	bool				isSameNode(const NodePtr& n) const;
	bool				isEqualNode(const NodePtr& n) const;

public:
	NodePtr				_myself() const;
	void				_setParent(const NodePtr&);
	void				_setOwnerDocument(const DocumentPtr&);

private:
	// Only set by Element when attaching/detaching a child Node
	void _setPreviousSibling(NodePtr node)	{ m_pPreviousSibling = node; }
	void _setNextSibling(NodePtr node)		{ m_pNextSibling = node; }

private:
	// Only set on creation by the owner Document
	void _setSelf(NodePtr self) { m_pSelf = self; }

protected:
	// Only set by derivated classes
	DOMString	m_oValue;

private:
	TNodeType	m_eType;
	DOMString	m_oName;
	//
	DOMString	m_oPrefix;
	DOMString	m_oLocalName;
	DOMString	m_oEmpty;
	//
	DocumentWeakPtr	m_pOwnerDocument;
	NodeWeakPtr		m_pParent;
	NodeWeakPtr		m_pSelf;
	//
	NodePtr			m_pNextSibling;
	NodeWeakPtr		m_pPreviousSibling;
};

#endif // DOM_NODE_INCLUDED
