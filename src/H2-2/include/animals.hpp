#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <cstdint>
#include <string>

class Animal
{
   public:
    uint16_t xpos_ = 0;
    uint16_t ypos_ = 0;
    // virtual void  move(uint16_t new_x, uint16_t new_y) = 0;
    auto get_feet_amount() const -> uint16_t;
    static void die(const std::string&);
    virtual void move(float) = 0;
    virtual ~Animal();

   protected:
    float speed_;
    uint16_t feet_;
};

class Spider : public Animal
{
   public:
    explicit Spider(float);
    void move(float move_time) override;
    ~Spider() override;
};

class Mammal : public Animal
{
   public:
    explicit Mammal(uint16_t, float);
    void move(float move_time) override;
    ~Mammal() override;
};

#endif