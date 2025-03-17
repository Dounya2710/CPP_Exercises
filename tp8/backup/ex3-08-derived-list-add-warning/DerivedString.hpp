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

    protected:
        virtual bool is_same_type(const Base& base) const override {
            return (dynamic_cast<const DerivedString&>(base)._str == _str);
        }

    private:
        std::string _str;
};