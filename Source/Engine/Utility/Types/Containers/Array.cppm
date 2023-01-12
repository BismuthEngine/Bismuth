export module Types:Array;

export import :Allocator; 

export
template <typename ElementType, class AllocatorType = TAllocator<ElementType>>
class TArray {
public:

    // Adds element to array
    // Returns new array size
    int Add(ElementType element) {
        
    }

    // Removes element from array
    // Returns new array size
    int Remove(int index) {
        
    }

    // Searches specified element in array
    // Returns index of element or -1 if could not find it
    int Find(ElementType element) {
        
    }

    // Current length of array 
    int Length() const {
        
    }

    // Maximum capacity before reallocating
    int Capacity() const {
        
    }

    // Returns allocated memory pointer to first element
    ElementType* Data() const {

    }
};