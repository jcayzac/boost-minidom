#if !defined(DOM_CONFIG_INCLUDED)
#define DOM_CONFIG_INCLUDED

#if defined(__GNUC__)
    /* GCC Wants friend classes to be specified as 'class' */
    #define TEMPLATED_FRIEND friend class
#elif defined(_MSC_VER)
    /* MSVC doesn't like "friend class" at all... */
    #define TEMPLATED_FRIEND friend
#else
    #define TEMPLATED_FRIEND friend class
#endif

#endif // DOM_CONFIG_INCLUDED

