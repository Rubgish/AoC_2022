#include "utils.hpp"

void permute(std::pair<char, int> (*field)[70], int val, int x, int y)
{
    if (x > 0)
    {
        if (field[x - 1][y].second == -1)
        {
            if (field[x - 1][y].first <= (field[x][y].first + 1))
            {
                field[x - 1][y].second = val + 1;
            }
        }
    }
    if (x < 40)
    {
        if (field[x + 1][y].second == -1)
        {
            if (field[x + 1][y].first <= (field[x][y].first + 1))
            {
                field[x + 1][y].second = val + 1;
            }
        }
    }
    if (y > 0)
    {
        if (field[x][y - 1].second == -1)
        {
            if (field[x][y - 1].first <= (field[x][y].first + 1))
            {
                field[x][y - 1].second = val + 1;
            }
        }
    }
    if (y < 69)
    {
        if (field[x][y + 1].second == -1)
        {
            if (field[x][y + 1].first <= (field[x][y].first + 1))
            {
                field[x][y + 1].second = val + 1;
            }
        }
    }
}

void search(std::pair<char, int> (*field)[70], int val)
{
    for (int i = 0; i < 41; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            if (field[i][j].second == val)
            {
                permute(field, val, i, j);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    auto input = read_input("day12_input");
    std::pair<char, int> field[41][70]{};
    int goal_i = 0;
    int goal_j = 0;
    int i = 0;
    for (auto &&x : input)
    {
        int j = 0;
        for (auto &&y : x)
        {
            if (y == 'S')
            {
                field[i][j] = std::make_pair('a', -1);
            }
            else if (y == 'E')
            {
                goal_i = i;
                goal_j = j;
                field[i][j] = std::make_pair(char(123), -1);
            }
            else
            {
                field[i][j] = std::make_pair(y, -1);
            }
            j++;
        }
        i++;
    }
    int best_search = 352;
    for (int i = 0; i < 41; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            int search_val = 0;
            if (field[i][j].first == 'a')
            {
                field[i][j].second = 0;
                while (field[goal_i][goal_j].second == -1)
                {
                    search(field, search_val);
                    search_val++;
                    if (search_val > best_search)
                    {
                        break;
                    }
                }
                if (search_val < best_search)
                {
                    best_search = search_val;
                }
                // reset
                for (int a = 0; a < 41; a++)
                {
                    for (int b = 0; b < 70; b++)
                    {
                        field[a][b].second = -1;
                    }
                }
            }
        }
    }

    std::cout << best_search << "\n";
}