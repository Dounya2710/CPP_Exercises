#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Person
{
    std::string first_name;
    std::string last_name;
};

std::string print_full(const Person& p) {
    return p.first_name + " " + p.last_name;
}

std::vector<std::string> compute_full_names(const std::vector<Person>& persons)
{
    std::vector<std::string> full_names;
    std::transform(persons.begin(), persons.end(), std::back_inserter(full_names), [](const Person& p) {return print_full(p);});
    return full_names;
}

int main()
{
    std::vector<Person> persons { { "Celine", "Noel" },
                                  { "Victor", "Marsault" },
                                  { "Anthony", "Labarre" },
                                  { "Henri", "Derycke" } };

    const auto full_names = compute_full_names(persons);
    for (const auto& f: full_names)
    {
        std::cout << f << std::endl;
    }

    return 0;
}