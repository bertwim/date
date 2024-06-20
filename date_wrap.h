#ifndef DATE_WRAP_H
#define DATE_WRAP_H

// As chrono support is still incomplete with gcc 13.2.0, (std::chrono::format and
// std::chrono::parse are missing), use Howard Hinnant's date library as an alternative
// instead. Unfortunately, a few compiler warnings need to be disabled.
#define HOWARD_HINNANT

#ifdef HOWARD_HINNANT

#pragma GCC diagnostic push

#if defined( __clang__ )
#pragma GCC diagnostic ignored "-Wdeprecated-literal-operator"
#else
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif

//#include "3rdparty/date/include/date/date.h"
#include "./include/date/date.h"

#pragma GCC diagnostic pop

using date::format;
using date::parse;

#else
using std::chrono::format;
using std::chrono::parse;
#endif

#endif
