#pragma once

#include <vector>
#include <memory>
#include <sstream>
#include <string>

#include "Base.hpp"

class DerivedList: public Base {
    public:
        DerivedList()
            : Base("List")
        {}

        bool is_null() const override {
            return _l.empty();
        }

        std::string to_string() const override {
            std::stringstream res;
            res << "[";
            for (unsigned i = 0; i < _l.size(); ++i) {
                res << _l[i]->to_string();
                if (i < _l.size() - 1) {
                    res << ", ";
                }
            }
            res << "]";
            return res.str();
        }

        void add(const Base& element) {
            _l.push_back(element);
        }

    protected:
        virtual bool is_same_type(const Base& b) const override
        {
            const DerivedList& other = dynamic_cast<const DerivedList&>(b);
            if (other._l.size() != _l.size())
                return false;
            for (unsigned i = 0; i < _l.size(); ++i)
                if (!(*(other._l[i]) == *(_l[i])))
                    return false;
            return true;
        }

    private:
        std::vector<std::unique_ptr<Base>> _l;
};