#include <cstdint>
#include <iostream>
#include <memory>


auto main() -> int
{
    uint size = 5;
    std::cout << "Size: ";


    auto u_ptr = std::make_shared<int[]>(size);

    for(uint i = 0; i < size; i++)
    {
        u_ptr.get()[i] = i + 1;
        std::cout << "Element " << i << " ist " << u_ptr.get()[i] << std::endl;  
    }

    return 0;
}
