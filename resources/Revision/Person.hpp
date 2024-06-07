#pragma once

#include <iostream>
#include <string>

class Person {
    public:
        Person() {}

        Person(const std::string& name, int age)
            : name_ {name}
            , age_ {age}
        {}

        virtual void display() const {
            std::cout << "Person: " << name_ << " is " << std::to_string(age_) << " years old." << std::endl;
        }

        void set_name(std::string n) {
            name_ = n;
        }

        void set_age(int a) {
            age_ = a;
        }

        ~Person() {
            //std::cout << name_ << " died at " << std::to_string(age_) << " years old. RIP" << std::endl;
        }
    
    private:
        std::string name_;
        int age_;
};
