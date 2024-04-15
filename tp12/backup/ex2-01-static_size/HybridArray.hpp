#include <algorithm>
#include <iostream>

template <typename Container, size_t Size>
class HybridArray
{
    public:
        HybridArray() = default;

        static constexpr size_t static_size() { return Size; }
};