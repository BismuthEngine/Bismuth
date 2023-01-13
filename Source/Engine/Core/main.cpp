#include "GuardedMain.h"
#include <windows.h>

#if defined(PLATFORM_WINDOWS_)
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	GuardedMain();

	return 0;
}
#else
int main()
{
	GuardedMain();

	return 0;
}
#endif