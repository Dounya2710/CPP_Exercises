#pragma once

#include <string>
#include <iostream>

class Base {
    friend std::ostream& operator<<(std::ostream& stream, const Base& base) {
        return stream << base.to_string();
    }

    public:
        Base(std::string type)
            : _type {std::move(type)}
        {}

        virtual bool is_null() const = 0;
        virtual std::string to_string() const = 0;

        const std::string& type() const {
            return _type;
        }

    private:
        std::string _type;
};