#pragma once

#include "Item.hpp"
#include "Random.hpp"

class Potion: public Item {
    public:
        Potion(int width, int height)
            : Item(random_value(0, width - 1), random_value(0, height - 1)) {}

        char get_representation() const override { return '$'; }
        void update() override {}
};