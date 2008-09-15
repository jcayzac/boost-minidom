#if !defined(DOM_UTILS_INCLUDED)
#define DOM_UTILS_INCLUDED

#include <boost/lexical_cast.hpp>
#include <vector>
#include "dom_types.hpp"

namespace dom {

class DOMUtils {
public:
	static wchar_t translateXMLEntity(const std::wstring& entity);
	static const std::wstring& emptyString();
};

}; // namespace dom

#endif // DOM_UTILS_INCLUDED
