#pragma once

#include "Entity.hpp"
#include <iostream>

class Item: public Entity {
    public:
        Item(int width, int height)
            : Entity(random_value(0, width - 1), random_value(0, height - 1))
            {}

        virtual void update() = 0;

        virtual void interact_with(Entity& other) = 0;

        void consume() {
            is_consumed == true;
        }

        bool should_destroy() const override {
            return is_consumed;
        }

        virtual ~Item() = default;

    private:
        int _width;
        int _height;
        bool is_consumed = false;
};