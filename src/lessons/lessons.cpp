#include <cstdint>
#include <iostream>
#include <memory>


class Shape
{
    public: 
    void set_width(int8_t width_in)
    {
        m_width_ = width_in;
    }

    void set_height(int8_t height_in)
    {
        m_height_ = height_in;
    }

    protected:
    int8_t m_width_;
    int8_t m_height_;
};

class PaintCost
{
    public:
    static auto get_cost(double area) -> double
    {
        return area * 70;
    }
};

class Triangle : public Shape, public PaintCost
{
    public:
    auto get_area() -> double
    {
        return 0.5f * (m_width_ * m_height_);
    }
};

auto main() -> int
{
    Triangle triangle;
    triangle.set_height(5);
    triangle.set_width(5);

    double area = triangle.get_area();

<<<<<<< HEAD
    // auto u_ptr = std::make_shared<int[]>(size);

    std::shared_ptr<int[]> u_ptr(new int[size]);

    auto p = std::make_shared<int>();
    
    auto e = std::make_shared<char>();
    

    for(uint i = 0; i < size; i++)
    {
        u_ptr.get()[i] = i + 1;
        std::cout << "Element " << i << " ist " << u_ptr.get()[i] << std::endl;  
    }
=======
    std::cout << "Fläche ist: " << area << std::endl;
    std::cout << "Kosten sind: " << PaintCost::get_cost(area) << std::endl;
>>>>>>> 34ff4ec (10.05)

    return 0;
}
