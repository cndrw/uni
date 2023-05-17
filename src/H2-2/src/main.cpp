#include <iostream>
#include "animals.hpp"


auto main() -> int
{
    Spider tarantula;
    Mammal groundhog(4);

    std::cout << "Tarantula has " << tarantula.get_feet_amount() << " feet" << std::endl;
    std::cout << "Groundhog has " << groundhog.get_feet_amount() << " feet" << std::endl;
    return 0;
}
