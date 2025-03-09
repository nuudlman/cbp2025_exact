#ifndef _PREDICTOR_H_
#define _PREDICTOR_H_

#include <stdlib.h>
#include <unordered_map>

#ifndef NDEBUG
#ifdef __clang__
#define unreachable() __builtin_debugtrap()
#else
#define unreachable() assert(false)
#endif
#else
#define unreachable() __builtin_unreachable()
#endif



// =================
// Predictor End
// =================

#endif
