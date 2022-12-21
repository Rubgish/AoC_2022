#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day20_input");
    std::vector<std::pair<long, long>> initial_values{};
    std::vector<std::pair<long, long>> current_values{};

    long position = 0;
    for (auto &&x : input)
    {
        long val = std::stol(x)*811589153;
        initial_values.push_back(std::make_pair(val, position));
        position++;
    }
    current_values = initial_values;
    for (long y =0; y < 10; y++)
    {
        for (auto &&x : initial_values)
        {
            auto it = std::find(current_values.begin(), current_values.end(), x);
            if (it != current_values.end())
            {
                auto index = std::distance(current_values.begin(), it);
                auto new_index = (index + it->first);
                new_index = ((new_index % ((long)current_values.size()-1)) + ((long)current_values.size()-1)) % ((long)current_values.size()-1);
                if (new_index == 0)
                {
                    new_index = (long)current_values.size() - 1;
                }
                current_values.erase(it);
                auto new_it = current_values.begin() + new_index;
                current_values.insert(new_it, x);
            }
        }
    }
    auto it = std::find(current_values.begin(), current_values.end(), std::make_pair((long)0,(long)4333));
    auto index = std::distance(current_values.begin(), it);
    long val_thing = ((long)index + 1000) % current_values.size();
    long val_thing_2 = ((long)index + 2000) % current_values.size();
    long val_thing_3 = ((long)index + 3000) % current_values.size();
    std::cout << current_values[val_thing].first << "\n";
    std::cout << current_values[val_thing_2].first << "\n";
    std::cout << current_values[val_thing_3].first << "\n";
    std::cout << current_values[val_thing].first + current_values[val_thing_2].first + current_values[val_thing_3].first << "\n";

    // not -1825297344
}