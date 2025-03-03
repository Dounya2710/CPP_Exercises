#pragma once

#include "Entity.hpp"
#include "Trap.hpp"
#include "Potion.hpp"
#include <iostream>

class Character: public Entity {
    public:
        Character(int x, int y)
        : Entity(x, y)
        , rep('O')
        {}

    char get_representation() const override {
        return rep;
    }

    void update() override {
        random_move(&Entity::get_x(), &Entity::get_y());
    }

    void interact_with(Entity& other) override {
        const auto* trap = dynamic_cast<Trap*>(&other);
        const auto* potion = dynamic_cast<Potion*>(&other);
        if(trap != nullptr) {
            if(rep == 'O') {
                rep = 'o';
            }
            if(rep == 'o') {
                rep = '.';
            }
            std::cout << "Character stepped on a trap " << rep << std::endl;
        }

        if(potion != nullptr) {
            if(rep == 'o') {
                rep = 'O';
            }
            //potion->consume();
            std::cout << "Character healed thanks to a potion " << rep << std::endl;
        }
        //std::cout << "Character interacts with " << rep << std::endl;
    }

    bool should_destroy() const override {
        return rep == '.';
    }

    ~Character() {
        std::cout << "A character died at position (" << Entity.get_x() << ", " << Entity.get_y() << ")" << std::endl;
    }

    private:
        /*int _x;
        int _y;*/
        char rep;
};