#include "GuardedMain.h"

#ifdef PLATFORM_WINDOWS
int GuardedMain() {
	//std::cout << 5 << std::endl;
	return 25;
}
#else 
int GuardedMain() {
	//std::cout << 40 << std::endl;

	return 40;
}
#endif