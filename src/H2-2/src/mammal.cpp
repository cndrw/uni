#include "animals.hpp"
#include <cstdint>
#include <iostream>

Mammal::Mammal(uint16_t feet_amount, float speed)
{
    feet_ = feet_amount;
    speed_ = speed;
}

Mammal::~Mammal()
{
    Animal::die("Mammal");
}

void Mammal::move(float move_time)
{
    std::cout << "mammal noises" << std::endl;
    xpos_ += speed_ * move_time;
    ypos_ += speed_ * move_time;
    std::cout << "Mammal moved to X: " << xpos_ << " Y: " << ypos_ << std::endl;
}