#include "animals.hpp"
#include <cstdint>
#include <iostream>

void Animal::die()
{
    std::cout << "an Animal died :(" << std::endl;
}

Mammal::Mammal(uint16_t feet_amount, float speed)
{
    feet_ = feet_amount;
    speed_ = speed;
}

void Mammal::move(uint16_t new_x, uint16_t new_y)
{
    std::cout << "mammal noises" << std::endl;
    xpos_ += new_x;
    ypos_ += new_y;
}