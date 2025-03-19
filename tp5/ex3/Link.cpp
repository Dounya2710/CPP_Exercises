#include "Link.hpp"

Link::Link(Person value)
    : _value (std::move(value))
{}

Link::Link(Link* prev, Person p)
    : _prev (prev)
    , _value (std::move(p))
{}

Link::Link(Link* prev, Person value, Link* next)
    : _prev (prev)
    , _value (std::move(value))
    , _next (next)
{
    _prev = nullptr;
    _next = nullptr;
}

const Person& Link::value() const {
    return _value;
}

Person& Link::value() {
    return _value;
}
