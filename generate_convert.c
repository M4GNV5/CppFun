#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void byet2bits(char *buff, uint8_t val, char splitter)
{
	for(int i = 7; i >= 0; i--)
	{
		*buff++ = '0' + ((val >> i) & 1);
		*buff++ = splitter;
	}

	*--buff = 0;
}

int main(char **args)
{
	char bits[16];
	FILE *fd = fopen("convert.h", "w");

	if(fd == NULL)
	{
		fprintf(stderr, "Could not open output file 'convert.h'\n");
		return EXIT_FAILURE;
	}

	fprintf(fd, "#ifndef _CPPFUN_CONVERT_H\n");
	fprintf(fd, "#define _CPPFUN_CONVERT_H\n\n");
	fprintf(fd, "#include \"common.h\"\n\n");

	fprintf(fd, "#define CONST2BYTE(val) JOIN2(CONST2BYTE, val)\n");
	for(int i = 0; i <= UINT8_MAX; i++)
	{
		byet2bits(bits, i, ',');
		fprintf(fd, "#define CONST2BYTE_%d (%s)\n", i, bits);
	}

	fprintf(fd, "\n#define _BYTE2CONST(b7, b6, b5, b4, b3, b2, b1, b0) BYTE2CONST_##b7##_##b6##_##b5##_##b4##_##b3##_##b2##_##b1##_##b0\n");
	fprintf(fd, "#define BYTE2CONST(val) _BYTE2CONST val\n");
	for(int i = 0; i <= UINT8_MAX; i++)
	{
		byet2bits(bits, i, '_');
		fprintf(fd, "#define BYTE2CONST_%s %d\n", bits, i);
	}

	fprintf(fd, "\n#endif\n");
}
