#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <functional>

std::string desc = R"(Object
Person
Dog
Cat
Tree
House
)";

class Entity {
public:
    virtual void print() const = 0;
    virtual ~Entity() = default;
};

class Factory {
public:
    using Builder = std::function<std::unique_ptr<Entity>()>;

    template <typename TDerivedEntity, typename... Args>
    void register_entity(const std::string& id, Args&&... args) {
        auto builder = [=]() -> std::unique_ptr<Entity> { return std::make_unique<TDerivedEntity>(const_cast<typename std::remove_reference<Args>::type&>(args)...); };
        builders[id] = builder;
    }

    std::unique_ptr<Entity> build(const std::string& id) const {
        auto it = builders.find(id);
        if (it != builders.end()) {
            return it->second();
        }
        return nullptr;
    }

private:
    std::map<std::string, Builder> builders;
};

class Object : public Entity {
public:
    void print() const override { std::cout << "Object" << std::endl; }
};

class Tree : public Object {
public:
    void print() const override { std::cout << "Tree" << std::endl; }
};

class Person : public Entity {
public:
    explicit Person(std::string name)
        : _name { std::move(name) }
    {}

    void print() const override { std::cout << _name << std::endl; }

    void set_name(std::string name) { _name = std::move(name); }
    const std::string& get_name() const { return _name; }

private:
    std::string _name;
};

class Animal : public Entity {
public:
    explicit Animal(std::string species)
        : _species { std::move(species) }
    {}

    void print() const override { std::cout << _species << std::endl; }

private:
    std::string _species;
};

class House : public Object {
public:
    explicit House(std::reference_wrapper<Person> owner)
        : _owner { owner }
    {}

    void print() const override { std::cout << "House owned by " << _owner.get().get_name() << std::endl; }

private:
    std::reference_wrapper<Person> _owner;
};

int main() {
    Factory factory;
    factory.register_entity<Object>("Object");
    factory.register_entity<Person>("Person", "Jean");
    factory.register_entity<Animal>("Dog", "dog");
    factory.register_entity<Tree>("Tree");

    Person person("Picsou");
    factory.register_entity<House>("House", std::ref(person));

    person.set_name("Picsou");

    std::vector<std::unique_ptr<Entity>> entities;

    std::stringstream s;
    s << desc;
    while (!s.eof()) {
        std::string id;
        s >> id;
        std::string arg;
        std::getline(s, arg);
        if (!arg.empty() && arg[0] == ' ') {
            arg = arg.substr(1);
        }
        entities.emplace_back(factory.build(id));
    }

    for (const auto& e : entities) {
        if (e != nullptr) {
            e->print();
        }
    }

    return 0;
}