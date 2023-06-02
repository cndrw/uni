#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <exception>
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

struct MyException : std::exception
{
    const char *what() const noexcept override
    {
        return "My own Exception";
    }
};

auto main() -> int
{
    try
    {
        throw MyException();
    }
    catch (const MyException &my_exception)
    {
        std::cerr << my_exception.what() << std::endl;
    }

    return 0;
}
