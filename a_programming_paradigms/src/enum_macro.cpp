// taken from https://stackoverflow.com/a/5094430
// I am using this macro in the interest of extensibility. This way we don't need to add an element to the switch case of the to_string function when we add an enum, as the stackoverflow answer explains.
#include <boost/preprocessor.hpp>

namespace util
{
    #define X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE(r, data, elem)    \
        case elem : return BOOST_PP_STRINGIZE(elem);

    #define DEFINE_ENUM_WITH_STRING_CONVERSIONS(name, enumerators)                \
        enum name {                                                               \
            BOOST_PP_SEQ_ENUM(enumerators)                                        \
        };                                                                        \
                                                                                \
        inline const char* ToString(name v)                                       \
        {                                                                         \
            switch (v)                                                            \
            {                                                                     \
                BOOST_PP_SEQ_FOR_EACH(                                            \
                    X_DEFINE_ENUM_WITH_STRING_CONVERSIONS_TOSTRING_CASE,          \
                    name,                                                         \
                    enumerators                                                   \
                )                                                                 \
                default: return "[Unknown " BOOST_PP_STRINGIZE(name) "]";         \
            }                                                                     \
        }
}
