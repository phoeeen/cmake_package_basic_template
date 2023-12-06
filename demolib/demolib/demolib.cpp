#include <demolib/demolib.hpp>

#include <iostream>

void hello_demolib()
{
	#ifdef NDEBUG
		std::cout << "hello from demolib in release mode" << std::endl;
	#else
		std::cout << "hello from demolib in debug mode" << std::endl;
	#endif
}