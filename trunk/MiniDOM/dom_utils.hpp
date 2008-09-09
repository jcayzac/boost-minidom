#if !defined(DOM_UTILS_INCLUDED)
#define DOM_UTILS_INCLUDED

#include <boost/lexical_cast.hpp>
#include "dom_types.hpp"

class DOMUtils {
	static unsigned short translateXMLEntity(const DOMString& entity);
};

#endif // DOM_UTILS_INCLUDED
