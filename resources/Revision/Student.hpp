#pragma once

#include "Person.hpp"

class Student : public Person {
    public:
        Student(const std::string& name, int age, float avg)
            : Person(name_, age_)
            , avg_ {avg}
        {}

        void display() const override {
            Person::display();
            std::cout << " Has got an average of " + std::to_string(avg_) + ". Congratulations !!!" << std::endl;
        }

    private:
        std::string name_;
        int age_;
        float avg_;
};