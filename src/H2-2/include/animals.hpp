#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <cstdint>

class Animal
{
    public:
    uint8_t feet;

    auto get_feet_number() const -> uint8_t;
};

class Spider : public Animal
{
    public:
    Spider();
};

class Mammal : public Animal
{
    public:
    Mammal();
};

#endif