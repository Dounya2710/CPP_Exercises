#pragma once

#include "Base.hpp"

class DerivedInt: public Base {
    public:
        DerivedInt(int value)
            : _value {value}
        {}

        bool is_null() const override {
            return _value == 0;
        }

        int data() const {
            return _value;
        }

    private:
        int _value;
};