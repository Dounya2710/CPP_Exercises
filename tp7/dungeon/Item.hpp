#pragma once

#include "Entity.hpp"

class Item: public Entity {
public:
    Item(int x, int y)
        : Entity(x, y)
    {}

    char get_representation() const override { return '?'; }
    void update() override {}
};