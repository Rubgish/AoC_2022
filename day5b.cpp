#include "utils.hpp"


int main(int argc, char *argv[])
{
    // Cheating because lazy
    std::vector<std::string> crates = {
        "",
"WRF",
"THMCDVWP",
"PMZNL",
"JCHR",
"CPGHQTB",
"GCWLFZ",
"WVLQZJGC",
"PNRFWTVC",
"JWHGRSV",
    };
    auto input = read_input("day5_input");
    std::regex reg_exp("([0-9]+) [a-z]+ ([0-9]+) [a-z]+ ([0-9]+)");
    std::smatch reg_out;
    for (auto &&x : input)
    {
        if (std::regex_search(x, reg_out, reg_exp))
        {
            std::string values = "";
            for (int y = 0; y < std::stoi(reg_out[1]); y++)
            {

                values.push_back(crates.at(std::stoi(reg_out[2])).back());
                crates.at(std::stoi(reg_out[2])).pop_back();
            }
            for (auto &&z: values)
            {
                crates.at(std::stoi(reg_out[3])).push_back(values.back());
                values.pop_back();
            }
        }
    }
    for (auto && y: crates)
    {
        std::cout << y << "\n";
    }
}