#include "Person.hpp"
#include "Student.hpp"
#include "PersonArray.hpp"

int main() {
    Person p("Dounya", 23);
    //p.display();

    Student s {"Dounya", 23, 15.65};
    //s.display();

    PersonArray pA(2);
    pA.addPerson(p, 0);
    pA.addPerson(s, 1);
    pA.displayAll();

    return 0;
}