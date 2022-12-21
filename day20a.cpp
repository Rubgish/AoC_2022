#include "utils.hpp"

int main(int argc, char *argv[])
{
    auto input = read_input("day20_input");
    std::vector<std::pair<int, int>> initial_values{};
    std::vector<std::pair<int, int>> current_values{};

    int position = 0;
    for (auto &&x : input)
    {
        initial_values.push_back(std::make_pair(std::stoi(x), position));
    }
    current_values = initial_values;

    for (auto &&x : initial_values)
    {
        auto it = std::find(current_values.begin(), current_values.end(), x);
        if (it != current_values.end())
        {
            auto index = std::distance(current_values.begin(), it);
            auto new_index = (index + it->first);
            std::cout << "new index: " << new_index << "\n";
            while (new_index < 0)
            {
                new_index = current_values.size() + new_index - 1;
                std::cout << "new index loop: " << new_index << "\n";
            }
            while (new_index >= current_values.size())
            {
                new_index -= current_values.size();
                std::cout << "new index loop 2: " << new_index << "\n";
            }
            current_values.erase(it);
            auto new_it = current_values.begin() + new_index;
            current_values.insert(new_it, x);
            for (auto &&y : current_values)
            {
                std::cout << y.first << ", ";
            }
            std::cout << "\n";
        }
    }
    for (auto &&x : current_values)
    {
        std::cout << x.first << "\n";
    }
    std::cout << current_values[(1000 % current_values.size())].first << "\n";
    std::cout << current_values[(2000 % current_values.size())].first << "\n";
    std::cout << current_values[(3000 % current_values.size())].first << "\n";
}