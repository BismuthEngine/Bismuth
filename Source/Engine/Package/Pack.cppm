export module Package:Pack;

export import :Artifact;

import Types;

export class SPackage {
protected:
    TArray<SArtifact> artifacts;

public:

    void Add(const SArtifact& artifact) {
        artifacts.Add(artifact);
    }
};