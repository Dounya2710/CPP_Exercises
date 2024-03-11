#pragma once

#include "Item.hpp"
#include "Random.hpp"

class Trap: public Item {
    public:
        Trap(int width, int height)
            : Item(random_value(0, width - 1), random_value(0, height - 1)) {}

        char get_representation() const override { return 'X'; }
        void update() override {}
};