#include "utils.hpp"

bool unique_string(std::string &str)
{
    std::set<char> size_check(str.begin(), str.end());
    if (str.size() == size_check.size())
    {
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    auto input = read_input("day6_input");
    std::string last_values = "";
    int char_count = 0;
    for (auto &&x : input)
    {
        for (auto &&y : x)
        {
            char_count++;
            last_values.push_back(y);
            if (last_values.size() >= 15)
            {
                last_values.erase(0,1);
                if (unique_string(last_values))
                {
                    std::cout << char_count << "\n";
                    return 0;
                }
            }
        }
    }
}