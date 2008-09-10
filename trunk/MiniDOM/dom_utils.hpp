#if !defined(DOM_UTILS_INCLUDED)
#define DOM_UTILS_INCLUDED

#include <boost/lexical_cast.hpp>
#include <vector>
#include "dom_types.hpp"

class DOMUtils {
public:
	static unsigned short translateXMLEntity(const DOMString& entity);
	static void explodeString(const DOMString& src, const DOMString& separator, std::vector<DOMString>& output);
	static const DOMString& emptyString();
};

#endif // DOM_UTILS_INCLUDED
