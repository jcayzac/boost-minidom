#if !defined(DOM_ATTR_INCLUDED)
#define DOM_ATTR_INCLUDED

#include "dom_node.hpp"

namespace dom {

class Attr: public Node {
private:
    Attr(const Attr&);
public:
    Attr(const std::wstring& name);
    virtual ~Attr() { }

    const std::wstring& name() const  { return nodeName(); }
    const std::wstring& value() const { return m_oValue; }
    void                setValue(const std::wstring& v) { m_oValue=v; }
    ElementPtr          ownerElement() const;

    // From Node
    NodePtr cloneNode(bool deep=false) const;
    bool    textContent(std::wstring& output) const { output=m_oValue; return true; }
    void    setTextContent(const std::wstring& newContent) { m_oValue=newContent; }
};

}; // namespace dom

#endif // DOM_ATTR_INCLUDED
