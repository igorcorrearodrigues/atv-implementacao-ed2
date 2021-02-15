#ifndef PRINT_BITS_HPP
#define PRINT_BITS_HPP

#include <iostream>

typedef unsigned char uchar;

#define BYTE_TO_BIT(byte) \
	((byte & 0x80) ? '1' : '0') << \
	((byte & 0x40) ? '1' : '0') << \
	((byte & 0x20) ? '1' : '0') << \
	((byte & 0x10) ? '1' : '0') << \
	((byte & 0x08) ? '1' : '0') << \
	((byte & 0x04) ? '1' : '0') << \
	((byte & 0x02) ? '1' : '0') << \
	((byte & 0x01) ? '1' : '0')


#define printbits(x)                   \
	do                                   \
	{                                    \
		size_t x_size = sizeof(x);         \
		uchar *x_ptr = (uchar *) &(x);     \
                                       \
		for (;;)                           \
		{                                  \
			uchar byte = x_ptr[--x_size];    \
                                       \
			std::cout << BYTE_TO_BIT(byte);  \
                                       \
			if (x_size == 0)                 \
				break;                         \
                                       \
			std::cout << ' ';                \
		}                                  \
	} while (0)

#endif // PRINT_BITS_HPP
