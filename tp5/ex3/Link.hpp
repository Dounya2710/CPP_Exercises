#pragma once

#include "Person.hpp"

class LinkedList;

class Link
{
public:
    // Il faut réflechir aux prototypes des fonctions-membres ci-dessous, certains ne sont pas corrects.
    Link(Person);
    const Person& value() const;
    Person& value();
    Link(Link*, Person);
    Link(Link*, Person, Link*);
    

private:
    Link*  _prev;
    Link*  _next;
    Person _value;
};