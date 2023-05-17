#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <cstdint>

class Animal
{
    public:
    auto get_feet_amount() const -> uint16_t;

    protected:
    uint16_t feet_;
};

class Spider : public Animal
{
    public:
    Spider();
};

class Mammal : public Animal
{
    public:
    explicit Mammal(uint16_t feet_amount);
};

#endif