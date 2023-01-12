import Services;
import Log;

#include "GuardedMain.h"

#if defined(PLATFORM_WINDOWS) || defined(_WIN32)
int GuardedMain() {
	const SServiceManager& servmgr = SServiceManager::Get();
	Logger::Log("Bismuth Engine");
	
	return 0;
}
#else 
int GuardedMain() {
	//std::cout << 40 << std::endl;

	return 40;
}
#endif