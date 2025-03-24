#include <iostream>
#include <string>
#include <vector>

struct Animal
{
    std::string name;
    std::string species;
};

std::ostream& operator<<(std::ostream& str, const Animal& animal)
{
    return str << animal.name << " (" << animal.species<< ")";
}

std::ostream& operator<<(std::ostream& str, const std::vector<Animal>& animals)
{
    str << "[-";
    for (const auto& a: animals)
    {
        str << " " <<  a << " -";
    }
    str << "]";
    return str;
}

void remove_cats(std::vector<Animal>& animals)
{
    auto it = std::remove_if(animals.begin(), animals.end(), [](const Animal& a) {return a.species == "cat";});
    animals.erase(it, animals.end());
}

std::ptrdiff_t get_position_of_first_with_species(const std::deque<Animal>& animals, const std::string& species)
{
    const auto it = std::find_if(animals.begin(), animals.end(), [&species](const Animal& a) {return a.species == species;});
    if(it == animals.end()) {
        return -1;
    }
    else {
        return std::distance(animals.begin(), it);
    }
}

int main()
{
    std::vector<Animal> animals;
    animals.push_back({ "felix", "cat" });
    animals.push_back({ "medor", "dog" });
    animals.push_back({ "guss", "mouse" });
    animals.push_back({ "gipsy", "dog" });
    animals.push_back({ "chaussette", "cat" });
    animals.push_back({ "pelotte", "cat" });

    std::cout << animals << std::endl;

    /*remove_cats(animals);
    std::cout << animals << std::endl;*/
    
    std::cout << "First dog is at: " << get_position_of_first_with_species(animals, "dog") << std::endl;
    std::cout << "First poney is at: " << get_position_of_first_with_species(animals, "poney") << std::endl;
    std::cout << "First mouse is at: " << get_position_of_first_with_species(animals, "mouse") << std::endl;


    return 0;
}