#include <boost/shared_ptr.hpp>

#include "dom_text.hpp"
#include "dom_document.hpp"

#define S(x) (const unsigned short* const)L##x

Text::Text(const DOMString& data)
: Node(S("#text"),TEXT_NODE)
{
	m_oValue=data;
}

NodePtr Text::cloneNode(bool) const {
	if (ownerDocument()) {
		NodePtr newText = ownerDocument()->createTextNode(m_oValue);
		return newText;
	}
	return NodePtr();
}

TextPtr Text::replaceWholeText(const DOMString& content) {
	NodePtr sibling = nextSibling();
	while (sibling && sibling->nodeType()==TEXT_NODE) {
		parentNode()->removeChild(sibling);
		sibling=nextSibling();
	}
	m_oValue = content;
	return TextPtr(_myself(),boost::detail::static_cast_tag());
}

const DOMString& Text::wholeText() const {
	NodePtr sibling	= nextSibling();
	if (!(sibling && sibling->nodeType()==TEXT_NODE)) return nodeValue();

	Text* sibling_ptr	= reinterpret_cast<Text*>(sibling.get());

	m_oTempString = nodeValue()+sibling_ptr->wholeText();
	sibling_ptr->m_oTempString.clear();

	return m_oTempString;
}

