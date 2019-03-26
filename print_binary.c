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
	(((i) & 0x80) ? '1': '0'),		\
	(((i) & 0x40) ? '1': '0'),		\
	(((i) & 0x20) ? '1': '0'),		\
	(((i) & 0x10) ? '1': '0'),		\
	(((i) & 0x08) ? '1': '0'),		\
	(((i) & 0x04) ? '1': '0'),		\
	(((i) & 0x02) ? '1': '0'),		\
	(((i) & 0x01) ? '1': '0')

#define PRINT_BINARY_PATTERN_INT16	\
	PRINT_BINARY_PATTERN_INT8	PRINT_BINARY_SEPARATOR	PRINT_BINARY_PATTERN_INT8

#define PRINT_BYTE_TO_BINARY_INT16(i)	\
	PRINT_BYTE_TO_BINARY_INT8((i) >> 8), PRINT_BYTE_TO_BINARY_INT8(i)

#define PRINT_BINARY_PATTERN_INT32	\
	PRINT_BINARY_PATTERN_INT16	PRINT_BINARY_SEPARATOR	PRINT_BINARY_PATTERN_INT16

#define PRINT_BYTE_TO_BINARY_INT32(i)	\
	PRINT_BYTE_TO_BINARY_INT16((i) >> 16),	PRINT_BYTE_TO_BINARY_INT16(i)
int main()
{
	long int a = 2147483647;

	printf("Binary representation of a: %lu is: "
		PRINT_BINARY_PATTERN_INT32"\n", a, PRINT_BYTE_TO_BINARY_INT32(a));
}
