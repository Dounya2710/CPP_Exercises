#include "ProgramData.hpp"


void ProgramData::add_material(std::string name)
{
    _materials.push_back(std::make_unique<Material>(name));
}

void ProgramData::get_materials(std::vector<const Material*>& materials) const
{
    materials.clear();
    for (const auto& material : _materials)
    {
        if (material)
        {
            materials.push_back(material.get());
        }
    }
}

void ProgramData::register_recipe(std::vector<std::string> materials, std::vector<std::string> products)
{
    Recipe recipe(materials, products, _recipes.size() + 1);
    _recipes.push_back(recipe);
    std::cout << "Recipe " << recipe << " has been registered" << std::endl;
}

void ProgramData::collect_doable_recipes(std::vector<const Recipe*>& recipes) const
{
    recipes.clear();
    for (const auto& recipe : _recipes)
    {
        bool allMaterialsAvailable = true;

        for (const auto& materialName : recipe.getMaterials())
        {
            bool materialFound = false;
            for (const auto& material : _materials)
            {
                if (material && material->getName() == materialName)
                {
                    materialFound = true;
                    break;
                }
            }

            if (!materialFound)
            {
                allMaterialsAvailable = false;
                break;
            }
        }

        if (allMaterialsAvailable)
        {
            recipes.push_back(&recipe);
        }
    }
}

ProductionResult ProgramData::produce(size_t recipe_id)
{
    ProductionResult result;

    if (recipe_id <= 0 || recipe_id > _recipes.size())
    {
        std::cerr << "No recipe is identified with " << recipe_id << std::endl;
        return result;
    }

    const Recipe& recipe = _recipes[recipe_id - 1];
    bool allMaterialsAvailable = true;
    for (const auto& materialName : recipe.getMaterials())
    {
        bool materialFound = false;
        for (auto it = _materials.begin(); it != _materials.end(); ++it)
        {
            if ((*it)->getName() == materialName)
            {
                materialFound = true;
                _materials.erase(it);
                break;
            }
        }

        if (!materialFound)
        {
            allMaterialsAvailable = false;
            result.missing_materials.push_back(materialName);
        }
    }

    if (allMaterialsAvailable)
    {
        result.recipe = &recipe;
    }

    return result;
}
