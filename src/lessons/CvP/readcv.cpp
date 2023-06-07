#include <iostream>
#include <vector>

int main()
{
  rapidcsv::Document doc("colhdr.csv");

  std::vector<float> col = doc.GetColumn<float>("Close");
  std::cout << "Read " << col.size() << " columes." << std::endl;

    for(int i = 0; i < col.size(); i++)
    {
        if(col[i] == "2017-02-22")
        {
            std::cout << col[i] << std::endl;
        }
    }
}