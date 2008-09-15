#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <iostream>
#include <iterator>
#include "dom_node.hpp"
#include "dom_element.hpp"
#include "dom_attr.hpp"
#include "dom_text.hpp"
#include "dom_document.hpp"
#include "dom_xpath.hpp"
#include "dom_utils.hpp"
using namespace dom;

int main(int argc, const char** argv) {
	DocumentPtr doc = DOMImplementation::createDocument();
	NodePtr root = doc->createElement(L"root");
	doc->appendChild(root);
}
