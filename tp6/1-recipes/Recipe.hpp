#pragma once

#include <ostream>
#include <vector>
#include <string>
#include <iostream>

class Recipe
{
    public:
        Recipe(std::vector<std::string> materials, std::vector<std::string> products, size_t id)
            : _materials(materials), _products(products), _id(id) {}

        const std::vector<std::string>& getMaterials() const { return _materials; }
        const std::vector<std::string>& getProducts() const { return _products; }
        size_t getId() const { return _id; }

        // Affiche l'identifiant et la formule d'une recette.
        friend std::ostream& operator<<(std::ostream& stream, const Recipe& recipe) {
            stream << "(" << recipe._id << ") ";
            for (size_t i = 0; i < recipe._materials.size(); ++i)
            {
                if (i != 0)
                    stream << " ";
                stream << recipe._materials[i];
            }

            stream << " => ";

            for (size_t i = 0; i < recipe._products.size(); ++i)
            {
                if (i != 0)
                    stream << " ";
                stream << recipe._products[i];
            }

            return stream;
        }
    
    private:
        std::vector<std::string> _materials;
        std::vector<std::string> _products;
        size_t _id;
};
