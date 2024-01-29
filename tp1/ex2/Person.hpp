#include <string>

class Person
{
private:
    std::string first_name;
    std::string surname;
    
public:
    Person();

    std::string getFirstName() const;
    std::string getSurname() const;

    void setFirstName(const std::string& firstName);
    void setSurname(const std::string& surName);
};