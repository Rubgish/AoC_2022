#include "utils.hpp"

int value_getter(char &input)
{
    if (isupper(input))
    {
        return (int(input) - 'A' + 26);
    }
    else
    {
        return (int(input) - 'a');
    }
}

int main(int argc, char *argv[])
{
    auto input = read_input("day3_input");
    static int data_len = 52;
    int total_value = 0;
    for (auto &&x : input)
    {
        bool c1[data_len] = {};
        bool c2[data_len] = {};
        auto compartment_size = x.length() / 2;
        auto c_1_letters = x.substr(0, compartment_size);
        auto c_2_letters = x.substr(compartment_size, compartment_size);

        for (auto &&y : c_1_letters)
        {
            c1[value_getter(y)] = true;
        }
        for (auto &&z : c_2_letters)
        {
            c2[value_getter(z)] = true;
        }
        for (int i = 0; i < data_len; i++)
        {
            if (c1[i] && c2[i])
            {
                total_value += (i + 1);
            }
        }
    }
    std::cout << total_value << "\n";
}