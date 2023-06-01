#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
class Animal
{
   public:
    virtual void make_noise() const = 0;
};

class Bird;

class Cat : public Animal
{
   public:
    void make_noise() const override
    {
        std::cout << "miau" << std::endl;
    }

    void operator+(const Cat &)
    {
        std::cout << "Cats like each other!" << std::endl;
    }

    void operator+(const Bird &)
    {
        std::cerr << "Cat and Bird don't like each other!" << std::endl;
    }
};

class Bird : public Animal
{
   public:
    void make_noise() const override
    {
        std::cout << "tschirp" << std::endl;
    }

    void operator+(const Cat &)
    {
        std::cerr << "Bird and Cat don't like each other!" << std::endl;
    }

    void operator+(const Bird &)
    {
        std::cout << "Birds like each other!" << std::endl;
    }
};

auto main() -> int
{
    std::vector<std::shared_ptr<Animal>> animals;

    animals.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        if(std::rand() > RAND_MAX / 2)
        {
            animals.push_back(std::make_shared<Bird>());
        }
        else
        {
            animals.push_back(std::make_shared<Cat>());
        }
    } 

    for(const auto& itr : animals)
    {
        itr->make_noise();
    }
    return 0;
}
