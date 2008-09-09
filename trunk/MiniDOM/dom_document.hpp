#if !defined(DOM_DOCUMENT_INCLUDED)
#define DOM_DOCUMENT_INCLUDED

#include "dom_element.hpp"

class Document : public Element {
private:
	friend class DOMImplementation;
	friend class Node; // Needed for remove from orphans
	Document();
	Document(const Document& o);
public:
	virtual ~Document();

	NodePtr	createElement(const DOMString& name);
	NodePtr	createTextNode(const DOMString& data);
	NodePtr	createAttribute(const DOMString& name);
	NodePtr	documentElement () const;

	const DOMString&	docType() const	 { return m_oDoctype; }
	const DOMString&	encoding() const { return m_oEncoding; }

	void setDocType(const DOMString& dt) { m_oDoctype=dt; }
	void setEncoding(const DOMString& e) { m_oEncoding=e; }

private:
	// Used by create*()
	NodePtr	constructNode(Node* object);
private:
	DOMString	m_oDoctype;
	DOMString	m_oEncoding;
};


#endif // DOM_DOCUMENT_INCLUDED
