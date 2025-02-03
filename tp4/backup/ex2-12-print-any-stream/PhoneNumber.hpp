#pragma once

#include <vector>
#include <iostream>
#include <sstream>

class PhoneNumber {
    public:
        PhoneNumber(int v1, int v2, int v3, int v4, int v5)
            : _v1 {v1}
            , _v2 {v2}
            , _v3 {v3}
            , _v4 {v4}
            , _v5 {v5}
        {}

        inline bool is_valid() const {
            return 0 <= _v1  && _v1 <= 99 && 0 <= _v2 && _v2 <= 99 && 0 <= _v3 && _v3 <= 99 && 0 < _v4 && _v4 <= 99 && 0 <= _v5 && _v5 <= 99;
        }

        int operator[](size_t index) const {
            auto vector = std::vector<int>{_v1, _v2, _v3, _v4, _v5};

            if(index < vector.size()) {
                return vector[index];
            }
            return -1;
        }

        friend std::ostream& operator<<(std::ostream& stream, const PhoneNumber& pn) {
            stream << (pn._v1 < 10 ? "0" : "") << pn._v1
                    << (pn._v2 < 10 ? "0" : "") << pn._v2
                    << (pn._v3 < 10 ? "0" : "") << pn._v3
                    << (pn._v4 < 10 ? "0" : "") << pn._v4
                    << (pn._v5 < 10 ? "0" : "") << pn._v5;
            return stream;
        }

    private:
        int _v1;
        int _v2;
        int _v3;
        int _v4;
        int _v5;
};