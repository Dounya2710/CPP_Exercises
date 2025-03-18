#pragma once

#include <string>
#include <iostream>
#include <memory>

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
        virtual std::unique_ptr<Base> new_copy() const = 0;
        virtual std::unique_ptr<Base> new_move() = 0;

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

#define JAI_LU_LE_WARNING_09 true
#define JAI_LU_LE_WARNING_13 true