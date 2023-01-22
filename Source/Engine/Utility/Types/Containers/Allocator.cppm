export module Types:Allocator;

export
template <typename ElementType>
class TAllocator {
public:
    static ElementType* Allocate(unsigned int sz, ElementType* data = nullptr) {
        return nullptr;
    }

    static ElementType* Reallocate(unsigned int sz, ElementType* data = nullptr, unsigned int oldsz = 0) {
        return nullptr;
    }
};