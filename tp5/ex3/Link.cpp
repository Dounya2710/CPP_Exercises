#include "Link.hpp"

Link::Link(const Person& value)
    : _value (value)
{}

Link::Link(const Link* prev, const Person& value, const Link* next)
    : _prev (prev)
    , _value (value)
    , _next (next)
{
    _prev = nullptr;
    _next = nullptr;
}
