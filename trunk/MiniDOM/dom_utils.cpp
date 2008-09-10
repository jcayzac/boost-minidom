#include <boost/pool/detail/singleton.hpp>
#include <boost/tokenizer.hpp>
#include <map>
#include "dom_utils.hpp"
using namespace dom;

#define S(x) (const unsigned short* const)L##x
typedef boost::tokenizer<boost::char_separator<unsigned short>,DOMString::const_iterator,DOMString> DOMTokenizer;


// This object will be wrapped into a singleton, and built before main() is called
class EntityDatabase {
public:
	static unsigned short get(const DOMString& entity) {
		const std::map<DOMString,unsigned short>& entities = boost::details::pool::singleton_default<EntityDatabase>::instance().mEntityMap;
		std::map<DOMString,unsigned short>::const_iterator it=entities.find(entity);
		if (it==entities.end())
			throw DOMException(DOMException::INVALID_CHARACTER_ERR);
		return it->second;
	}
private:
	friend boost::details::pool::singleton_default<EntityDatabase>;
	std::map<DOMString,unsigned short> mEntityMap;
	EntityDatabase() {
		mEntityMap[S("amp")]		= 0x0026;	// XML 1.0, HTML 2.0	ampersand
		mEntityMap[S("apos")]		= 0x0027;	// XML 1.0, XHTML		apostrophe
		mEntityMap[S("acute")]		= 0x00B4;	// HTML 3.2 	acute accent
		mEntityMap[S("agrave")]		= 0x00E0;	// HTML 2.0 	Latin small letter a with grave
		mEntityMap[S("aacute")]		= 0x00E1;	// HTML 2.0 	Latin small letter a with acute
		mEntityMap[S("acirc")]		= 0x00E2;	// HTML 2.0 	Latin small letter a with circumflex
		mEntityMap[S("atilde")]		= 0x00E3;	// HTML 2.0 	Latin small letter a with tilde
		mEntityMap[S("auml")]		= 0x00E4;	// HTML 2.0 	Latin small letter a with diaeresis
		mEntityMap[S("aring")]		= 0x00E5;	// HTML 2.0 	Latin small letter a with ring above
		mEntityMap[S("aelig")]		= 0x00E6;	// HTML 2.0 	Latin lowercase ligature ae
		mEntityMap[S("alpha")]		= 0x03B1;	// HTML 4.0 	Greek small letter alpha
		mEntityMap[S("alefsym")]	= 0x2135;	// HTML 4.0 	alef symbol			 
		mEntityMap[S("ang")]		= 0x2220;	// HTML 4.0 	angle
		mEntityMap[S("and")]		= 0x2227;	// HTML 4.0 	logical and
		mEntityMap[S("asymp")]		= 0x2248;	// HTML 4.0 	almost equal to
		mEntityMap[S("brvbar")]		= 0x00A6;	// HTML 3.2 	broken bar
		mEntityMap[S("beta")]		= 0x03B2;	// HTML 4.0 	Greek small letter beta
		mEntityMap[S("bdquo")]		= 0x201E;	// HTML 4.0 	double low-9 quotation mark
		mEntityMap[S("bull")]		= 0x2022;	// HTML 4.0 	bullet
		mEntityMap[S("copy")]		= 0x00A9;	// HTML 3.2 	copyright sign
		mEntityMap[S("ccedil")]		= 0x00E7;	// HTML 2.0 	Latin small letter c with cedilla
		mEntityMap[S("cent")]		= 0x00A2;	// HTML 3.2 	cent sign
		mEntityMap[S("curren")]		= 0x00A4;	// HTML 3.2 	currency sign
		mEntityMap[S("cedil")]		= 0x00B8;	// HTML 3.2 	cedilla
		mEntityMap[S("circ")]		= 0x02C6;	// HTML 4.0 	modifier letter circumflex accent
		mEntityMap[S("chi")]		= 0x03C7;	// HTML 4.0 	Greek small letter chi
		mEntityMap[S("crarr")]		= 0x21B5;	// HTML 4.0 	downwards arrow with corner leftwards
		mEntityMap[S("cap")]		= 0x2229;	// HTML 4.0 	intersection
		mEntityMap[S("cup")]		= 0x222A;	// HTML 4.0 	union
		mEntityMap[S("cong")]		= 0x2245;	// HTML 4.0 	congruent to
		mEntityMap[S("clubs")]		= 0x2663;	// HTML 4.0 	black club suit
		mEntityMap[S("deg")]		= 0x00B0;	// HTML 3.2 	degree sign
		mEntityMap[S("divide")]		= 0x00F7;	// HTML 3.2 	division sign
		mEntityMap[S("delta")]		= 0x03B4;	// HTML 4.0 	Greek small letter delta
		mEntityMap[S("dagger")]		= 0x2020;	// HTML 4.0 	dagger
		mEntityMap[S("darr")]		= 0x2193;	// HTML 4.0 	downwards arrow
		mEntityMap[S("dArr")]		= 0x21D3;	// HTML 4.0 	downwards double arrow
		mEntityMap[S("diams")]		= 0x2666;	// HTML 4.0 	black diamond suit
		mEntityMap[S("egrave")]		= 0x00E8;	// HTML 2.0 	Latin small letter e with grave
		mEntityMap[S("eacute")]		= 0x00E9;	// HTML 2.0 	Latin small letter e with acute
		mEntityMap[S("ecirc")]		= 0x00EA;	// HTML 2.0 	Latin small letter e with circumflex
		mEntityMap[S("euml")]		= 0x00EB;	// HTML 2.0 	Latin small letter e with diaeresis
		mEntityMap[S("eth")]		= 0x00F0;	// HTML 2.0 	Latin small letter eth
		mEntityMap[S("epsilon")]	= 0x03B5;	// HTML 4.0 	Greek small letter epsilon
		mEntityMap[S("eta")]		= 0x03B7;	// HTML 4.0 	Greek small letter eta
		mEntityMap[S("ensp")]		= 0x2002;	// HTML 4.0 	en space [1]
		mEntityMap[S("emsp")]		= 0x2003;	// HTML 4.0 	em space [2]
		mEntityMap[S("euro")]		= 0x20AC;	// HTML 4.0 	euro sign
		mEntityMap[S("exist")]		= 0x2203;	// HTML 4.0 	there exists
		mEntityMap[S("empty")]		= 0x2205;	// HTML 4.0 	empty set
		mEntityMap[S("equiv")]		= 0x2261;	// HTML 4.0 	identical to (equivalent to)
		mEntityMap[S("frac14")]		= 0x00BC;	// HTML 3.2 	vulgar fraction one quarter
		mEntityMap[S("frac12")]		= 0x00BD;	// HTML 3.2 	vulgar fraction one half
		mEntityMap[S("frac34")]		= 0x00BE;	// HTML 3.2 	vulgar fraction three quarters
		mEntityMap[S("fnof")]		= 0x0192;	// HTML 4.0 	Latin small letter f with hook
		mEntityMap[S("frasl")]		= 0x2044;	// HTML 4.0 	fraction slash
		mEntityMap[S("forall")]		= 0x2200;	// HTML 4.0 	for all
		mEntityMap[S("gt")]			= 0x003e;	// XML 1.0, HTML 2.0	greater-than sign
		mEntityMap[S("gamma")]		= 0x03B3;	// HTML 4.0 	Greek small letter gamma
		mEntityMap[S("ge")]			= 0x2265;	// HTML 4.0 	greater-than or equal to
		mEntityMap[S("hellip")]		= 0x2026;	// HTML 4.0 	horizontal ellipsis
		mEntityMap[S("harr")]		= 0x2194;	// HTML 4.0 	left right arrow
		mEntityMap[S("hArr")]		= 0x21D4;	// HTML 4.0 	left right double arrow
		mEntityMap[S("hearts")]		= 0x2665;	// HTML 4.0 	black heart suit
		mEntityMap[S("igrave")]		= 0x00EC;	// HTML 2.0 	Latin small letter i with grave
		mEntityMap[S("iacute")]		= 0x00ED;	// HTML 2.0 	Latin small letter i with acute
		mEntityMap[S("icirc")]		= 0x00EE;	// HTML 2.0 	Latin small letter i with circumflex
		mEntityMap[S("iuml")]		= 0x00EF;	// HTML 2.0 	Latin small letter i with diaeresis
		mEntityMap[S("iexcl")]		= 0x00A1;	// HTML 3.2 	inverted exclamation mark
		mEntityMap[S("iquest")]		= 0x00BF;	// HTML 3.2 	inverted question mark
		mEntityMap[S("iota")]		= 0x03B9;	// HTML 4.0 	Greek small letter iota
		mEntityMap[S("image")]		= 0x2111;	// HTML 4.0 	black-letter capital i
		mEntityMap[S("isin")]		= 0x2208;	// HTML 4.0 	element of
		mEntityMap[S("infin")]		= 0x221E;	// HTML 4.0 	infinity
		mEntityMap[S("int")]		= 0x222B;	// HTML 4.0 	integral
		mEntityMap[S("kappa")]		= 0x03BA;	// HTML 4.0 	Greek small letter kappa
		mEntityMap[S("lt")]			= 0x003c;	// XML 1.0, HTML 2.0	less-than sign
		mEntityMap[S("laquo")]		= 0x00AB;	// HTML 3.2 	left-pointing double angle quotation mark
		mEntityMap[S("lambda")]		= 0x03BB;	// HTML 4.0 	Greek small letter lambda
		mEntityMap[S("lrm")]		= 0x200E;	// HTML 4.0 	left-to-right mark
		mEntityMap[S("lsquo")]		= 0x2018;	// HTML 4.0 	left single quotation mark
		mEntityMap[S("ldquo")]		= 0x201C;	// HTML 4.0 	left double quotation mark
		mEntityMap[S("larr")]		= 0x2190;	// HTML 4.0 	leftwards arrow			 
		mEntityMap[S("lsaquo")]		= 0x2039;	// HTML 4.0 	single left-pointing angle quotation mark
		mEntityMap[S("lArr")]		= 0x21D0;	// HTML 4.0 	leftwards double arrow
		mEntityMap[S("lowast")]		= 0x2217;	// HTML 4.0 	asterisk operator
		mEntityMap[S("le")]			= 0x2264;	// HTML 4.0 	less-than or equal to
		mEntityMap[S("lceil")]		= 0x2308;	// HTML 4.0 	left ceiling
		mEntityMap[S("lfloor")]		= 0x230A;	// HTML 4.0 	left floor
		mEntityMap[S("lang")]		= 0x2329;	// HTML 4.0 	left-pointing angle bracket
		mEntityMap[S("loz")]		= 0x25CA;	// HTML 4.0 	lozenge
		mEntityMap[S("macr")]		= 0x00AF;	// HTML 3.2 	macron
		mEntityMap[S("micro")]		= 0x00B5;	// HTML 3.2 	micro sign
		mEntityMap[S("middot")]		= 0x00B7;	// HTML 3.2 	middle dot
		mEntityMap[S("mu")]			= 0x03BC;	// HTML 4.0 	Greek small letter mu
		mEntityMap[S("mdash")]		= 0x2014;	// HTML 4.0 	em dash
		mEntityMap[S("minus")]		= 0x2212;	// HTML 4.0 	minus sign
		mEntityMap[S("nbsp")]		= 0x00A0;	// HTML 3.2 	non-breaking space
		mEntityMap[S("ntilde")]		= 0x00F1;	// HTML 2.0 	Latin small letter n with tilde
		mEntityMap[S("not")]		= 0x00AC;	// HTML 3.2 	not sign
		mEntityMap[S("nu")]			= 0x03BD;	// HTML 4.0 	Greek small letter nu
		mEntityMap[S("ndash")]		= 0x2013;	// HTML 4.0 	en dash
		mEntityMap[S("nabla")]		= 0x2207;	// HTML 4.0 	nabla
		mEntityMap[S("notin")]		= 0x2209;	// HTML 4.0 	not an element of
		mEntityMap[S("ni")]			= 0x220B;	// HTML 4.0 	contains as member
		mEntityMap[S("ne")]			= 0x2260;	// HTML 4.0 	not equal to
		mEntityMap[S("nsub")]		= 0x2284;	// HTML 4.0 	not a subset of
		mEntityMap[S("ograve")]		= 0x00F2;	// HTML 2.0 	Latin small letter o with grave
		mEntityMap[S("oacute")]		= 0x00F3;	// HTML 2.0 	Latin small letter o with acute
		mEntityMap[S("ocirc")]		= 0x00F4;	// HTML 2.0 	Latin small letter o with circumflex
		mEntityMap[S("otilde")]		= 0x00F5;	// HTML 2.0 	Latin small letter o with tilde
		mEntityMap[S("ouml")]		= 0x00F6;	// HTML 2.0 	Latin small letter o with diaeresis
		mEntityMap[S("ordf")]		= 0x00AA;	// HTML 3.2 	feminine ordinal indicator
		mEntityMap[S("ordm")]		= 0x00BA;	// HTML 3.2 	masculine ordinal indicator
		mEntityMap[S("oslash")]		= 0x00F8;	// HTML 2.0 	Latin small letter o with stroke
		mEntityMap[S("oelig")]		= 0x0153;	// HTML 4.0 	Latin small ligature oe
		mEntityMap[S("omicron")]	= 0x03BF;	// HTML 4.0 	Greek small letter omicron
		mEntityMap[S("omega")]		= 0x03C9;	// HTML 4.0 	Greek small letter omega
		mEntityMap[S("oline")]		= 0x203E;	// HTML 4.0 	overline
		mEntityMap[S("or")]			= 0x2228;	// HTML 4.0 	logical or
		mEntityMap[S("oplus")]		= 0x2295;	// HTML 4.0 	circled plus
		mEntityMap[S("otimes")]		= 0x2297;	// HTML 4.0 	circled times
		mEntityMap[S("pound")]		= 0x00A3;	// HTML 3.2 	pound sign
		mEntityMap[S("plusmn")]		= 0x00B1;	// HTML 3.2 	plus-minus sign
		mEntityMap[S("para")]		= 0x00B6;	// HTML 3.2 	pilcrow sign
		mEntityMap[S("pi")]			= 0x03C0;	// HTML 4.0 	Greek small letter pi
		mEntityMap[S("phi")]		= 0x03C6;	// HTML 4.0 	Greek small letter phi
		mEntityMap[S("psi")]		= 0x03C8;	// HTML 4.0 	Greek small letter psi
		mEntityMap[S("piv")]		= 0x03D6;	// HTML 4.0 	Greek pi symbol
		mEntityMap[S("permil")]		= 0x2030;	// HTML 4.0 	per mille sign
		mEntityMap[S("prime")]		= 0x2032;	// HTML 4.0 	prime
		mEntityMap[S("part")]		= 0x2202;	// HTML 4.0 	partial differential
		mEntityMap[S("prod")]		= 0x220F;	// HTML 4.0 	n-ary product
		mEntityMap[S("prop")]		= 0x221D;	// HTML 4.0 	proportional to
		mEntityMap[S("perp")]		= 0x22A5;	// HTML 4.0 	up tack (perpendicular sign in math)
		mEntityMap[S("quot")]		= 0x0022;	// XML 1.0, HTML 2.0	quotation mark
		mEntityMap[S("reg")]		= 0x00AE;	// HTML 3.2 	registered sign
		mEntityMap[S("raquo")]		= 0x00BB;	// HTML 3.2 	right-pointing double angle quotation mark
		mEntityMap[S("rho")]		= 0x03C1;	// HTML 4.0 	Greek small letter rho
		mEntityMap[S("rlm")]		= 0x200F;	// HTML 4.0 	right-to-left mark
		mEntityMap[S("rsquo")]		= 0x2019;	// HTML 4.0 	right single quotation mark
		mEntityMap[S("rdquo")]		= 0x201D;	// HTML 4.0 	right double quotation mark
		mEntityMap[S("rsaquo")]		= 0x203A;	// HTML 4.0 	single right-pointing angle quotation mark
		mEntityMap[S("real")]		= 0x211C;	// HTML 4.0 	black-letter capital r	 
		mEntityMap[S("rarr")]		= 0x2192;	// HTML 4.0 	rightwards arrow
		mEntityMap[S("rArr")]		= 0x21D2;	// HTML 4.0 	rightwards double arrow
		mEntityMap[S("radic")]		= 0x221A;	// HTML 4.0 	square root
		mEntityMap[S("rceil")]		= 0x2309;	// HTML 4.0 	right ceiling
		mEntityMap[S("rfloor")]		= 0x230B;	// HTML 4.0 	right floor
		mEntityMap[S("rang")]		= 0x232A;	// HTML 4.0 	right-pointing angle bracket
		mEntityMap[S("shy")]		= 0x00AD;	// HTML 3.2 	soft hyphen
		mEntityMap[S("sup2")]		= 0x00B2;	// HTML 3.2 	superscript two
		mEntityMap[S("sup3")]		= 0x00B3;	// HTML 3.2 	superscript three
		mEntityMap[S("sup1")]		= 0x00B9;	// HTML 3.2 	superscript one
		mEntityMap[S("sect")]		= 0x00A7;	// HTML 3.2 	section sign
		mEntityMap[S("szlig")]		= 0x00DF;	// HTML 2.0 	Latin small letter sharp s (German Eszett)
		mEntityMap[S("scaron")]		= 0x0161;	// HTML 4.0 	Latin small letter s with caron
		mEntityMap[S("sigmaf")]		= 0x03C2;	// HTML 4.0 	Greek small letter final sigma
		mEntityMap[S("sigma")]		= 0x03C3;	// HTML 4.0 	Greek small letter sigma
		mEntityMap[S("sbquo")]		= 0x201A;	// HTML 4.0 	single low-9 quotation mark
		mEntityMap[S("sum")]		= 0x2211;	// HTML 4.0 	n-ary summation
		mEntityMap[S("sim")]		= 0x223C;	// HTML 4.0 	tilde operator
		mEntityMap[S("sub")]		= 0x2282;	// HTML 4.0 	subset of
		mEntityMap[S("sup")]		= 0x2283;	// HTML 4.0 	superset of
		mEntityMap[S("sube")]		= 0x2286;	// HTML 4.0 	subset of or equal to
		mEntityMap[S("supe")]		= 0x2287;	// HTML 4.0 	superset of or equal to
		mEntityMap[S("sdot")]		= 0x22C5;	// HTML 4.0 	dot operator
		mEntityMap[S("spades")]		= 0x2660;	// HTML 4.0 	black spade suit
		mEntityMap[S("times")]		= 0x00D7;	// HTML 3.2 	multiplication sign
		mEntityMap[S("thorn")]		= 0x00FE;	// HTML 2.0 	Latin small letter thorn
		mEntityMap[S("tilde")]		= 0x02DC;	// HTML 4.0 	small tilde
		mEntityMap[S("theta")]		= 0x03B8;	// HTML 4.0 	Greek small letter theta
		mEntityMap[S("tau")]		= 0x03C4;	// HTML 4.0 	Greek small letter tau
		mEntityMap[S("thetasym")]	= 0x03D1;	// HTML 4.0 	Greek theta symbol
		mEntityMap[S("thinsp")]		= 0x2009;	// HTML 4.0 	thin space [3]
		mEntityMap[S("trade")]		= 0x2122;	// HTML 4.0 	trademark sign			 
		mEntityMap[S("there4")]		= 0x2234;	// HTML 4.0 	therefore
		mEntityMap[S("uml")]		= 0x00A8;	// HTML 3.2 	diaeresis
		mEntityMap[S("ugrave")]		= 0x00F9;	// HTML 2.0 	Latin small letter u with grave
		mEntityMap[S("uacute")]		= 0x00FA;	// HTML 2.0 	Latin small letter u with acute
		mEntityMap[S("ucirc")]		= 0x00FB;	// HTML 2.0 	Latin small letter u with circumflex
		mEntityMap[S("uuml")]		= 0x00FC;	// HTML 2.0 	Latin small letter u with diaeresis
		mEntityMap[S("upsilon")]	= 0x03C5;	// HTML 4.0 	Greek small letter upsilon
		mEntityMap[S("upsih")]		= 0x03D2;	// HTML 4.0 	Greek upsilon with hook symbol
		mEntityMap[S("uarr")]		= 0x2191;	// HTML 4.0 	upwards arrow			 
		mEntityMap[S("uArr")]		= 0x21D1;	// HTML 4.0 	upwards double arrow
		mEntityMap[S("weierp")]		= 0x2118;	// HTML 4.0 	script capital p (Weierstrass p)
		mEntityMap[S("xi")]			= 0x03BE;	// HTML 4.0 	Greek small letter xi
		mEntityMap[S("yen")]		= 0x00A5;	// HTML 3.2 	yen sign
		mEntityMap[S("yacute")]		= 0x00FD;	// HTML 2.0 	Latin small letter y with acute
		mEntityMap[S("yuml")]		= 0x00FF;	// HTML 2.0 	Latin small letter y with diaeresis
		mEntityMap[S("zeta")]		= 0x03B6;	// HTML 4.0 	Greek small letter zeta
		mEntityMap[S("zwnj")]		= 0x200C;	// HTML 4.0 	zero width non-joiner
		mEntityMap[S("zwj")]		= 0x200D;	// HTML 4.0 	zero width joiner
		mEntityMap[S("Agrave")]		= 0x00C0;	// HTML 2.0 	Latin capital letter a with grave
		mEntityMap[S("Aacute")]		= 0x00C1;	// HTML 2.0 	Latin capital letter a with acute
		mEntityMap[S("Acirc")]		= 0x00C2;	// HTML 2.0 	Latin capital letter a with circumflex
		mEntityMap[S("Atilde")]		= 0x00C3;	// HTML 2.0 	Latin capital letter a with tilde
		mEntityMap[S("Auml")]		= 0x00C4;	// HTML 2.0 	Latin capital letter a with diaeresis
		mEntityMap[S("Aring")]		= 0x00C5;	// HTML 2.0 	Latin capital letter a with ring above
		mEntityMap[S("AElig")]		= 0x00C6;	// HTML 2.0 	Latin capital letter ae
		mEntityMap[S("Alpha")]		= 0x0391;	// HTML 4.0 	Greek capital letter alpha
		mEntityMap[S("Beta")]		= 0x0392;	// HTML 4.0 	Greek capital letter beta
		mEntityMap[S("Ccedil")]		= 0x00C7;	// HTML 2.0 	Latin capital letter c with cedilla
		mEntityMap[S("Chi")]		= 0x03A7;	// HTML 4.0 	Greek capital letter chi
		mEntityMap[S("Delta")]		= 0x0394;	// HTML 4.0 	Greek capital letter delta
		mEntityMap[S("Dagger")]		= 0x2021;	// HTML 4.0 	double dagger
		mEntityMap[S("Egrave")]		= 0x00C8;	// HTML 2.0 	Latin capital letter e with grave
		mEntityMap[S("Eacute")]		= 0x00C9;	// HTML 2.0 	Latin capital letter e with acute
		mEntityMap[S("Ecirc")]		= 0x00CA;	// HTML 2.0 	Latin capital letter e with circumflex
		mEntityMap[S("Euml")]		= 0x00CB;	// HTML 2.0 	Latin capital letter e with diaeresis
		mEntityMap[S("ETH")]		= 0x00D0;	// HTML 2.0 	Latin capital letter eth
		mEntityMap[S("Epsilon")]	= 0x0395;	// HTML 4.0 	Greek capital letter epsilon
		mEntityMap[S("Eta")]		= 0x0397;	// HTML 4.0 	Greek capital letter eta
		mEntityMap[S("Gamma")]		= 0x0393;	// HTML 4.0 	Greek capital letter gamma
		mEntityMap[S("Igrave")]		= 0x00CC;	// HTML 2.0 	Latin capital letter i with grave
		mEntityMap[S("Iacute")]		= 0x00CD;	// HTML 2.0 	Latin capital letter i with acute
		mEntityMap[S("Icirc")]		= 0x00CE;	// HTML 2.0 	Latin capital letter i with circumflex
		mEntityMap[S("Iuml")]		= 0x00CF;	// HTML 2.0 	Latin capital letter i with diaeresis
		mEntityMap[S("Iota")]		= 0x0399;	// HTML 4.0 	Greek capital letter iota
		mEntityMap[S("Kappa")]		= 0x039A;	// HTML 4.0 	Greek capital letter kappa
		mEntityMap[S("Lambda")]		= 0x039B;	// HTML 4.0 	Greek capital letter lambda
		mEntityMap[S("Mu")]			= 0x039C;	// HTML 4.0 	Greek capital letter mu
		mEntityMap[S("Ntilde")]		= 0x00D1;	// HTML 2.0 	Latin capital letter n with tilde
		mEntityMap[S("Nu")]			= 0x039D;	// HTML 4.0 	Greek capital letter nu
		mEntityMap[S("Ograve")]		= 0x00D2;	// HTML 2.0 	Latin capital letter o with grave
		mEntityMap[S("Oacute")]		= 0x00D3;	// HTML 2.0 	Latin capital letter o with acute
		mEntityMap[S("Ocirc")]		= 0x00D4;	// HTML 2.0 	Latin capital letter o with circumflex
		mEntityMap[S("Otilde")]		= 0x00D5;	// HTML 2.0 	Latin capital letter o with tilde
		mEntityMap[S("Ouml")]		= 0x00D6;	// HTML 2.0 	Latin capital letter o with diaeresis
		mEntityMap[S("Oslash")]		= 0x00D8;	// HTML 2.0 	Latin capital letter o with stroke
		mEntityMap[S("OElig")]		= 0x0152;	// HTML 4.0 	Latin capital ligature oe
		mEntityMap[S("Omicron")]	= 0x039F;	// HTML 4.0 	Greek capital letter omicron
		mEntityMap[S("Omega")]		= 0x03A9;	// HTML 4.0 	Greek capital letter omega
		mEntityMap[S("Pi")]			= 0x03A0;	// HTML 4.0 	Greek capital letter pi
		mEntityMap[S("Phi")]		= 0x03A6;	// HTML 4.0 	Greek capital letter phi
		mEntityMap[S("Psi")]		= 0x03A8;	// HTML 4.0 	Greek capital letter psi
		mEntityMap[S("Prime")]		= 0x2033;	// HTML 4.0 	double prime
		mEntityMap[S("Rho")]		= 0x03A1;	// HTML 4.0 	Greek capital letter rho
		mEntityMap[S("Scaron")]		= 0x0160;	// HTML 4.0 	Latin capital letter s with caron
		mEntityMap[S("Sigma")]		= 0x03A3;	// HTML 4.0 	Greek capital letter sigma
		mEntityMap[S("THORN")]		= 0x00DE;	// HTML 2.0 	Latin capital letter thorn
		mEntityMap[S("Theta")]		= 0x0398;	// HTML 4.0 	Greek capital letter theta
		mEntityMap[S("Tau")]		= 0x03A4;	// HTML 4.0 	Greek capital letter tau
		mEntityMap[S("Ugrave")]		= 0x00D9;	// HTML 2.0 	Latin capital letter u with grave
		mEntityMap[S("Uacute")]		= 0x00DA;	// HTML 2.0 	Latin capital letter u with acute
		mEntityMap[S("Ucirc")]		= 0x00DB;	// HTML 2.0 	Latin capital letter u with circumflex
		mEntityMap[S("Uuml")]		= 0x00DC;	// HTML 2.0 	Latin capital letter u with diaeresis
		mEntityMap[S("Upsilon")]	= 0x03A5;	// HTML 4.0 	Greek capital letter upsilon
		mEntityMap[S("Xi")]			= 0x039E;	// HTML 4.0 	Greek capital letter xi
		mEntityMap[S("Yacute")]		= 0x00DD;	// HTML 2.0 	Latin capital letter y with acute
		mEntityMap[S("Yuml")]		= 0x0178;	// HTML 4.0 	Latin capital letter y with diaeresis
		mEntityMap[S("Zeta")]		= 0x0396;	// HTML 4.0 	Greek capital letter zeta
	}
};

