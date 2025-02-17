#pragma once

#include "Person.hpp"

class LinkedList;

class Link
{
public:
    // Il faut réflechir aux prototypes des fonctions-membres ci-dessous, certains ne sont pas corrects.
    Link(const Person&);
    // Person value();
    // Link(Link*, Person);
    Link(const Link*, const Person&, const Link*);
    

private:
    Link*  _prev;
    Link*  _next;
    Person _value;
};