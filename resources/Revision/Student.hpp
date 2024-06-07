#pragma once

#include "Person.hpp"

class Student : public Person {
    public:
        Student(const std::string& name, int age, float avg)
            : Person(name, age)
            , avg_ {avg}
        {}

        void display() const override {
            Person::display();
            std::cout << " Has got an average of " + std::to_string(avg_) + ". Congratulations !!!" << std::endl;
        }

    private:
        float avg_;
};