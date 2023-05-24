#include <iostream>
#include "animals.hpp"


auto main() -> int
{
    Spider tarantula = Spider(2.2);
    Mammal groundhog(4, 8.2);

    std::cout << "Tarantula has " << tarantula.get_feet_amount() << " feet" << std::endl;
    std::cout << "Groundhog has " << groundhog.get_feet_amount() << " feet" << std::endl;

    tarantula.move(5.0);
    groundhog.move(2.0);
    return 0;
}
