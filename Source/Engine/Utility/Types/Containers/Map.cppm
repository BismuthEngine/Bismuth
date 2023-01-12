export module Types:Map;

export import :Array; 

export
template <typename KeyType, typename ElementType, class AllocatorType = TAllocator<ElementType>>
class TMap {
public:

    // Sets element to array by key
    // Returns new map size
    int Set(KeyType key, ElementType element) {
        
    }

    // Removes element from array
    // Returns new map size
    int Remove(KeyType key) {
        
    }

    // Searches specified element in array
    // Returns index of element or -1 if could not find it
    int Find(KeyType key) {
        
    }

    // Current length of map
    int Length() const {
        
    }

    // Maximum capacity before reallocating
    int Capacity() const {
        
    }
};