#include "animals.hpp"
#include <cstdint>
#include <iosream>

Spider::Spider(float speed)
{
    speed_ = speed;
    feet_ = 8;
}

void Spider::move(uint16_t new_x, uint16_t new_y) override 
{
    std::cout << "i don't know which sound a spide does" << std::endl;
    xpos_ += new_x;
    ypos_ += new_y; 
}

Spider::~Spider()
{
    Animal::die();
}