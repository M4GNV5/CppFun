#!/bin/bash

function byte2bits
{
	val=$1
	seperator=$2
	result=""

	for i in `seq 7 -1 1`; do
		let "bit = ($val >> $i) & 1"
		if [[ $bit -eq 1 ]]; then
			result="${result}1${seperator}"
		else
			result="${result}0${seperator}"
		fi
	done

	let "bit = $val & 1"
	if [[ bit -eq 1 ]]; then
		result="${result}1"
	else
		result="${result}0"
	fi

	printf "%s" $result
}

printf "#ifndef _CPPFUN_CONVERT_H\n" > convert.h
printf "#define _CPPFUN_CONVERT_H\n\n" >> convert.h
printf "#include \"common.h\"\n\n" >> convert.h

printf "#define CONST2BYTE(val) JOIN2(CONST2BYTE, val)\n" >> convert.h

for i in `seq 0 255`; do
	bits=$(byte2bits $i ",")
	printf "#define CONST2BYTE_%d (%s)\n" $i $bits >> convert.h
done

printf "\n#define _BYTE2CONST(b7, b6, b5, b4, b3, b2, b1, b0) \
BYTE2CONST_##b7##_##b6##_##b5##_##b4##_##b3##_##b2##_##b1##_##b0\n" >> convert.h

printf "#define BYTE2CONST(val) _BYTE2CONST val\n" >> convert.h

for i in `seq 0 255`; do
	bits=$(byte2bits $i "_")
	printf "#define BYTE2CONST_%s %d\n" $bits $i >> convert.h
done

printf "\n#endif\n" >> convert.h
