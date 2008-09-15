#if !defined(DOM_DOCUMENT_INCLUDED)
#define DOM_DOCUMENT_INCLUDED

#include "dom_element.hpp"

namespace dom {

class Document : public Element {
private:
    friend class DOMImplementation;
    friend class Node; // Needed for remove from orphans
    Document();
    Document(const Document& o);
public:
    virtual ~Document();

    NodePtr    createElement(const std::wstring& name);
    NodePtr    createTextNode(const std::wstring& data);
    NodePtr    createAttribute(const std::wstring& name);
    NodePtr    documentElement () const;

    const std::wstring&    docType() const  { return m_oDoctype; }
    const std::wstring&    encoding() const { return m_oEncoding; }

    void setDocType(const std::wstring& dt) { m_oDoctype=dt; }
    void setEncoding(const std::wstring& e) { m_oEncoding=e; }

private:
    // Used by create*()
    NodePtr    constructNode(Node* object);
private:
    std::wstring m_oDoctype;
    std::wstring m_oEncoding;
};

}; // namespace dom

#endif // DOM_DOCUMENT_INCLUDED
