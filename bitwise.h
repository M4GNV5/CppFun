#ifndef _CPPFUN_BITWISE_H
#define _CPPFUN_BITWISE_H

#define EXTRACT_BIT_7(b7, b6, b5, b4, b3, b2, b1, b0) b7
#define EXTRACT_BIT_6(b7, b6, b5, b4, b3, b2, b1, b0) b6
#define EXTRACT_BIT_5(b7, b6, b5, b4, b3, b2, b1, b0) b5
#define EXTRACT_BIT_4(b7, b6, b5, b4, b3, b2, b1, b0) b4
#define EXTRACT_BIT_3(b7, b6, b5, b4, b3, b2, b1, b0) b3
#define EXTRACT_BIT_2(b7, b6, b5, b4, b3, b2, b1, b0) b2
#define EXTRACT_BIT_1(b7, b6, b5, b4, b3, b2, b1, b0) b1
#define EXTRACT_BIT_0(b7, b6, b5, b4, b3, b2, b1, b0) b0
#define EXTRACT_BIT(val, index) EXTRACT_BIT_##index val

#define INSERT_BIT_7(b7, b6, b5, b4, b3, b2, b1, b0, bit) (bit, b6, b5, b4, b3, b2, b1, b0)
#define INSERT_BIT_6(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, bit, b5, b4, b3, b2, b1, b0)
#define INSERT_BIT_5(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, bit, b4, b3, b2, b1, b0)
#define INSERT_BIT_4(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, b5, bit, b3, b2, b1, b0)
#define INSERT_BIT_3(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, b5, b4, bit, b2, b1, b0)
#define INSERT_BIT_2(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, b5, b4, b3, bit, b1, b0)
#define INSERT_BIT_1(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, b5, b4, b3, b2, bit, b0)
#define INSERT_BIT_0(b7, b6, b5, b4, b3, b2, b1, b0, bit) (b7, b6, b5, b4, b3, b2, b1, bit)
#define BYTE2ARG(b7, b6, b5, b4, b3, b2, b1, b0) b7, b6, b5, b4, b3, b2, b1, b0
#define INSERT_BIT(val, index, bit) APPLY(INSERT_BIT_##index, BYTE2ARG val, bit)

#define _SHL(b7, b6, b5, b4, b3, b2, b1, b0) (b6, b5, b4, b3, b2, b1, b0, 0)
#define SHL(val) _SHL val

#define _SHR(b7, b6, b5, b4, b3, b2, b1, b0) (0, b7, b6, b5, b4, b3, b2, b1)
#define SHR(val) _SHR val

#define NOT_1 0
#define NOT_0 1
#define NOT(X) (\
		APPLY(JOIN2, NOT, EXTRACT_BIT(X, 7)),\
		APPLY(JOIN2, NOT, EXTRACT_BIT(X, 6)),\
		APPLY(JOIN2, NOT, EXTRACT_BIT(X, 5)),\
		APPLY(JOIN2, NOT, EXTRACT_BIT(X, 4)),\
		APPLY(JOIN2, NOT, EXTRACT_BIT(X, 3)),\
		APPLY(JOIN2, NOT, EXTRACT_BIT(X, 2)),\
		APPLY(JOIN2, NOT, EXTRACT_BIT(X, 1)),\
		APPLY(JOIN2, NOT, EXTRACT_BIT(X, 0))\
	)

#define AND_0_0 0
#define AND_0_1 0
#define AND_1_0 0
#define AND_1_1 1
#define AND(X, Y) (\
		APPLY(JOIN3, AND, EXTRACT_BIT(X, 7), EXTRACT_BIT(Y, 7)),\
		APPLY(JOIN3, AND, EXTRACT_BIT(X, 6), EXTRACT_BIT(Y, 6)),\
		APPLY(JOIN3, AND, EXTRACT_BIT(X, 5), EXTRACT_BIT(Y, 5)),\
		APPLY(JOIN3, AND, EXTRACT_BIT(X, 4), EXTRACT_BIT(Y, 4)),\
		APPLY(JOIN3, AND, EXTRACT_BIT(X, 3), EXTRACT_BIT(Y, 3)),\
		APPLY(JOIN3, AND, EXTRACT_BIT(X, 2), EXTRACT_BIT(Y, 2)),\
		APPLY(JOIN3, AND, EXTRACT_BIT(X, 1), EXTRACT_BIT(Y, 1)),\
		APPLY(JOIN3, AND, EXTRACT_BIT(X, 0), EXTRACT_BIT(Y, 0))\
	)

#define OR_0_0 0
#define OR_0_1 1
#define OR_1_0 1
#define OR_1_1 1
#define OR(X, Y) (\
		APPLY(JOIN3, OR, EXTRACT_BIT(X, 7), EXTRACT_BIT(Y, 7)),\
		APPLY(JOIN3, OR, EXTRACT_BIT(X, 6), EXTRACT_BIT(Y, 6)),\
		APPLY(JOIN3, OR, EXTRACT_BIT(X, 5), EXTRACT_BIT(Y, 5)),\
		APPLY(JOIN3, OR, EXTRACT_BIT(X, 4), EXTRACT_BIT(Y, 4)),\
		APPLY(JOIN3, OR, EXTRACT_BIT(X, 3), EXTRACT_BIT(Y, 3)),\
		APPLY(JOIN3, OR, EXTRACT_BIT(X, 2), EXTRACT_BIT(Y, 2)),\
		APPLY(JOIN3, OR, EXTRACT_BIT(X, 1), EXTRACT_BIT(Y, 1)),\
		APPLY(JOIN3, OR, EXTRACT_BIT(X, 0), EXTRACT_BIT(Y, 0))\
	)

#define XOR_0_0 0
#define XOR_0_1 1
#define XOR_1_0 1
#define XOR_1_1 0
#define XOR(X, Y) (\
		APPLY(JOIN3, XOR, EXTRACT_BIT(X, 7), EXTRACT_BIT(Y, 7)),\
		APPLY(JOIN3, XOR, EXTRACT_BIT(X, 6), EXTRACT_BIT(Y, 6)),\
		APPLY(JOIN3, XOR, EXTRACT_BIT(X, 5), EXTRACT_BIT(Y, 5)),\
		APPLY(JOIN3, XOR, EXTRACT_BIT(X, 4), EXTRACT_BIT(Y, 4)),\
		APPLY(JOIN3, XOR, EXTRACT_BIT(X, 3), EXTRACT_BIT(Y, 3)),\
		APPLY(JOIN3, XOR, EXTRACT_BIT(X, 2), EXTRACT_BIT(Y, 2)),\
		APPLY(JOIN3, XOR, EXTRACT_BIT(X, 1), EXTRACT_BIT(Y, 1)),\
		APPLY(JOIN3, XOR, EXTRACT_BIT(X, 0), EXTRACT_BIT(Y, 0))\
	)

#endif
