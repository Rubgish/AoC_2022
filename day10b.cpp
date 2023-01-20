#include "utils.hpp"

int main(int argc, char *argv[])
{
    std::regex reg_exp("([a-z]+) ([-0-9]+)");
    std::smatch reg_out;
    auto input = read_input("day10_input");

    int cycle_count = 0;
    int register_val = 1;
    int pixel = 0;
    int row = 0;
    bool result[6][40]{false};

    for (auto &&x : input)
    {
        if (std::regex_search(x, reg_out, reg_exp))
        {
            auto change = std::stoi(reg_out[2]);

            if (abs(pixel - register_val) <= 1)
            {
                result[row][pixel] = true;
            }
            cycle_count++;
            pixel++;
            if (pixel > 39)
            {
                pixel = 0;
                row++;
            }
            if (abs(pixel - register_val) <= 1)
            {
                result[row][pixel] = true;
            }
            cycle_count++;
            pixel++;
            if (pixel > 39)
            {
                pixel = 0;
                row++;
            }
            register_val += change;
        }
        else
        {
            if (abs(pixel - register_val) <= 1)
            {
                result[row][pixel] = true;
            }
            pixel++;
            if (pixel > 39)
            {
                pixel = 0;
                row++;
            }
            cycle_count++;
        }
    }
    for (auto &&x : result)
    {
        for (auto &&y : x)
        {
            if (y)
            {
                std::cout << "#";
            }
            else
            {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
}