/*
 * Print an integer number in binary.
 *
 * E.g.
 * a = 9 => 1001
 */
#include <stdio.h>

#define PRINT_BINARY_SEPARATOR		" "
#define PRINT_BINARY_PATTERN_INT8	"%c%c%c%c%c%c%c%c"

#define PRINT_BYTE_TO_BINARY_INT8(i)	\
	(((i) & 0x80ll) ? '1': '0'),		\
	(((i) & 0x40ll) ? '1': '0'),		\
	(((i) & 0x20ll) ? '1': '0'),		\
	(((i) & 0x10ll) ? '1': '0'),		\
	(((i) & 0x08ll) ? '1': '0'),		\
	(((i) & 0x04ll) ? '1': '0'),		\
	(((i) & 0x02ll) ? '1': '0'),		\
	(((i) & 0x01ll) ? '1': '0')

#define PRINT_BINARY_PATTERN_INT16	\
	PRINT_BINARY_PATTERN_INT8	PRINT_BINARY_SEPARATOR	PRINT_BINARY_PATTERN_INT8

#define PRINT_BYTE_TO_BINARY_INT16(i)	\
	PRINT_BYTE_TO_BINARY_INT8((i) >> 8), PRINT_BYTE_TO_BINARY_INT8(i)

#define PRINT_BINARY_PATTERN_INT32	\
	PRINT_BINARY_PATTERN_INT16	PRINT_BINARY_SEPARATOR	PRINT_BINARY_PATTERN_INT16

#define PRINT_BYTE_TO_BINARY_INT32(i)	\
	PRINT_BYTE_TO_BINARY_INT16((i) >> 16),	PRINT_BYTE_TO_BINARY_INT16(i)

#define PRINT_BINARY_PATTERN_INT64	\
	PRINT_BINARY_PATTERN_INT32	PRINT_BINARY_SEPARATOR	PRINT_BINARY_PATTERN_INT32

#define PRINT_BYTE_TO_BINARY_INT64(i)	\
	PRINT_BYTE_TO_BINARY_INT32((i) >> 32), PRINT_BYTE_TO_BINARY_INT32(i)

int main()
{
	long long int a = 9223372036854775807;

	printf("Binary representation of a: %llu is: "
		PRINT_BINARY_PATTERN_INT64"\n", a, PRINT_BYTE_TO_BINARY_INT64(a));
}
