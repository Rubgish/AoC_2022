#include "utils.hpp"

int main(int argc, char *argv[])
{
    std::regex reg_exp("([a-z]+) ([-0-9]+)");
    std::smatch reg_out;
    auto input = read_input("day10_input");

    int cycle_count = 0;
    int register_val = 1;
    int retval = 0;

    for (auto &&x : input)
    {
        if (std::regex_search(x, reg_out, reg_exp))
        {
            auto change = std::stoi(reg_out[2]);
            cycle_count++;
            if ((cycle_count % 40) == 20)
            {
                retval += (cycle_count * register_val);
            }
            cycle_count++;
            if ((cycle_count % 40) == 20)
            {
                retval += (cycle_count * register_val);
            }
            register_val += change;
        }
        else
        {
            cycle_count++;
            if ((cycle_count % 40) == 20)
            {
                retval += (cycle_count * register_val);
            }
        }
        if (cycle_count > 220)
        {
            break;
        }
    }
    std::cout << retval << "\n";
}