#ifndef _CPPFUN_COMPARE_H
#define _CPPFUN_COMPARE_H

#include "common.h"
#include "bitwise.h"
#include "math.h"

//equal
#define CMP_E(X, Y) ISZERO(XOR(X, Y))
//not equal
#define CMP_NE(X, Y) B_NOT(CMP_E(X, Y))

//above or equal
#define CMP_AE(X, Y) HEAD(ADC(X, NOT(Y), 1))
//below
#define CMP_B(X, Y) B_NOT(CMP_AE(X, Y))

//above
#define _CMP_A(res) HEAD(res), ISNONZERO(TAIL(res))
#define CMP_A(X, Y) _CMP_A(ADC(X, NOT(Y), 1))
//below or equal
#define CMP_BE(X, Y) B_NOT(CMP_A(X, Y))

#endif
