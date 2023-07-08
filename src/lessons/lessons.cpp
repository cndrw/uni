#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <exception>

int fib(int k)
{
    return k == 0 ? 0 :  k == 1 ? 1 : fib(k-1) + fib(k-2);
}

auto main() -> int
{
    int num;
    scanf("%d", &num);
    std::cout << fib(num) << std::endl;
    return 0;
}
