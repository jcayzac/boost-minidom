#include "dom_types.hpp"
#include "dom_document.hpp"

bool DOMImplementation::hasFeature(const DOMString& feature, const DOMString& version) {
	return false;
}

DocumentPtr DOMImplementation::createDocument(const DOMString& namespaceURI, const DOMString& qualifiedName, const DocumentType& doctype) {
	Document* object = new Document();
	if (object) {
		DocumentPtr document(object);
		document->_setSelf(document);
		document->_setOwnerDocument(document);
		return document;
	}
	return DocumentPtr();
}

DocumentTypePtr	DOMImplementation::createDocumentType(const DOMString& qualifiedName, const DOMString& publicId, const DOMString& systemId) {
	return DocumentTypePtr();
}
