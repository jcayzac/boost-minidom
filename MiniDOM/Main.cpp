#include "dom_node.hpp"
#include "dom_element.hpp"
#include "dom_attr.hpp"
#include "dom_text.hpp"
#include "dom_document.hpp"
#include "dom_xpath.hpp"
using namespace dom;

#define S(x) (const unsigned short* const)L##x

int main(int argc, const char** argv) {
	DocumentPtr doc = DOMImplementation::createDocument();
	NodePtr root = doc->createElement(S("root"));
	doc->appendChild(root);
	int z = sizeof(wchar_t);
	z;
}
