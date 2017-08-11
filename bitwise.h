#ifndef _CPPFUN_BITWISE_H
#define _CPPFUN_BITWISE_H

#include "common.h"

#define BYTE2ARG(b7, b6, b5, b4, b3, b2, b1, b0) b7, b6, b5, b4, b3, b2, b1, b0

#define _MAP(func, b7, b6, b5, b4, b3, b2, b1, b0) ( \
		func(b7),\
		func(b6),\
		func(b5),\
		func(b4),\
		func(b3),\
		func(b2),\
		func(b1),\
		func(b0)\
	)
#define MAP(func, val) APPLY(_MAP, func, BYTE2ARG val)

#define _MAP2(func, a7, a6, a5, a4, a3, a2, a1, a0, b7, b6, b5, b4, b3, b2, b1, b0) ( \
		func(a7, b7),\
		func(a6, b6),\
		func(a5, b5),\
		func(a4, b4),\
		func(a3, b3),\
		func(a2, b2),\
		func(a1, b1),\
		func(a0, b0)\
	)
#define MAP2(func, a, b) APPLY(_MAP2, func, BYTE2ARG a, BYTE2ARG b)

#define EXTRACT_BIT_7(b7, b6, b5, b4, b3, b2, b1, b0) b7
#define EXTRACT_BIT_6(b7, b6, b5, b4, b3, b2, b1, b0) b6
#define EXTRACT_BIT_5(b7, b6, b5, b4, b3, b2, b1, b0) b5
#define EXTRACT_BIT_4(b7, b6, b5, b4, b3, b2, b1, b0) b4
#define EXTRACT_BIT_3(b7, b6, b5, b4, b3, b2, b1, b0) b3
#define EXTRACT_BIT_2(b7, b6, b5, b4, b3, b2, b1, b0) b2
#define EXTRACT_BIT_1(b7, b6, b5, b4, b3, b2, b1, b0) b1
#define EXTRACT_BIT_0(b7, b6, b5, b4, b3, b2, b1, b0) b0
#define EXTRACT_BIT(val, index) JOIN2(EXTRACT_BIT, index) val

#define INSERT_BIT_7(b7, b6, b5, b4, b3, b2, b1, b0, bit) (bit, b6, b5, b4, b3, b2, b1, b0)
#define INSERT_BIT_6(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, bit, b5, b4, b3, b2, b1, b0)
#define INSERT_BIT_5(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, bit, b4, b3, b2, b1, b0)
#define INSERT_BIT_4(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, b5, bit, b3, b2, b1, b0)
#define INSERT_BIT_3(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, b5, b4, bit, b2, b1, b0)
#define INSERT_BIT_2(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, b5, b4, b3, bit, b1, b0)
#define INSERT_BIT_1(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, b5, b4, b3, b2, bit, b0)
#define INSERT_BIT_0(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, b5, b4, b3, b2, b1, bit)
#define INSERT_BIT(val, index, bit) APPLY(JOIN2(INSERT_BIT, index), BYTE2ARG val, bit)

#define _SHL1(b7, b6, b5, b4, b3, b2, b1, b0) (b6, b5, b4, b3, b2, b1, b0, 0)
#define SHL1(val) _SHL1 val

#define _SHR1(b7, b6, b5, b4, b3, b2, b1, b0) (0, b7, b6, b5, b4, b3, b2, b1)
#define SHR1(val) _SHR1 val

#define _SHLIN(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b6, b5, b4, b3, b2, b1, b0, bit)
#define SHLIN(val, bit) APPLY(_SHLIN, BYTE2ARG val, bit)

#define _SHRIN(b7, b6, b5, b4, b3, b2, b1, b0, bit) (bit, b7, b6, b5, b4, b3, b2, b1)
#define SHRIN(val, bit) APPLY(_SHRIN, BYTE2ARG val, bit)

