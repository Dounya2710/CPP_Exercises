#pragma once

#include <string>
#include <iostream>

class Base {
    friend std::ostream& operator<<(std::ostream& stream, const Base& base) {
        return stream << base.to_string();
    }

    public:
        virtual bool is_null() const = 0;
        virtual std::string to_string() const = 0;
};