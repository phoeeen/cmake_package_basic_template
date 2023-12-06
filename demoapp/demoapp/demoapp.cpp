#include <demoapp/demoapp.hpp>

#include <demolib/demolib.hpp>

int main()
{
	#ifdef NDEBUG
		std::cout << "hello from demoapp in release mode" << std::endl;
	#else
		std::cout << "hello from demoapp in debug mode" << std::endl;
	#endif

	hello_demolib();	
	return 0;
}
