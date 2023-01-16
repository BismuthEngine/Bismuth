import Application;
import Log;

#include "GuardedMain.h" 

int GuardedMain() {
	SApplication application;

	Logger::Log("Bismuth Engine");
	
	while(!application.ShouldQuit()) {
		application.Tick();
	}

	return 0;
}
