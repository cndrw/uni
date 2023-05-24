#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

class Animal
{
    public:
    virtual void make_noise() = 0;
    std::string name;
};

class Cat;

class Bird : public Animal
{
    public:
    explicit Bird(const std::string& name_par)
    {
        this->name = name_par;
    }

    void make_noise() override
    {
        std::cout << "tschirp" << std::endl;
    }

    void operator+(const Bird& bird);
    void operator+(const Cat& cat);
};

class Cat : public Animal
{
    public:
    explicit Cat(const std::string& name_par)
    {
        this->name = name_par;
        
    }

    void make_noise() override
    {
        std::cout << "grhh" << std::endl;
    }

    void operator+(const Bird& bird)
    {
        std::cout << bird.name << " wrid von " << name << " gejagt!" << std::endl;
    }

    void operator+(const Cat& cat)
    {
        std::cout << name << "und " << cat.name << " spielen Zusammen!" << std::endl;
    }
};

void Bird::operator+(const Bird& bird)
{
    std::cout << name << " und " << bird.name << " fliegen zum Süden" << std::endl;
}

void Bird::operator+(const Cat& cat)
{
    std::cout << name << " flieht vor " << cat.name << std::endl;
}


auto main() -> int
{
    Cat cat("Katze1");
    Cat cat2("Katze2");
    Bird bird("Vogel1");
    Bird bird2("Vogel2");

    cat.make_noise();
    bird.make_noise();

    cat + cat2;
    cat + bird;
    bird + cat;
    bird + bird2;
    

    return 0;
}
