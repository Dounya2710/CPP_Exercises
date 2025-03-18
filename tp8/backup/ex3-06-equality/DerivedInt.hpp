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

        std::unique_ptr<Base> new_copy() const override {
            return std::make_unique<DerivedInt>(*this);
        }

        std::unique_ptr<Base> new_move() override {
            return std::make_unique<DerivedInt>(std::move(*this));
        }

    protected:
        virtual bool is_same_type(const Base& base) const override {
            return (dynamic_cast<const DerivedInt&>(base)._value == _value);
        }

    private:
        int _value;
};