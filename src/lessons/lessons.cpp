#include <cstdint>
#include <iostream>
#include <memory>


auto main() -> int
{
    uint size = 0;
    std::cout << "Size: ";
    std::cin >> size;


    auto u_ptr = std::make_unique<int[]>(size);

    for(uint i = 0; i < size; i++)
    {
        u_ptr.get()[i] = i + 1;
        std::cout << "Element " << i << " ist " << u_ptr.get()[i] << std::endl;  
    }

    return 0;
}
