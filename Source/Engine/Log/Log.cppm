module;

#include <iostream>

export module Log;

import Types;

export class Logger {
public:
    static void Log(const char* msg) {
        std::cout << msg << std::endl;
    }
};