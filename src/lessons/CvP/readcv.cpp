#include <iostream>
#include <vector>

void Print(std::string& str)
{
    std::cout << str << std::endl;
}

int main()
{
    std::string str = "Hallo";
    Print(str);
}