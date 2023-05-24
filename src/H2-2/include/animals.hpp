#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <cstdint>

class Animal
{
    public:
    //virtual void  move(uint16_t new_x, uint16_t new_y) = 0;
    auto get_feet_amount() const -> uint16_t;
    static void die();
    virtual void move(uint16_t new_x, uint16_t new_y) = 0;

    protected:
    uint16_t xpos_;
    uint16_t ypos_;
    float speed_;
    uint16_t feet_;

};

class Spider : public Animal
{
    public:
    explicit Spider(float speed);
    void move(uint16_t new_x, uint16_t new_y);

    private:
    ~Spider();
};

class Mammal : public Animal
{
    public:
    explicit Mammal(uint16_t feet_amount, float speed);
    void move(uint16_t new_x, uint16_t new_y);
};

#endif