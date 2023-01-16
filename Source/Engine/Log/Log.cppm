module;

#include <iostream>
#include <process.h>

export module Log;

import Types;

export class Logger {
public:
    static void Log(const char* msg) { 
        std::cout << msg << std::endl;
    }

    static void CriticalError(const char* msg) { 
        std::cout << msg << std::endl;
        abort();
    }
};