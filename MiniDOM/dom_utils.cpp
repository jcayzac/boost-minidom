#include <map>
#include "dom_utils.hpp"

#define S(x) (const unsigned short* const)L##x
#define C(x) ((unsigned short)x)


static const std::map<DOMString,unsigned short>& GetEntityMap() {
	static std::map<DOMString,unsigned short> gEntityMap;
	if (gEntityMap.empty()) {
		gEntityMap[S("amp")]=0x0026;
	}
	return gEntityMap;
}




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
	else {
		// Character entities
		switch(entity[0]) {
		case C('a'):
			if (entity==S("amp"))		return 0x0026;	// XML 1.0, HTML 2.0	ampersand
			if (entity==S("apos"))		return 0x0027;	// XML 1.0, XHTML		apostrophe
			if (entity==S("acute"))		return 0x00B4;	// HTML 3.2 	acute accent
			if (entity==S("agrave"))	return 0x00E0;	// HTML 2.0 	Latin small letter a with grave
			if (entity==S("aacute"))	return 0x00E1;	// HTML 2.0 	Latin small letter a with acute
			if (entity==S("acirc"))		return 0x00E2;	// HTML 2.0 	Latin small letter a with circumflex
			if (entity==S("atilde"))	return 0x00E3;	// HTML 2.0 	Latin small letter a with tilde
			if (entity==S("auml"))		return 0x00E4;	// HTML 2.0 	Latin small letter a with diaeresis
			if (entity==S("aring"))		return 0x00E5;	// HTML 2.0 	Latin small letter a with ring above
			if (entity==S("aelig"))		return 0x00E6;	// HTML 2.0 	Latin lowercase ligature ae
			if (entity==S("alpha"))		return 0x03B1;	// HTML 4.0 	Greek small letter alpha
			if (entity==S("alefsym"))	return 0x2135;	// HTML 4.0 	alef symbol			 
			if (entity==S("ang"))		return 0x2220;	// HTML 4.0 	angle
			if (entity==S("and"))		return 0x2227;	// HTML 4.0 	logical and
			if (entity==S("asymp"))		return 0x2248;	// HTML 4.0 	almost equal to
			break;
		case C('b'):
			if (entity==S("brvbar"))	return 0x00A6;	// HTML 3.2 	broken bar
			if (entity==S("beta"))		return 0x03B2;	// HTML 4.0 	Greek small letter beta
			if (entity==S("bdquo"))		return 0x201E;	// HTML 4.0 	double low-9 quotation mark
			if (entity==S("bull"))		return 0x2022;	// HTML 4.0 	bullet
			break;
		case C('c'):
			if (entity==S("copy"))		return 0x00A9;	// HTML 3.2 	copyright sign
			if (entity==S("ccedil"))	return 0x00E7;	// HTML 2.0 	Latin small letter c with cedilla
			if (entity==S("cent"))		return 0x00A2;	// HTML 3.2 	cent sign
			if (entity==S("curren"))	return 0x00A4;	// HTML 3.2 	currency sign
			if (entity==S("cedil"))		return 0x00B8;	// HTML 3.2 	cedilla
			if (entity==S("circ"))		return 0x02C6;	// HTML 4.0 	modifier letter circumflex accent
			if (entity==S("chi"))		return 0x03C7;	// HTML 4.0 	Greek small letter chi
			if (entity==S("crarr"))		return 0x21B5;	// HTML 4.0 	downwards arrow with corner leftwards
			if (entity==S("cap"))		return 0x2229;	// HTML 4.0 	intersection
			if (entity==S("cup"))		return 0x222A;	// HTML 4.0 	union
			if (entity==S("cong"))		return 0x2245;	// HTML 4.0 	congruent to
			if (entity==S("clubs"))		return 0x2663;	// HTML 4.0 	black club suit
			break;
		case C('d'):
			if (entity==S("deg"))		return 0x00B0;	// HTML 3.2 	degree sign
			if (entity==S("divide"))	return 0x00F7;	// HTML 3.2 	division sign
			if (entity==S("delta"))		return 0x03B4;	// HTML 4.0 	Greek small letter delta
			if (entity==S("dagger"))	return 0x2020;	// HTML 4.0 	dagger
			if (entity==S("darr"))		return 0x2193;	// HTML 4.0 	downwards arrow
			if (entity==S("dArr"))		return 0x21D3;	// HTML 4.0 	downwards double arrow
			if (entity==S("diams"))		return 0x2666;	// HTML 4.0 	black diamond suit
			break;
		case C('e'):
			if (entity==S("egrave"))	return 0x00E8;	// HTML 2.0 	Latin small letter e with grave
			if (entity==S("eacute"))	return 0x00E9;	// HTML 2.0 	Latin small letter e with acute
			if (entity==S("ecirc"))		return 0x00EA;	// HTML 2.0 	Latin small letter e with circumflex
			if (entity==S("euml"))		return 0x00EB;	// HTML 2.0 	Latin small letter e with diaeresis
			if (entity==S("eth"))		return 0x00F0;	// HTML 2.0 	Latin small letter eth
			if (entity==S("epsilon"))	return 0x03B5;	// HTML 4.0 	Greek small letter epsilon
			if (entity==S("eta"))		return 0x03B7;	// HTML 4.0 	Greek small letter eta
			if (entity==S("ensp"))		return 0x2002;	// HTML 4.0 	en space [1]
			if (entity==S("emsp"))		return 0x2003;	// HTML 4.0 	em space [2]
			if (entity==S("euro"))		return 0x20AC;	// HTML 4.0 	euro sign
			if (entity==S("exist"))		return 0x2203;	// HTML 4.0 	there exists
			if (entity==S("empty"))		return 0x2205;	// HTML 4.0 	empty set
			if (entity==S("equiv"))		return 0x2261;	// HTML 4.0 	identical to (equivalent to)
			break;
		case C('f'):
			if (entity==S("frac14"))	return 0x00BC;	// HTML 3.2 	vulgar fraction one quarter
			if (entity==S("frac12"))	return 0x00BD;	// HTML 3.2 	vulgar fraction one half
			if (entity==S("frac34"))	return 0x00BE;	// HTML 3.2 	vulgar fraction three quarters
			if (entity==S("fnof"))		return 0x0192;	// HTML 4.0 	Latin small letter f with hook
			if (entity==S("frasl"))		return 0x2044;	// HTML 4.0 	fraction slash
			if (entity==S("forall"))	return 0x2200;	// HTML 4.0 	for all
			break;
		case C('g'):
			if (entity==S("gt"))		return 0x003e;	// XML 1.0, HTML 2.0	greater-than sign
			if (entity==S("gamma"))		return 0x03B3;	// HTML 4.0 	Greek small letter gamma
			if (entity==S("ge"))		return 0x2265;	// HTML 4.0 	greater-than or equal to
			break;
		case C('h'):
			if (entity==S("hellip"))	return 0x2026;	// HTML 4.0 	horizontal ellipsis
			if (entity==S("harr"))		return 0x2194;	// HTML 4.0 	left right arrow
			if (entity==S("hArr"))		return 0x21D4;	// HTML 4.0 	left right double arrow
			if (entity==S("hearts"))	return 0x2665;	// HTML 4.0 	black heart suit
			break;
		case L'i':
			if (entity==S("igrave"))	return 0x00EC;	// HTML 2.0 	Latin small letter i with grave
			if (entity==S("iacute"))	return 0x00ED;	// HTML 2.0 	Latin small letter i with acute
			if (entity==S("icirc"))	return 0x00EE;	// HTML 2.0 	Latin small letter i with circumflex
			if (entity==S("iuml"))		return 0x00EF;	// HTML 2.0 	Latin small letter i with diaeresis
			if (entity==S("iexcl"))	return 0x00A1;	// HTML 3.2 	inverted exclamation mark
			if (entity==S("iquest"))	return 0x00BF;	// HTML 3.2 	inverted question mark
			if (entity==S("iota"))		return 0x03B9;	// HTML 4.0 	Greek small letter iota
			if (entity==S("image"))	return 0x2111;	// HTML 4.0 	black-letter capital i
			if (entity==S("isin"))		return 0x2208;	// HTML 4.0 	element of
			if (entity==S("infin"))	return 0x221E;	// HTML 4.0 	infinity
			if (entity==S("int"))		return 0x222B;	// HTML 4.0 	integral
		case L'k':
			if (entity==S("kappa"))	return 0x03BA;	// HTML 4.0 	Greek small letter kappa
			break;
		case L'l':
			if (entity==S("lt"))		return 0x003c;	// XML 1.0, HTML 2.0	less-than sign
			if (entity==S("laquo"))	return 0x00AB;	// HTML 3.2 	left-pointing double angle quotation mark
			if (entity==S("lambda"))	return 0x03BB;	// HTML 4.0 	Greek small letter lambda
			if (entity==S("lrm"))		return 0x200E;	// HTML 4.0 	left-to-right mark
			if (entity==S("lsquo"))	return 0x2018;	// HTML 4.0 	left single quotation mark
			if (entity==S("ldquo"))	return 0x201C;	// HTML 4.0 	left double quotation mark
			if (entity==S("larr"))		return 0x2190;	// HTML 4.0 	leftwards arrow			 
			if (entity==S("lsaquo"))	return 0x2039;	// HTML 4.0 	single left-pointing angle quotation mark
			if (entity==S("lArr"))		return 0x21D0;	// HTML 4.0 	leftwards double arrow
			if (entity==S("lowast"))	return 0x2217;	// HTML 4.0 	asterisk operator
			if (entity==S("le"))		return 0x2264;	// HTML 4.0 	less-than or equal to
			if (entity==S("lceil"))	return 0x2308;	// HTML 4.0 	left ceiling
			if (entity==S("lfloor"))	return 0x230A;	// HTML 4.0 	left floor
			if (entity==S("lang"))		return 0x2329;	// HTML 4.0 	left-pointing angle bracket
			if (entity==S("loz"))		return 0x25CA;	// HTML 4.0 	lozenge
			break;
		case L'm':
			if (entity==S("macr"))		return 0x00AF;	// HTML 3.2 	macron
			if (entity==S("micro"))	return 0x00B5;	// HTML 3.2 	micro sign
			if (entity==S("middot"))	return 0x00B7;	// HTML 3.2 	middle dot
			if (entity==S("mu"))		return 0x03BC;	// HTML 4.0 	Greek small letter mu
			if (entity==S("mdash"))	return 0x2014;	// HTML 4.0 	em dash
			if (entity==S("minus"))	return 0x2212;	// HTML 4.0 	minus sign
			break;
		case L'n':
			if (entity==S("nbsp"))		return 0x00A0;	// HTML 3.2 	non-breaking space
			if (entity==S("ntilde"))	return 0x00F1;	// HTML 2.0 	Latin small letter n with tilde
			if (entity==S("not"))		return 0x00AC;	// HTML 3.2 	not sign
			if (entity==S("nu"))		return 0x03BD;	// HTML 4.0 	Greek small letter nu
			if (entity==S("ndash"))	return 0x2013;	// HTML 4.0 	en dash
			if (entity==S("nabla"))	return 0x2207;	// HTML 4.0 	nabla
			if (entity==S("notin"))	return 0x2209;	// HTML 4.0 	not an element of
			if (entity==S("ni"))		return 0x220B;	// HTML 4.0 	contains as member
			if (entity==S("ne"))		return 0x2260;	// HTML 4.0 	not equal to
			if (entity==S("nsub"))		return 0x2284;	// HTML 4.0 	not a subset of
			break;
		case L'o':
			if (entity==S("ograve"))	return 0x00F2;	// HTML 2.0 	Latin small letter o with grave
			if (entity==S("oacute"))	return 0x00F3;	// HTML 2.0 	Latin small letter o with acute
			if (entity==S("ocirc"))	return 0x00F4;	// HTML 2.0 	Latin small letter o with circumflex
			if (entity==S("otilde"))	return 0x00F5;	// HTML 2.0 	Latin small letter o with tilde
			if (entity==S("ouml"))		return 0x00F6;	// HTML 2.0 	Latin small letter o with diaeresis
			if (entity==S("ordf"))		return 0x00AA;	// HTML 3.2 	feminine ordinal indicator
			if (entity==S("ordm"))		return 0x00BA;	// HTML 3.2 	masculine ordinal indicator
			if (entity==S("oslash"))	return 0x00F8;	// HTML 2.0 	Latin small letter o with stroke
			if (entity==S("oelig"))	return 0x0153;	// HTML 4.0 	Latin small ligature oe
			if (entity==S("omicron"))	return 0x03BF;	// HTML 4.0 	Greek small letter omicron
			if (entity==S("omega"))	return 0x03C9;	// HTML 4.0 	Greek small letter omega
			if (entity==S("oline"))	return 0x203E;	// HTML 4.0 	overline
			if (entity==S("or"))		return 0x2228;	// HTML 4.0 	logical or
			if (entity==S("oplus"))	return 0x2295;	// HTML 4.0 	circled plus
			if (entity==S("otimes"))	return 0x2297;	// HTML 4.0 	circled times
			break;
		case L'p':
			if (entity==S("pound"))	return 0x00A3;	// HTML 3.2 	pound sign
			if (entity==S("plusmn"))	return 0x00B1;	// HTML 3.2 	plus-minus sign
			if (entity==S("para"))		return 0x00B6;	// HTML 3.2 	pilcrow sign
			if (entity==S("pi"))		return 0x03C0;	// HTML 4.0 	Greek small letter pi
			if (entity==S("phi"))		return 0x03C6;	// HTML 4.0 	Greek small letter phi
			if (entity==S("psi"))		return 0x03C8;	// HTML 4.0 	Greek small letter psi
			if (entity==S("piv"))		return 0x03D6;	// HTML 4.0 	Greek pi symbol
			if (entity==S("permil"))	return 0x2030;	// HTML 4.0 	per mille sign
			if (entity==S("prime"))	return 0x2032;	// HTML 4.0 	prime
			if (entity==S("part"))		return 0x2202;	// HTML 4.0 	partial differential
			if (entity==S("prod"))		return 0x220F;	// HTML 4.0 	n-ary product
			if (entity==S("prop"))		return 0x221D;	// HTML 4.0 	proportional to
			if (entity==S("perp"))		return 0x22A5;	// HTML 4.0 	up tack (perpendicular sign in math)
			break;
		case L'q':
			if (entity==S("quot"))		return 0x0022;	// XML 1.0, HTML 2.0	quotation mark
			break;
		case L'r':
			if (entity==S("reg"))		return 0x00AE;	// HTML 3.2 	registered sign
			if (entity==S("raquo"))	return 0x00BB;	// HTML 3.2 	right-pointing double angle quotation mark
			if (entity==S("rho"))		return 0x03C1;	// HTML 4.0 	Greek small letter rho
			if (entity==S("rlm"))		return 0x200F;	// HTML 4.0 	right-to-left mark
			if (entity==S("rsquo"))	return 0x2019;	// HTML 4.0 	right single quotation mark
			if (entity==S("rdquo"))	return 0x201D;	// HTML 4.0 	right double quotation mark
			if (entity==S("rsaquo"))	return 0x203A;	// HTML 4.0 	single right-pointing angle quotation mark
			if (entity==S("real"))		return 0x211C;	// HTML 4.0 	black-letter capital r	 
			if (entity==S("rarr"))		return 0x2192;	// HTML 4.0 	rightwards arrow
			if (entity==S("rArr"))		return 0x21D2;	// HTML 4.0 	rightwards double arrow
			if (entity==S("radic"))	return 0x221A;	// HTML 4.0 	square root
			if (entity==S("rceil"))	return 0x2309;	// HTML 4.0 	right ceiling
			if (entity==S("rfloor"))	return 0x230B;	// HTML 4.0 	right floor
			if (entity==S("rang"))		return 0x232A;	// HTML 4.0 	right-pointing angle bracket
			break;
		case L's':
			if (entity==S("shy"))		return 0x00AD;	// HTML 3.2 	soft hyphen
			if (entity==S("sup2"))		return 0x00B2;	// HTML 3.2 	superscript two
			if (entity==S("sup3"))		return 0x00B3;	// HTML 3.2 	superscript three
			if (entity==S("sup1"))		return 0x00B9;	// HTML 3.2 	superscript one
			if (entity==S("sect"))		return 0x00A7;	// HTML 3.2 	section sign
			if (entity==S("szlig"))	return 0x00DF;	// HTML 2.0 	Latin small letter sharp s (German Eszett)
			if (entity==S("scaron"))	return 0x0161;	// HTML 4.0 	Latin small letter s with caron
			if (entity==S("sigmaf"))	return 0x03C2;	// HTML 4.0 	Greek small letter final sigma
			if (entity==S("sigma"))	return 0x03C3;	// HTML 4.0 	Greek small letter sigma
			if (entity==S("sbquo"))	return 0x201A;	// HTML 4.0 	single low-9 quotation mark
			if (entity==S("sum"))		return 0x2211;	// HTML 4.0 	n-ary summation
			if (entity==S("sim"))		return 0x223C;	// HTML 4.0 	tilde operator
			if (entity==S("sub"))		return 0x2282;	// HTML 4.0 	subset of
			if (entity==S("sup"))		return 0x2283;	// HTML 4.0 	superset of
			if (entity==S("sube"))		return 0x2286;	// HTML 4.0 	subset of or equal to
			if (entity==S("supe"))		return 0x2287;	// HTML 4.0 	superset of or equal to
			if (entity==S("sdot"))		return 0x22C5;	// HTML 4.0 	dot operator
			if (entity==S("spades"))	return 0x2660;	// HTML 4.0 	black spade suit
			break;
		case L't':
			if (entity==S("times"))	return 0x00D7;	// HTML 3.2 	multiplication sign
			if (entity==S("thorn"))	return 0x00FE;	// HTML 2.0 	Latin small letter thorn
			if (entity==S("tilde"))	return 0x02DC;	// HTML 4.0 	small tilde
			if (entity==S("theta"))	return 0x03B8;	// HTML 4.0 	Greek small letter theta
			if (entity==S("tau"))		return 0x03C4;	// HTML 4.0 	Greek small letter tau
			if (entity==S("thetasym"))	return 0x03D1;	// HTML 4.0 	Greek theta symbol
			if (entity==S("thinsp"))	return 0x2009;	// HTML 4.0 	thin space [3]
			if (entity==S("trade"))	return 0x2122;	// HTML 4.0 	trademark sign			 
			if (entity==S("there4"))	return 0x2234;	// HTML 4.0 	therefore
			break;
		case L'u':
			if (entity==S("uml"))		return 0x00A8;	// HTML 3.2 	diaeresis
			if (entity==S("ugrave"))	return 0x00F9;	// HTML 2.0 	Latin small letter u with grave
			if (entity==S("uacute"))	return 0x00FA;	// HTML 2.0 	Latin small letter u with acute
			if (entity==S("ucirc"))	return 0x00FB;	// HTML 2.0 	Latin small letter u with circumflex
			if (entity==S("uuml"))		return 0x00FC;	// HTML 2.0 	Latin small letter u with diaeresis
			if (entity==S("upsilon"))	return 0x03C5;	// HTML 4.0 	Greek small letter upsilon
			if (entity==S("upsih"))	return 0x03D2;	// HTML 4.0 	Greek upsilon with hook symbol
			if (entity==S("uarr"))		return 0x2191;	// HTML 4.0 	upwards arrow			 
			if (entity==S("uArr"))		return 0x21D1;	// HTML 4.0 	upwards double arrow
			break;
		case L'w':
			if (entity==S("weierp"))	return 0x2118;	// HTML 4.0 	script capital p (Weierstrass p)
			break;
		case L'x':
			if (entity==S("xi"))		return 0x03BE;	// HTML 4.0 	Greek small letter xi
			break;
		case L'y':
			if (entity==S("yen"))		return 0x00A5;	// HTML 3.2 	yen sign
			if (entity==S("yacute"))	return 0x00FD;	// HTML 2.0 	Latin small letter y with acute
			if (entity==S("yuml"))		return 0x00FF;	// HTML 2.0 	Latin small letter y with diaeresis
			break;
		case L'z':
			if (entity==S("zeta"))		return 0x03B6;	// HTML 4.0 	Greek small letter zeta
			if (entity==S("zwnj"))		return 0x200C;	// HTML 4.0 	zero width non-joiner
			if (entity==S("zwj"))		return 0x200D;	// HTML 4.0 	zero width joiner
			break;
		case L'A':
			if (entity==S("Agrave"))	return 0x00C0;	// HTML 2.0 	Latin capital letter a with grave
			if (entity==S("Aacute"))	return 0x00C1;	// HTML 2.0 	Latin capital letter a with acute
			if (entity==S("Acirc"))	return 0x00C2;	// HTML 2.0 	Latin capital letter a with circumflex
			if (entity==S("Atilde"))	return 0x00C3;	// HTML 2.0 	Latin capital letter a with tilde
			if (entity==S("Auml"))		return 0x00C4;	// HTML 2.0 	Latin capital letter a with diaeresis
			if (entity==S("Aring"))	return 0x00C5;	// HTML 2.0 	Latin capital letter a with ring above
			if (entity==S("AElig"))	return 0x00C6;	// HTML 2.0 	Latin capital letter ae
			if (entity==S("Alpha"))	return 0x0391;	// HTML 4.0 	Greek capital letter alpha
			break;
		case L'B':
			if (entity==S("Beta"))		return 0x0392;	// HTML 4.0 	Greek capital letter beta
			break;
		case L'C':
			if (entity==S("Ccedil"))	return 0x00C7;	// HTML 2.0 	Latin capital letter c with cedilla
			if (entity==S("Chi"))		return 0x03A7;	// HTML 4.0 	Greek capital letter chi
			break;
		case L'D':
			if (entity==S("Delta"))	return 0x0394;	// HTML 4.0 	Greek capital letter delta
			if (entity==S("Dagger"))	return 0x2021;	// HTML 4.0 	double dagger
			break;
		case L'E':
			if (entity==S("Egrave"))	return 0x00C8;	// HTML 2.0 	Latin capital letter e with grave
			if (entity==S("Eacute"))	return 0x00C9;	// HTML 2.0 	Latin capital letter e with acute
			if (entity==S("Ecirc"))	return 0x00CA;	// HTML 2.0 	Latin capital letter e with circumflex
			if (entity==S("Euml"))		return 0x00CB;	// HTML 2.0 	Latin capital letter e with diaeresis
			if (entity==S("ETH"))		return 0x00D0;	// HTML 2.0 	Latin capital letter eth
			if (entity==S("Epsilon"))	return 0x0395;	// HTML 4.0 	Greek capital letter epsilon
			if (entity==S("Eta"))		return 0x0397;	// HTML 4.0 	Greek capital letter eta
			break;
		case L'G':
			if (entity==S("Gamma"))	return 0x0393;	// HTML 4.0 	Greek capital letter gamma
			break;
		case L'I':
			if (entity==S("Igrave"))	return 0x00CC;	// HTML 2.0 	Latin capital letter i with grave
			if (entity==S("Iacute"))	return 0x00CD;	// HTML 2.0 	Latin capital letter i with acute
			if (entity==S("Icirc"))	return 0x00CE;	// HTML 2.0 	Latin capital letter i with circumflex
			if (entity==S("Iuml"))		return 0x00CF;	// HTML 2.0 	Latin capital letter i with diaeresis
			if (entity==S("Iota"))		return 0x0399;	// HTML 4.0 	Greek capital letter iota
			break;
		case L'K':
			if (entity==S("Kappa"))	return 0x039A;	// HTML 4.0 	Greek capital letter kappa
			break;
		case L'L':
			if (entity==S("Lambda"))	return 0x039B;	// HTML 4.0 	Greek capital letter lambda
			break;
		case L'M':
			if (entity==S("Mu"))		return 0x039C;	// HTML 4.0 	Greek capital letter mu
			break;
		case L'N':
			if (entity==S("Ntilde"))	return 0x00D1;	// HTML 2.0 	Latin capital letter n with tilde
			if (entity==S("Nu"))		return 0x039D;	// HTML 4.0 	Greek capital letter nu
			break;
		case L'O':
			if (entity==S("Ograve"))	return 0x00D2;	// HTML 2.0 	Latin capital letter o with grave
			if (entity==S("Oacute"))	return 0x00D3;	// HTML 2.0 	Latin capital letter o with acute
			if (entity==S("Ocirc"))	return 0x00D4;	// HTML 2.0 	Latin capital letter o with circumflex
			if (entity==S("Otilde"))	return 0x00D5;	// HTML 2.0 	Latin capital letter o with tilde
			if (entity==S("Ouml"))		return 0x00D6;	// HTML 2.0 	Latin capital letter o with diaeresis
			if (entity==S("Oslash"))	return 0x00D8;	// HTML 2.0 	Latin capital letter o with stroke
			if (entity==S("OElig"))	return 0x0152;	// HTML 4.0 	Latin capital ligature oe
			if (entity==S("Omicron"))	return 0x039F;	// HTML 4.0 	Greek capital letter omicron
			if (entity==S("Omega"))	return 0x03A9;	// HTML 4.0 	Greek capital letter omega
			break;
		case L'P':
			if (entity==S("Pi"))		return 0x03A0;	// HTML 4.0 	Greek capital letter pi
			if (entity==S("Phi"))		return 0x03A6;	// HTML 4.0 	Greek capital letter phi
			if (entity==S("Psi"))		return 0x03A8;	// HTML 4.0 	Greek capital letter psi
			if (entity==S("Prime"))	return 0x2033;	// HTML 4.0 	double prime
			break;
		case L'R':
			if (entity==S("Rho"))		return 0x03A1;	// HTML 4.0 	Greek capital letter rho
			break;
		case L'S':
			if (entity==S("Scaron"))	return 0x0160;	// HTML 4.0 	Latin capital letter s with caron
			if (entity==S("Sigma"))	return 0x03A3;	// HTML 4.0 	Greek capital letter sigma
			break;
		case L'T':
			if (entity==S("THORN"))	return 0x00DE;	// HTML 2.0 	Latin capital letter thorn
			if (entity==S("Theta"))	return 0x0398;	// HTML 4.0 	Greek capital letter theta
			if (entity==S("Tau"))		return 0x03A4;	// HTML 4.0 	Greek capital letter tau
			break;
		case L'U':
			if (entity==S("Ugrave"))	return 0x00D9;	// HTML 2.0 	Latin capital letter u with grave
			if (entity==S("Uacute"))	return 0x00DA;	// HTML 2.0 	Latin capital letter u with acute
			if (entity==S("Ucirc"))	return 0x00DB;	// HTML 2.0 	Latin capital letter u with circumflex
			if (entity==S("Uuml"))		return 0x00DC;	// HTML 2.0 	Latin capital letter u with diaeresis
			if (entity==S("Upsilon"))	return 0x03A5;	// HTML 4.0 	Greek capital letter upsilon
			break;
		case L'X':
			if (entity==S("Xi"))		return 0x039E;	// HTML 4.0 	Greek capital letter xi
			break;
		case L'Y':
			if (entity==S("Yacute"))	return 0x00DD;	// HTML 2.0 	Latin capital letter y with acute
			if (entity==S("Yuml"))		return 0x0178;	// HTML 4.0 	Latin capital letter y with diaeresis
			break;
		case L'Z':
			if (entity==S("Zeta"))		return 0x0396;	// HTML 4.0 	Greek capital letter zeta
			break;
		default: break;
		}
	}
	return 0; // bad entity!
}
