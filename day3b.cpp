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
    bool c1[data_len] = {};
    bool c2[data_len] = {};
    bool c3[data_len] = {};
    auto counter = 0;
    for (auto &&x : input)
    {
        for (auto &&y : x)
        {
            if ((counter % 3) == 0)
            {
                c1[value_getter(y)] = true;
            }
            else if ((counter % 3) == 1)
            {
                c2[value_getter(y)] = true;
            }
            else
            {
                c3[value_getter(y)] = true;
            }
        }
        if ((counter % 3) == 2)
        {
            for (int i = 0; i < data_len; i++)
            {
                if (c1[i] && c2[i] && c3[i])
                {
                    total_value += (i + 1);
                }
            }
            for (int i = 0; i < data_len; i++)
            {
                c1[i] = false;
                c2[i] = false;
                c3[i] = false;
            }
        }
        counter++;
    }
    std::cout << total_value << "\n";
}