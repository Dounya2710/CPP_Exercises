#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Recipe
{
    // Affiche l'identifiant et la formule d'une recette.
    friend std::ostream& operator<<(std::ostream& stream, const Recipe& recipe) { 
        stream << "(" << recipe._id << ") ";
        for(auto i = 0; i < recipe._materials.size(); i++) {
            stream << recipe._materials[i];

            if(i < recipe._materials.size() - 1) {
                stream << " ";
            }
        }
        stream << " => ";

        for(auto j = 0; j < recipe._products.size(); j++) {
            stream << recipe._products[j];

            if(j < recipe._products.size() - 1) {
                stream << " ";
            }
        }

        return stream;
    }

    public:
        Recipe(size_t id, std::vector<std::string> materials, std::vector<std::string> products)
            : _id {id}
            , _materials {std::move(materials)}
            , _products {std::move(products)}
        {}

        const std::vector<std::string>& get_materials() const {
            return _materials;
        }

        const size_t get_id() const {
            return _id;
        }

        const std::vector<std::string>& get_products() const {
            return _products;
        }

    private:
        std::vector<std::string> _materials;
        std::vector<std::string> _products;
        size_t _id;

};
