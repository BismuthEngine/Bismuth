module;

#include <string.h>

export module Types:String;

import :Array;
export import :Allocator;

export
class SString {
protected:
    TArray<const char> data;

public:
    SString() {}
    SString(const char* data) {
        for(int i = 0; i < strlen(data); i++) 
        {

        }
    }

    
};