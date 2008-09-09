#if !defined(DOM_TEXT_INCLUDED)
#define DOM_TEXT_INCLUDED

#include "dom_node.hpp"

class Text: public Node {
private:
	Text(const Text&);
public:
	Text(const DOMString& data);
	virtual ~Text() { }

	// Interface CharacterData
	DOMString&			data()			{ return m_oValue; }
	const DOMString&	data() const	{ return m_oValue; }
	unsigned long		length() const	{ return (unsigned long)m_oValue.length(); }
	DOMString			substringData(unsigned long offset, unsigned long count) const;
	void				appendData(const DOMString& arg);
	void				insertData(unsigned long offset, const DOMString& arg);
	void				deleteData(unsigned long offset, unsigned long count);
	void				replaceData(unsigned long offset, unsigned long count, const DOMString& arg);
	//
	TextPtr				splitText(unsigned long offset);
	TextPtr				replaceWholeText(const DOMString& content);
	const DOMString&	wholeText() const;
	bool				isWhitespaceOnly() const;
	bool				isElementContentWhitespace() const;

	// From Node
	NodePtr	cloneNode(bool deep=false) const;
	bool	textContent(DOMString& output) const { output=m_oValue; return true; }
	void	setTextContent(const DOMString& newContent) { m_oValue=newContent; }
private:
	mutable DOMString m_oTempString;
};

#endif // DOM_TEXT_INCLUDED
