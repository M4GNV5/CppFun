#ifndef _CPPFUN_COMMON_H
#define _CPPFUN_COMMON_H

#define JOIN2(a, b) a##_##b
#define JOIN3(a, b, c) a##_##b##_##c
#define JOIN4(a, b, c, d) a##_##b##_##c##_##d

#define EVAL(...) __VA_ARGS__
#define APPLY(F, ...) F(__VA_ARGS__)



#define LIST_HEAD(X, ...) X
#define LIST_TAIL(X, ...) (__VA_ARGS__)

#define HEAD(L) LIST_HEAD L
#define TAIL(L) LIST_TAIL L

#endif
