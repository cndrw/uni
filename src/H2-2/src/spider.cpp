#include "animals.hpp"
#include <cstdint>
#include <iostream>

Spider::Spider(float speed)
{
    speed_ = speed;
    feet_ = 8;
}

Spider::~Spider()
{
    Animal::die("Spider");
}

// Just some useless comment

void Spider::move(float move_time) 
{
    std::cout << "i don't know which sound a spide does" << std::endl;
    xpos_ += speed_ * move_time;
    ypos_ += speed_ * move_time; 
    std::cout << "Spider moved to X: " << xpos_ << " Y: " << ypos_ << std::endl;
    std::cout << "just a filler text" << std::endl;
}
