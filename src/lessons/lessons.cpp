#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <exception>

class Developer
{
    private:
    std::string m_name;
    public:
    Developer(const std::string& name) : m_name{name}{}
    auto get_name() const -> const std::string
    {
        return m_name;
    }
};


auto main() -> int
{
    Developer dev("Marius");
    std::cout << dev.get_name() << std::endl;
    return 0;
}
