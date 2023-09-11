#include <iostream>
#include <string>

void print(std::string&& str)
{
    std::cout << str << std::endl;
}

auto main() -> int
{ 
    std::string sentence = "Hallo Sophia!";
    print("Hallo");
}