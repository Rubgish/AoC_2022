#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day1_input");
    int elf_cal = 0;
    std::vector<int> all_elves = {};
    for (auto &&x : input)
    {
        if (x != "")
        {
            elf_cal = elf_cal + std::stoi(x);
        }
        else
        {
            all_elves.push_back(elf_cal);
            elf_cal = 0;
        }
    }

    std::sort(all_elves.begin(), all_elves.end());
    std::reverse(all_elves.begin(), all_elves.end());
    auto total_val = all_elves.at(0) + all_elves.at(1) + all_elves.at(2);
    std::cout << total_val << "\n";
}