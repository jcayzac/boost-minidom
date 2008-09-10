#include "dom_attr.hpp"
#include "dom_document.hpp"
using namespace dom;

Attr::Attr(const DOMString& name)
: Node(name,ATTRIBUTE_NODE)
{ }

NodePtr Attr::cloneNode(bool) const {
	if (ownerDocument()) {
		NodePtr newAttr = ownerDocument()->createAttribute(name());
		Attr* newImpl = reinterpret_cast<Attr*>(newAttr.get());
		newImpl->setValue(value());
		return newAttr;
	}
	return NodePtr();
}

ElementPtr Attr::ownerElement() const {
	NodePtr parent = parentNode();
	while (parent) {
		if (parent->nodeType()==ELEMENT_NODE) return ElementPtr(parent, boost::detail::static_cast_tag());
		parent = parent->parentNode();
	}
	return ElementPtr();
}
