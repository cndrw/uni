#include <cstdint>
#include <iostream>

namespace test
{
using MyCppStruct = struct
{
    int8_t a = 0;
    float b = 0.0f;

    auto print() const -> void
    {
        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
};
}  // namespace test

auto main() -> int
{
    test::MyCppStruct my_struct;
    std::cout << "Printing struct my_struct: " << std::endl;
    my_struct.print();
    return 0;
}
