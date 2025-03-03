#include "Potion.hpp"
#include "Character.hpp"

void Potion::interact_with(Entity& other) override {
    const auto* character = dynamic_cast<Character*>(&other);
    if(character != nullptr) {
        //consumed = true;
        consume();
        std::cout << "Potion interacts with " << other.get_representation() << std::endl;
    }
    //std::cout << "Potion interacts with " << other.get_representation() << std::endl;
}