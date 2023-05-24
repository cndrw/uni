#include "animals.hpp"
#include <iostream>

auto Animal::get_feet_amount() const -> uint16_t
{
    return feet_;
}

void Animal::die(const std::string& animal_name)
{
   std::cout << animal_name << " died. :(" << std::endl;
}

Animal::~Animal()
{
    std::cout << "ARGh" << std::endl;
}