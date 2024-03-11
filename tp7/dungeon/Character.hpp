#pragma once

#include "Entity.hpp"

class Character : public Entity {
public:
    Character(int x, int y): Entity(x, y) {}

    char get_representation() const override { return 'O'; }

    void update() override {random_move(_x, _y);}

private:
    int _x;
    int _y;
};