#include <algorithm>
#include <iostream>

template <typename Container, size_t Size>
class HybridArray
{
    public:
        HybridArray() = default;

        static constexpr size_t static_size() { return Size; }

        /*void push_back(const Container& value) {
            if (size_ < Size) {
                data_[size_] = value;
                ++size_;
            }
        }*/

        const Container& push_back(const Container& value) {
            if (size_ < Size) {
                data_[size_] = value;
                ++size_;
                return data_[size_ - 1];
            } else {
                throw std::out_of_range("HybridArray is full");
            }
        }

        size_t size() const {return size_;}
    
    private:
        Container data_[Size];
        size_t size_ = 0;

};