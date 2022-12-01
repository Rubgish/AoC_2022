#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day1_input");
    int elf_cal = 0;
    int max_cal = 0;
    for (auto &&x : input)
    {
        if (x != "")
        {
            elf_cal = elf_cal + std::stoi(x);
        }
        else
        {
            if (elf_cal > max_cal)
            {
                max_cal = elf_cal;
            }
            elf_cal = 0;
        }
    }
    std::cout << max_cal << "\n";
}