#if !defined(DOM_UTF8_CONFIG_INCLUDED)
#define DOM_UTF8_CONFIG_INCLUDED

#include <boost/program_options/config.hpp>

#define BOOST_UTF8_BEGIN_NAMESPACE \
    namespace dom { namespace utf8 {
#define BOOST_UTF8_END_NAMESPACE }}
#define BOOST_UTF8_DECL BOOST_PROGRAM_OPTIONS_DECL

# endif // DOM_UTF8_CONFIG_INCLUDED
