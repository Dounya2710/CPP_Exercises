#pragma once

#include <ostream>
#include <iostream>
#include <string>

class Material
{
    public:
        Material(std::string name)
            : _name (name)
        {
            std::cout << _name << " was created" << std::endl;
        }

        ~Material()
        {
            std::cout << _name << " was destroyed" << std::endl;
        }

        std::string getName() const { return _name; }

        // Affiche le nom d'un materiau.
        friend std::ostream& operator<<(std::ostream& stream, const Material& material) { 
            stream << material._name;
            return stream; 
        }

    private:
        std::string _name;

};
