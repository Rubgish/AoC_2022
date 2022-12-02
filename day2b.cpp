#include "utils.hpp"

int hand_result(const char o, const char y, const int choice_value)
{
    auto r_o = 'A';
    auto p_o = 'B';
    auto s_o = 'C';
    auto r = 'X';
    auto p = 'Y';
    auto s = 'Z';
    int result = 0;
    if ((o == r_o && y == r) || (o == p_o && y == p) || (o == s_o && y == s))
    {
        result = 3;
    }
    else if ((o == r_o && y == p) || (o == p_o && y == s) || (o == s_o && y == r))
    {
        result = 6;
    }
    else
    {
        result = 0;
    }
    return (result + choice_value);
}

int choice_value(const char your_hand)
{
    if (your_hand == 'X')
    {
        return 1;
    }
    else if (your_hand == 'Y')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

// Work out what you played and send that back
char calc_your_hand(const char o, const char your_hand)
{
    auto r_o = 'A';
    auto p_o = 'B';
    auto s_o = 'C';
    auto r = 'X';
    auto p = 'Y';
    auto s = 'Z';

    // Lose
    if (your_hand == r)
    {
        if (o == r_o)
        {
            return s;
        }
        else if (o == p_o)
        {
            return r;
        }
        else
        {
            return p;
        }
    }
    // draw
    else if (your_hand == p)
    {
        if (o == r_o)
        {
            return r;
        }
        else if (o == p_o)
        {
            return p;
        }
        else
        {
            return s;
        }
    }
    // Win
    else
    {
        if (o == r_o)
        {
            return p;
        }
        else if (o == p_o)
        {
            return s;
        }
        else
        {
            return r;
        }
    }
}

int main(int argc, char *argv[])
{
    auto input = read_input("day2_input");
    int total_score = 0;
    for (auto &&x : input)
    {
        auto hand_val = calc_your_hand(x.at(0), x.at(2));
        auto choice_val = choice_value(hand_val);
        total_score += hand_result(x.at(0), hand_val, choice_val);
    }
    std::cout << total_score << "\n";
}
