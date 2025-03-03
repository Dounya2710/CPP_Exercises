#pragma once

#include "Item.hpp"

//class Character; // forward-declaration

class Potion: public Item {
    public:
        Potion(int width, int height)
        //: Entity(random_value(0, width - 1), random_value(0, height - 1))
        : Item(width, height)
        {}

        char get_representation() const override {
            return '$';
        }

        //void update() override {}

        //void interact_with(Entity& other) override;

        bool should_destroy() const override {
            return consumed;
        }

    private:
        int _width;
        int _height;
        bool consumed = false;
};