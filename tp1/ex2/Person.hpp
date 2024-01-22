#include <string>

class Person
{
public:
    std::string first_name;
    std::string surname;
    
    public:
    Person();

    std::string getFirstName() const;
    std::string getSurname() const;
};