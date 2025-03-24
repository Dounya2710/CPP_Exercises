#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <string>

struct Entity
{
    Entity(std::string name, int life)
    : name { std::move(name) }
    , life { life }
    {}

    std::string name;
    int life = 100;
};

using Entities = std::list<std::unique_ptr<Entity>>;

void apply_on_entities_with_type(std::map<std::string, Entities>& all_entities,
                                 const std::string& type,
                                 const std::function<void(Entities&)>& fcn)
{
    auto it = all_entities.find(type);
    if(it != all_entities.end()) {
        fcn(it->second);
    }
}

void print_entities(std::map<std::string, Entities>& all_entities, const std::string& type)
{
    apply_on_entities_with_type(all_entities, type, [&type](Entities& entities) {std::cout << type << " entities:\n";
        for (const auto& entity : entities) {
            std::cout << "- " << entity->name << " (life: " << entity->life << ")\n";
        }
    });
}

void hit_monsters(std::map<std::string, Entities>& all_entities, int life_decrease)
{
    apply_on_entities_with_type(all_entities, "Monster", [life_decrease](Entities& entities){
        for(const auto& entity: entities) {
            entity->life = life_decrease;
        }
    });
}

void remove_dead_entities(std::map<std::string, Entities>& all_entities)
{
    auto remove_if_dead = [](Entities& entities) {
        entities.remove_if([](const std::unique_ptr<Entity>& entity) { return entity->life <= 0; });
    };
    apply_on_entities_with_type(all_entities, "Monster", remove_if_dead);
    apply_on_entities_with_type(all_entities, "Human", remove_if_dead);
}

void add_entity(std::map<std::string, Entities>& all_entities, const std::string& type, std::unique_ptr<Entity> entity)
{
    apply_on_entities_with_type(all_entities, type, [all_entities](Entities& entities) {all_entities.insert(type, entities);}); // A CORRIGER !!
}

int main()
{
    std::map<std::string, Entities> entities;

    {
        auto monsters = Entities {};
        monsters.push_back(std::make_unique<Entity>("Troll", 1000));
        monsters.push_back(std::make_unique<Entity>("Blob", 30));
        
        entities.emplace("Monster", std::move(monsters));
    }

    {
        auto humans = Entities {};
        humans.push_back(std::make_unique<Entity>("Bob", 60));
 
        entities.emplace("Human", std::move(humans));
    }

    print_entities(entities, "Human");
    print_entities(entities, "Monster");
    print_entities(entities, "Items");  // Nothing should happen if the type doesn't exist

    hit_monsters(entities, 200);
    remove_dead_entities(entities); // Blob should die
    add_entity(entities, "Monster", std::make_unique<Entity>("Wolf", 400));

    print_entities(entities, "Monster");
    
    hit_monsters(entities, 2000);
    remove_dead_entities(entities);

    print_entities(entities, "Monster"); // All monsters should be dead

    return 0;
}

