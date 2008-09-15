#if !defined(DOM_UTILS_INCLUDED)
#define DOM_UTILS_INCLUDED

#include <boost/lexical_cast.hpp>
#include <vector>
#include "dom_types.hpp"

namespace dom {

class DOMUtils {
public:
    /** Translate an XML/HTML entity, such as &amp;eacute; or &amp;#67;
      * or &amp;#xe3;, and return its character value.
      * @param entity Name of the entity
      * @return The corresponding character
      */
	static wchar_t translateXMLEntity(const std::wstring& entity);
};

}; // namespace dom

#endif // DOM_UTILS_INCLUDED
