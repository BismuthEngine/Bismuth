module;

//#include <cstdarg>
//#include <algorithm>
//#include <vector>

export module Package:Pack;

export import :Artifact;

export class SPackage {
protected:
    //std::vector<SArtifact> artifacts;

public:

    void Add(unsigned int count, ...);
};