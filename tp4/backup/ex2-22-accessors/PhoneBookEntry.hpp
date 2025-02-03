#pragma once

#include "PhoneNumber.hpp"
#include <string>

class PhoneBookEntry{
    public:
        PhoneBookEntry(const std::string& name, PhoneNumber pn)
            : _name {name}
            , _pn {pn}
        {}

        std::string get_name() const {
            return _name;
        }

        PhoneNumber get_number() const {
            return _pn;
        }

    private:
        std::string _name;
        PhoneNumber _pn;
};