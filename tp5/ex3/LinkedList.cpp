#include "LinkedList.hpp"
#include <vector>

size_t LinkedList::size() {
    return _size;
}

std::ostream& operator<<(std::ostream& o, LinkedList list) {
    return o << list._front << " " << list._back;
}

bool LinkedList::empty() {
    return _front == nullptr;
}

void LinkedList::push_back(Person p) {
    auto* newLink = new Link(_back, std::move(p));
    if(_back == nullptr) {
        _front = newLink;
    }
    _back->_next = newLink;
}