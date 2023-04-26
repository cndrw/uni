#include <cstdint>
#include <iostream>

class Student
{
   private:
    int16_t bank_account_num;

   public:
    int16_t num_of_exams = 0;
    int32_t id_number;
    std::string name;

    Student(std::string par_name, int16_t par_bank_num, int32_t par_id)
        : bank_account_num{par_bank_num}, id_number{par_id}, name{par_name}
    {
    }

    void update_bank_account(const int16_t par_bank_num)
    {
        bank_account_num = par_bank_num;
    }

    void print() const
    {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Student name: " << name << std::endl;
        std::cout << "Number of Exams: " << num_of_exams << std::endl;
        std::cout << "ID-Number: " << id_number << std::endl;
        std::cout << "Bank Account Number: " << bank_account_num << std::endl;
    }
};

auto main() -> int
{
    Student student("Link", 2, 3);
    student.print();
    student.update_bank_account(1234);
    student.print();

    return 0;
}
