# C pre-processor fun
Math in the C pre-processor by breaking up Numbers into arrays of 8 bits and implementing common operations on those arrays.

## Stuff it can do
```C
#include "convert.h"
#include "math.h"

//this is esentially (6 / 2) * (15 - 13)
BYTE2CONST(
	MUL(
		DIV(
			CONST2BYTE(6),
			CONST2BYTE(2)
		),
		SUB(
			CONST2BYTE(15),
			CONST2BYTE(13)
		)
	)
)
```

running with `cpp test.h` gives
```
6
```

## See also
I got the idea when looking at [orangeduck's cpp Brainfuck interpreter](https://github.com/orangeduck/CPP_COMPLETE)
The readme gives a good overview on how one can have fun with the C pre-processor. Be sure to also check out [C Preprocessor tricks, tips, and idioms](https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms) by pfultz2. However they both do math by simply incrementing/decrementing numbers using macros in the form of
```C
#define INC(x) INC_##x
#define INC_0 1
#define INC_1 2
#define INC_2 3
//...
```
When i saw this together with orangeduck's list functionality, i thought why not represent numbers as a list of 8 ones and zeros. Allowing us to easily implement common operations like addition/subtraction/multiplication and of course bitwise operations such as not/and/or/xor. See below for more information

## How this works

### Basics
First of all the very basics. When you "program" in/with/for the C pre-processor you often use variable pasting. This looks something like this:
```C
#define NOT_1 0
#define NOT_0 1
#define NOT(X) NOT_##X
```
When we now enter `NOT(1)` it gets evaluated to `NOT_1` which is again a macro for `0`.

### Lists
Basically cpp only pastes strings, so we need some trickery to create lists or arrays if you wish. However when we pass a list as `(0,0,0,0)` we can just use the list as arguments like. Let me give an example
```C
#define _NOT_4BIT(b3, b2, b1, b0) (NOT(b3), NOT(b2), NOT(b1), NOT(b0))
#define NOT_4BIT(X) _NOT_4BIT X
```
Now when we run `NOT_4BIT((0,1,0,1))` we get `(1,0,1,0)`. Thats great! Now using the same scheme we can create macros for the other bitwise operations and/or/xor. Then we can implement addition, and using `ADD(X, NOT(Y))` and setting the carry-in we can subtract.

In this repo all of this is done on 8 bit values

### Conversion
For now conversion between between numbers and bit arrays (`BYTE2CONST` and `CONST2BYTE`) is done using 256 macros each.
That code gets generated by [generate_convert](generate_convert.sh). You can run it using `./generate_convert.sh`

## License

The code is published under the EUPL
> The “European Union Public Licence” (EUPL) is a copyleft free/open source software license created on the initiative of and approved by the European Commission in 22 official languages of the European Union.
