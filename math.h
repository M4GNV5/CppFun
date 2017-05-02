#ifndef _CPPFUN_MATH_H
#define _CPPFUN_MATH_H

#include "common.h"
#include "bitwise.h"

#define ADD(X, Y) TAIL(ADC(X, Y, 0))
#define SUB(X, Y) TAIL(ADC(X, NOT(Y), 1))

#define ADDBIT_0_0_0 0, 0
#define ADDBIT_0_0_1 0, 1
#define ADDBIT_0_1_0 0, 1
#define ADDBIT_0_1_1 1, 0
#define ADDBIT_1_0_0 0, 1
#define ADDBIT_1_0_1 1, 0
#define ADDBIT_1_1_0 1, 0
#define ADDBIT_1_1_1 1, 1
#define ADDBIT(X, Y, C) JOIN4(ADDBIT, X, Y, C)

#define _APPLY_AND_RET(F, X, Y, C, ...) F(X, Y, C), __VA_ARGS__
#define APPLY_AND_RET(...) _APPLY_AND_RET(__VA_ARGS__)
#define ADC(X, Y, Cin) \
		(\
			APPLY_AND_RET(ADDBIT, EXTRACT_BIT(X, 7), EXTRACT_BIT(Y, 7), \
				APPLY_AND_RET(ADDBIT, EXTRACT_BIT(X, 6), EXTRACT_BIT(Y, 6), \
					APPLY_AND_RET(ADDBIT, EXTRACT_BIT(X, 5), EXTRACT_BIT(Y, 5), \
						APPLY_AND_RET(ADDBIT, EXTRACT_BIT(X, 4), EXTRACT_BIT(Y, 4), \
							APPLY_AND_RET(ADDBIT, EXTRACT_BIT(X, 3), EXTRACT_BIT(Y, 3), \
								APPLY_AND_RET(ADDBIT, EXTRACT_BIT(X, 2), EXTRACT_BIT(Y, 2), \
									APPLY_AND_RET(ADDBIT, EXTRACT_BIT(X, 1), EXTRACT_BIT(Y, 1), \
										ADDBIT(EXTRACT_BIT(X, 0), EXTRACT_BIT(Y, 0), Cin) \
									)\
								)\
							)\
						)\
					)\
				)\
			)\
		)

#endif
