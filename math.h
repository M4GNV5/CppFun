#ifndef _CPPFUN_MATH_H
#define _CPPFUN_MATH_H

#include "common.h"
#include "bitwise.h"
#include "compare.h"

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

#define ADD(X, Y) TAIL(ADC(X, Y, 0))
#define SUB(X, Y) TAIL(ADC(X, NOT(Y), 1))

#define ADDIF_1(X, Y) ADD(X, Y)
#define ADDIF_0(X, Y) X
#define ADDIF(cond, X, Y) JOIN2(ADDIF, cond)(X, Y)

#define MUL(X, Y) ADDIF(EXTRACT_BIT(Y, 0), MUL1(SHL(X), Y), X)
#define MUL1(X, Y) ADDIF(EXTRACT_BIT(Y, 1), MUL2(SHL(X), Y), X)
#define MUL2(X, Y) ADDIF(EXTRACT_BIT(Y, 2), MUL3(SHL(X), Y), X)
#define MUL3(X, Y) ADDIF(EXTRACT_BIT(Y, 3), MUL4(SHL(X), Y), X)
#define MUL4(X, Y) ADDIF(EXTRACT_BIT(Y, 4), MUL5(SHL(X), Y), X)
#define MUL5(X, Y) ADDIF(EXTRACT_BIT(Y, 5), MUL6(SHL(X), Y), X)
#define MUL6(X, Y) ADDIF(EXTRACT_BIT(Y, 6), MUL7(SHL(X), Y), X)
#define MUL7(X, Y) ADDIF(EXTRACT_BIT(Y, 7), CONST2BYTE(0), X)

#define DIVSTEP_1(step, X, Y, quot, rem) INSERT_BIT(quot, step, 1), SUB(rem, Y)
#define DIVSTEP_0(step, X, Y, quot, rem) quot, rem
#define __DIVSTEP(cond, step, X, Y, quot, rem) JOIN2(DIVSTEP, cond)(step, X, Y, quot, rem)
#define _DIVSTEP(step, X, Y, quot, rem) __DIVSTEP(CMP_AE(rem, Y), step, X, Y, quot, rem)
#define DIVSTEP(step, X, Y, quot, rem) _DIVSTEP(step, X, Y, quot, SHLIN(rem, EXTRACT_BIT(X, step)))

#define APPLY0(F, ...) F(__VA_ARGS__)
#define APPLY1(F, ...) F(__VA_ARGS__)
#define APPLY2(F, ...) F(__VA_ARGS__)
#define APPLY3(F, ...) F(__VA_ARGS__)
#define APPLY4(F, ...) F(__VA_ARGS__)
#define APPLY5(F, ...) F(__VA_ARGS__)
#define APPLY6(F, ...) F(__VA_ARGS__)

#define DIVMOD(X, Y) \
	APPLY0(DIVSTEP, 0, X, Y, \
		APPLY1(DIVSTEP, 1, X, Y, \
			APPLY2(DIVSTEP, 2, X, Y, \
				APPLY3(DIVSTEP, 3, X, Y, \
					APPLY4(DIVSTEP, 4, X, Y, \
						APPLY5(DIVSTEP, 5, X, Y, \
							APPLY6(DIVSTEP, 6, X, Y, \
								DIVSTEP(7, X, Y, CONST2BYTE(0), CONST2BYTE(0)) \
							) \
						) \
					) \
				) \
			) \
		) \
	)

#define DIV(X, Y) HEAD((DIVMOD(X, Y)))
#define MOD(X, Y) TAIL((DIVMOD(X, Y)))

#endif
