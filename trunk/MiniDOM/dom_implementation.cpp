#include "dom_types.hpp"
#include "dom_document.hpp"
using namespace dom;

bool DOMImplementation::hasFeature(const DOMString& feature, const DOMString& version) {
	return false;
}

DocumentPtr DOMImplementation::createDocument() {
	Document* object = new Document();
	if (object) {
		DocumentPtr document(object);
		document->_setSelf(document);
		document->_setOwnerDocument(document);
		return document;
	}
	return DocumentPtr();
}

