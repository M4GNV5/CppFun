#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void byet2bits(uint8_t *buff, uint8_t val)
{
	buff[0] = val >> 7;
	buff[1] = (val >> 6) & 1;
	buff[2] = (val >> 5) & 1;
	buff[3] = (val >> 4) & 1;
	buff[4] = (val >> 3) & 1;
	buff[5] = (val >> 2) & 1;
	buff[6] = (val >> 1) & 1;
	buff[7] = val & 1;
}

int main(char **args)
{
	uint8_t bits[8];
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
		byet2bits(bits, i);
		fprintf(fd, "#define CONST2BYTE_%d (%hhu, %hhu, %hhu, %hhu, %hhu, %hhu, %hhu, %hhu)\n", i,
			bits[0], bits[1], bits[2], bits[3], bits[4], bits[5], bits[6], bits[7]);
	}

	fprintf(fd, "\n#define _BYTE2CONST(b7, b6, b5, b4, b3, b2, b1, b0) BYTE2CONST_##b7##_##b6##_##b5##_##b4##_##b3##_##b2##_##b1##_##b0\n");
	fprintf(fd, "#define BYTE2CONST(val) _BYTE2CONST val\n");
	for(int i = 0; i <= UINT8_MAX; i++)
	{
		byet2bits(bits, i);
		fprintf(fd, "#define BYTE2CONST_%hhu_%hhu_%hhu_%hhu_%hhu_%hhu_%hhu_%hhu %d\n",
			bits[0], bits[1], bits[2], bits[3], bits[4], bits[5], bits[6], bits[7], i);
	}

	fprintf(fd, "\n#endif\n");
}
