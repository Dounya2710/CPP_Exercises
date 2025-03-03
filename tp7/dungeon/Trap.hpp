#pragma once
#include "Item.hpp"

class Trap: public Item {
    public:
        Trap(int width, int height)
        //: Entity(random_value(0, width - 1), random_value(0, height - 1))
        : Item(width, height) 
        {}

        char get_representation() const override {
            return 'X';
        }

        //void update() override {}

        void interact_with(Entity &other) override {
            //std::cout << "Trap interacts with " << other.get_representation() << std::endl;
            trigged = true;
        }

        bool should_destroy() const override {
            return trigged;
        }

    private:
        int _width;
        int _height;
        bool trigged = false;
};