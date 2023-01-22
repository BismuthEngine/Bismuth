export module Types:Array;

export import :Allocator; 

export
template <typename ElementType, class AllocatorType = TAllocator<ElementType>>
class TArray {
    ElementType* array;
    unsigned int size;
    unsigned int capacity;
public:

    TArray(unsigned int sz, ElementType* data = nullptr)
        : size(sz), capacity(sz*2)
    {
        array = AllocatorType::Allocate(sz, data);
    }

    TArray()
        : size(0), capacity(1)
    {
        array = AllocatorType::Allocate(1);
    }

    // Adds element to array
    // Returns new array size
    int Add(ElementType element) {
        if(size+1 > capacity) {
            array = AllocatorType::Reallocate(capacity*2, array, capacity);
        }

        array[size] = element;
        return ++size;
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
        return size;
    }

    // Maximum capacity before reallocating
    int Capacity() const {
        return capacity;
    }

    // Returns allocated memory pointer to first element
    ElementType* Data() const {
        return array;
    }
};