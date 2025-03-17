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
        virtual ~Base() = default;

        const std::string& type() const {
            return _type;
        }

        bool operator==(const Base& base) const{
            if(base._type != this->_type) {
                return false;
            }
            return is_same_type(base);
        }

    private:
        std::string _type;

    protected:
        virtual bool is_same_type(const Base& other) const = 0;
};