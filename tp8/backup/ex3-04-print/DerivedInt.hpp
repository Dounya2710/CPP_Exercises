#pragma once

#include "Base.hpp"

class DerivedInt: public Base {
    public:
        DerivedInt(int value)
            : Base("Int")
            , _value {value}
        {}

        bool is_null() const override {
            return _value == 0;
        }

        int data() const {
            return _value;
        }

        std::string to_string() const override {
            return std::to_string(_value);
        }

    private:
        int _value;
};