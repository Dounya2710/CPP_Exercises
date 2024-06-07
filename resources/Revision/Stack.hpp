#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
class Stack{
    public:
        Stack() = default;

        void push(const T& element) {
            _elements.push_back(element);
        }

        T pop() {
            T elem = _elements.back();
            _elements.pop_back();
            return elem;
        }

        bool isEmpty() const {
            return _elements.empty();
        }

    private:
        std::vector<T> _elements;
};