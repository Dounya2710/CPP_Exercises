#include "ProgramData.hpp"


void ProgramData::add_material(std::string name)
{
    _materials.push_back(std::make_unique<Material>(std::move(name)));
}

void ProgramData::get_materials(std::vector<const Material*>& materials) const
{
    for(const auto& material: _materials) {
        materials.push_back(material.get());
    }
}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{
    auto recipe_id = _recipes.size() + 1;
    auto recipe = std::make_unique<Recipe>(recipe_id, std::move(materials), std::move(products));
    _recipes.push_back(std::move(recipe));

    std::cout << "Recipe " << recipe_id << " has been registered" << std::endl;
}

void ProgramData::collect_doable_recipes(std::vector<const Recipe*>& recipes) const
{
    for (const auto& recipe : _recipes) {
        auto can_make = true;
        for (const auto& material : recipe->get_materials()) {
            can_make = false;

            for (const auto& m : _materials) {
                if (m->get_name() == material) {
                    can_make = true;
                    break;
                }
            }

            if (!can_make) {
                break;
            }
        }

        if (can_make) {
            recipes.push_back(recipe.get());
        }
    }
}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    for (const auto& recipe : _recipes) {
        if (recipe->get_id() == recipe_id) {
            ProductionResult result;
            result.recipe = recipe.get();

            std::vector<std::string> missing_materials;

            for (const auto& material_name : recipe->get_materials()) {
                auto found = false;
                for (auto& material : _materials) {
                    if (material && material->get_name() == material_name) {
                        found = true;
                        material.reset();
                        break;
                    }
                }
                if (!found) {
                    missing_materials.push_back(material_name);
                }
            }
            if (!missing_materials.empty()) {
                result.missing_materials = missing_materials;
                return result;
            }

            for (const auto& product : recipe->get_products()) {
                add_material(product);
            }

            return result;
        }
    }

    std::cout << "Recipe " << recipe_id << " not found!" << std::endl;
    return ProductionResult{nullptr, {}};
    
    //ProductionResult result;
    //return result;
}