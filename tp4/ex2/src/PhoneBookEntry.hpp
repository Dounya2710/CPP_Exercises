#pragma once

#include "PhoneNumber.hpp"
#include <string>

class PhoneBookEntry{
    public:
        PhoneBookEntry(const std::string& name, const PhoneNumber& pn)
            : _name {name}
            , _pn {pn}
        {}

        const std::string& get_name() const {
            return _name;
        }

        const PhoneNumber& get_number() const {
            return _pn;
        }

        friend bool operator==(const PhoneBookEntry& p1, const PhoneBookEntry& p2){
            return p1._name == p2._name;
        }

    private:
        std::string _name;
        PhoneNumber _pn;
};