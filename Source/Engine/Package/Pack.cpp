module Package:Pack;

#include <cstdarg>
#include <algorithm>

void SPackage::Add(unsigned int count, ...) {
    std::va_list args;
    va_start(args, fmt);

    for(int i = 0; i < count; i++) {
        const SArtifact& artifact = va_arg(args, const SArtifact&);
        // Only add artifact, if it is unique
        if(std::find(artifacts.begin(), artifacts.end(), artifact) == artifacts.end()) {
            artifacts.push_back(artifact);
        }
    }

    va_end(args);
}