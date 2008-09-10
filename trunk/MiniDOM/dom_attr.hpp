#if !defined(DOM_ATTR_INCLUDED)
#define DOM_ATTR_INCLUDED

#include "dom_node.hpp"

namespace dom {

class Attr: public Node {
private:
	Attr(const Attr&);
public:
	Attr(const DOMString& name);
	virtual ~Attr() { }

	const DOMString&	name() const					{ return nodeName(); }
	const DOMString&	value() const					{ return m_oValue; }
	void				setValue(const DOMString& v)	{ m_oValue=v; }
	ElementPtr			ownerElement() const;

	// From Node
	NodePtr	cloneNode(bool deep=false) const;
	bool	textContent(DOMString& output) const { output=m_oValue; return true; }
	void	setTextContent(const DOMString& newContent) { m_oValue=newContent; }
};

}; // namespace dom

#endif // DOM_ATTR_INCLUDED
