#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day4_input");
    std::regex reg_exp("([0-9]+)-([0-9]+),([0-9]+)-([0-9]+)");
    std::smatch reg_out;
    int contained_count = 1000;
    for (auto &&x : input)
    {
        if (std::regex_search(x, reg_out, reg_exp))
        {
            auto a1 = std::stoi(reg_out[1]);
            auto a2 = std::stoi(reg_out[2]);
            auto b1 = std::stoi(reg_out[3]);
            auto b2 = std::stoi(reg_out[4]);
            if ((b1 > a2) || (a1 > b2))
            {
                contained_count--;
            }
        }
    }
    std::cout << contained_count << "\n";
}