#define SHL_4_1(b7, b6, b5, b4, b3, b2, b1, b0) b3, b2, b1, b0, 0, 0, 0, 0
#define SHL_2_1(b7, b6, b5, b4, b3, b2, b1, b0) b5, b4, b3, b2, b1, b0, 0, 0
#define SHL_1_1(b7, b6, b5, b4, b3, b2, b1, b0) b6, b5, b4, b3, b2, b1, b0, 0
#define SHL_4_0(b7, b6, b5, b4, b3, b2, b1, b0) b7, b6, b5, b4, b3, b2, b1, b0
#define SHL_2_0(b7, b6, b5, b4, b3, b2, b1, b0) b7, b6, b5, b4, b3, b2, b1, b0
#define SHL_1_0(b7, b6, b5, b4, b3, b2, b1, b0) b7, b6, b5, b4, b3, b2, b1, b0
#define _SHL(val, a7, a6, a5, a4, a3, a2, a1, a0) \
	(APPLY0(JOIN2(SHL_1, a0), \
		APPLY1(JOIN2(SHL_2, a1), \
			APPLY2(JOIN2(SHL_4, a2), BYTE2ARG val) \
		) \
	))
#define SHL(val, amount) APPLY(_SHL, val, BYTE2ARG amount)

#define SHR_4_1(b7, b6, b5, b4, b3, b2, b1, b0) 0, 0, 0, 0, b7, b6, b5, b4
#define SHR_2_1(b7, b6, b5, b4, b3, b2, b1, b0) 0, 0, b7, b6, b5, b4, b3, b2
#define SHR_1_1(b7, b6, b5, b4, b3, b2, b1, b0) 0, b7, b6, b5, b4, b3, b2, b1
#define SHR_4_0(b7, b6, b5, b4, b3, b2, b1, b0) b7, b6, b5, b4, b3, b2, b1, b0
#define SHR_2_0(b7, b6, b5, b4, b3, b2, b1, b0) b7, b6, b5, b4, b3, b2, b1, b0
#define SHR_1_0(b7, b6, b5, b4, b3, b2, b1, b0) b7, b6, b5, b4, b3, b2, b1, b0
#define _SHR(val, a7, a6, a5, a4, a3, a2, a1, a0) \
	(APPLY0(JOIN2(SHR_1, a0), \
		APPLY1(JOIN2(SHR_2, a1), \
			APPLY2(JOIN2(SHR_4, a2), BYTE2ARG val) \
		) \
	))
#define SHR(val, amount) APPLY(_SHR, val, BYTE2ARG amount)

#define _ISNONZERO(b7, b6, b5, b4, b3, b2, b1, b0) B_OR( \
			B_OR( \
				B_OR(b7, b6), \
				B_OR(b5, b4) \
			), \
			B_OR( \
				B_OR(b3, b2), \
				B_OR(b1, b0) \
			) \
		)
#define ISNONZERO(X) _ISNONZERO X

#define ISZERO(X) B_NOT(ISNONZERO(X))

#define NOT_1 0
#define NOT_0 1
#define B_NOT(X) JOIN2(NOT, X)
#define NOT(X) MAP(B_NOT, X)

#define AND_0_0 0
#define AND_0_1 0
#define AND_1_0 0
#define AND_1_1 1
#define B_AND(X, Y) JOIN3(AND, X, Y)
#define AND(X, Y) MAP2(B_AND, X, Y)

#define OR_0_0 0
#define OR_0_1 1
#define OR_1_0 1
#define OR_1_1 1
#define B_OR(X, Y) JOIN3(OR, X, Y)
#define OR(X, Y) MAP2(B_OR, X, Y)

#define XOR_0_0 0
#define XOR_0_1 1
#define XOR_1_0 1
#define XOR_1_1 0
#define B_XOR(X, Y) JOIN3(XOR, X, Y)
#define XOR(X, Y) MAP2(B_OR, X, Y)

#endif
