#if !defined(DOM_TYPES_INCLUDED)
#define DOM_TYPES_INCLUDED

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <vector>
#include <string>
#include <exception>

// Forward declarations
class Node;
class Attr;
class Text;
class Element;
class Document;
class DocumentType;

// DOMString is a sequence of 16-bit units
typedef std::basic_string<unsigned short> DOMString;

// DOMTimeStamp is defined as a unsigned long long in DOM level 2 core specs
typedef unsigned long long DOMTimeStamp;


class DOMException : public std::exception {
public:
	enum {
		INDEX_SIZE_ERR = 1,
		DOMSTRING_SIZE_ERR,
		HIERARCHY_REQUEST_ERR,
		WRONG_DOCUMENT_ERR,
		INVALID_CHARACTER_ERR,
		NO_DATA_ALLOWED_ERR,
		NO_MODIFICATION_ALLOWED_ERR,
		NOT_FOUND_ERR,
		NOT_SUPPORTED_ERR,
		INUSE_ATTRIBUTE_ERR,
		INVALID_STATE_ERR,
		SYNTAX_ERR,
		INVALID_MODIFICATION_ERR,
		NAMESPACE_ERR,
		INVALID_ACCESS_ERR,
	};
public:
	DOMException(unsigned short c): mCode(c) { }
	unsigned short code() const { return mCode; }
	virtual const char* what() const throw() {
		return "DOMException";
	}
private:
	unsigned short mCode;
};


// From DOM-Level-2-Core, section 1.1.2, "Memory Management":
// To ensure a consistent API across [...] platforms, the DOM does not address
// memory management issues at all, but instead leaves these for the
// implementation. Neither of the explicit language bindings defined by the
// DOM API (for ECMAScript and Java) require any memory management methods,
// but DOM bindings for other languages (especially C or C++) may require such
// support.

// Thanks to Boost's smart pointers, we really don't need to address any issue
// at all...

typedef boost::shared_ptr<Node>			NodePtr;
typedef boost::shared_ptr<Attr>			AttrPtr;
typedef boost::shared_ptr<Text>			TextPtr;
typedef boost::shared_ptr<Element>		ElementPtr;
typedef boost::shared_ptr<Document>		DocumentPtr;
typedef boost::shared_ptr<DocumentType>	DocumentTypePtr;

typedef boost::weak_ptr<Node>			NodeWeakPtr;
typedef boost::weak_ptr<Attr>			AttrWeakPtr;
typedef boost::weak_ptr<Text>			TextWeakPtr;
typedef boost::weak_ptr<Element>		ElementWeakPtr;
typedef boost::weak_ptr<Document>		DocumentWeakPtr;
typedef boost::weak_ptr<DocumentType>	DocumentTypeWeakPtr;

// DOM defines a NodeList as follow:
// 
// interface NodeList {
//		Node item(in unsigned long index);
//		readonly attribute unsigned long    length;
// };
// 
// ...but for simplicity, I will use a std::vector<> instead
typedef std::vector<NodePtr>			NodeList;
typedef boost::shared_ptr<NodeList>		NodeListPtr;
typedef boost::weak_ptr<NodeList>		DNodeListWeakPtr;
typedef NodeList::iterator				NodeIterator;
typedef NodeList::const_iterator		NodeConstIterator;

class DOMImplementation {
public:
	static bool				hasFeature(const DOMString& feature, const DOMString& version);
	static DocumentPtr		createDocument(const DOMString& namespaceURI, const DOMString& qualifiedName, const DocumentType& doctype);

	/// DocumentType is not supported, so this will always return a NULL pointer.
	static DocumentTypePtr	createDocumentType(const DOMString& qualifiedName, const DOMString& publicId, const DOMString& systemId);
};

#endif // DOM_TYPES_INCLUDED