class EmptyString {
public:
	static const DOMString& get() {
		return boost::details::pool::singleton_default<EmptyString>::instance().mValue;
	}
private:
	friend boost::details::pool::singleton_default<EmptyString>;
	DOMString mValue;
	EmptyString() { }
};

unsigned short DOMUtils::translateXMLEntity(const DOMString& entity) {
	if (0==entity.find(S("#"),0,1)) {
		// Numerical entity
		if (0==entity.find(S("#x"),0,2)) {
			// Hexadecimal
			std::basic_istringstream<unsigned short> iss(entity.substr(2,entity.length()-2));
			unsigned short us;
			iss >> std::hex >> us;
			return us;
		}
		else {
			// Decimal
			std::basic_istringstream<unsigned short> iss(entity.substr(1,entity.length()-1));
			unsigned short us; 
			iss >> us; 
			return us;
		}
	}
	return EntityDatabase::get(entity);
}


void DOMUtils::explodeString(const DOMString& src, const DOMString& separator, std::vector<DOMString>& output) {
	output.clear();
	boost::char_separator<unsigned short> sep(separator.data());
	DOMTokenizer tokens(src, sep);
	DOMTokenizer::iterator it = tokens.begin();
 
	while(it != tokens.end())
		output.push_back(*(it++));
}

const DOMString& DOMUtils::emptyString() {
	return EmptyString::get();
}

