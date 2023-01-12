import Services;
import Log;

#include "GuardedMain.h"

#ifdef PLATFORM_WINDOWS
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