#pragma once

#include "Person.hpp"

class PersonArray {
    public:
        PersonArray(int size):_size {size}
        {
            if(size > 0) {
                _persons = new Person[size];
            }
            else {
                _persons = nullptr;
            }
        }

        ~PersonArray() {
            delete[] _persons;
        }

        void addPerson(const Person& p, int index) {
            if(index >= 0 && index <= _size) {
                _persons[index] = p;
            }
            else {
                std::cout << "Out of bounds !!" << std::endl;
            }
        }

        void displayAll() const {
            for(int i = 0; i < _size; i++) {
                _persons[i].display();
            }
        }

    private:
        Person *_persons;
        int _size;
};