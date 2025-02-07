#pragma once

#include "PhoneBookEntry.hpp"

class PhoneBook {
    public:
        PhoneBook() {}

        bool add_entry(const PhoneBookEntry& phonebookEntry) {
            if(phonebookEntry.get_number().is_valid()) {
                _entries.push_back(phonebookEntry);
                return true;
            }
           return false;
        }

        const PhoneNumber* get_number(const std::string& name) const {
            for(const auto& i: _entries) {
                if(i.get_name() == name) {
                    return &i.get_number();
                }
            }
            return nullptr;
        }
    
    private:
        std::vector<PhoneBookEntry> _entries;
};