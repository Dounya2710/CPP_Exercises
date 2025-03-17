#pragma once

#include "Base.hpp"

class DerivedString: public Base {
    public:
        DerivedString(const std::string& str)
            : Base("String")
            , _str {str}
        {}

        bool is_null() const override {
            return _str.empty();
        }

        const std::string& data() const {
            return _str;
        }

        std::string to_string() const override {
            return _str;
        }

    private:
        std::string _str;
};