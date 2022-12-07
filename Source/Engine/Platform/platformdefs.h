#pragma once

#ifndef PLATFORM_WINDOWS
#if defined(_WIN32)
#define PLATFORM_WINDOWS 1
#else
#define PLATFORM_WINDOWS 0
#endif
#endif