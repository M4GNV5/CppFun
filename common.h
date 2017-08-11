#ifndef _CPPFUN_COMMON_H
#define _CPPFUN_COMMON_H

#define JOIN2(a, b) a##_##b
#define JOIN3(a, b, c) a##_##b##_##c
#define JOIN4(a, b, c, d) a##_##b##_##c##_##d

#define EVAL(...) __VA_ARGS__
#define APPLY(F, ...) F(__VA_ARGS__)

#define APPLY0(F, ...) F(__VA_ARGS__)
#define APPLY1(F, ...) F(__VA_ARGS__)
#define APPLY2(F, ...) F(__VA_ARGS__)
#define APPLY3(F, ...) F(__VA_ARGS__)
#define APPLY4(F, ...) F(__VA_ARGS__)
#define APPLY5(F, ...) F(__VA_ARGS__)
#define APPLY6(F, ...) F(__VA_ARGS__)



#define _HEAD(X, ...) X
#define HEAD(X) _HEAD X

#define _TAIL(X, ...) (__VA_ARGS__)
#define TAIL(X) _TAIL X

#endif
