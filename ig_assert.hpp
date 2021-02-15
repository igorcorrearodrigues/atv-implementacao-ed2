#ifndef IG_ASSERT_HPP
#define IG_ASSERT_HPP

#define ig_assert(expr) assert(expr)
/* \
 	do\
 	{\
 		assert(expr);\
 		std::cout << "Assertion `" << #expr << "': OK\n";\
 	} while (0)
*/

#endif // IG_ASSERT_HPP
