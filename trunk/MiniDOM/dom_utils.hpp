#if !defined(DOM_UTILS_INCLUDED)
#define DOM_UTILS_INCLUDED

#include <string>

namespace dom {

class DOMUtils {
public:
    /** Translate an XML/HTML entity, such as "&amp;eacute;" or "&amp;#67;"
      * or "&amp;#xe3;", and return its character value.
      * @param entity Name of the entity
      * @return The corresponding character
      */
	static wchar_t translateXMLEntity(const std::wstring& entity);

    static bool isLineBreakingSpace(wchar_t c);
    static bool isBreakingWhiteSpace(wchar_t c);
    static bool isNonBreakingWhiteSpace(wchar_t c);
    static bool isWhiteSpace(wchar_t c);
    static void trimSpaces(std::wstring& s);

};

}; // namespace dom

#endif // DOM_UTILS_INCLUDED
