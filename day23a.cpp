#include "utils.hpp"
bool north(std::pair<bool, int> (*a)[96], int x, int y)
{
    if (a[x - 1][y].first || a[x - 1][y - 1].first || a[x - 1][y + 1].first)
    {
        return false;
    }
    else
    {
        a[x - 1][y].second += 1;
        if (a[x - 1][y].second > 2)
        {
            // two movers!
            a[x][y].second = 0;
        }
        else
        {
            a[x][y].second = -1;
        }
        return true;
    }
}

bool south(std::pair<bool, int> (*a)[96], int x, int y)
{
    if (a[x + 1][y].first || a[x + 1][y - 1].first || a[x + 1][y + 1].first)
    {
        return false;
    }
    else
    {
        a[x + 1][y].second += 1;
        if (a[x + 1][y].second > 2)
        {
            // two movers!
            a[x][y].second = 0;
        }
        else
        {
            a[x][y].second = -1;
        }
        return true;
    }
}

bool east(std::pair<bool, int> (*a)[96], int x, int y)
{
    if (a[x][y + 1].first || a[x - 1][y + 1].first || a[x + 1][y + 1].first)
    {
        return false;
    }
    else
    {
        a[x][y + 1].second += 1;
        if (a[x][y + 1].second > 2)
        {
            // two movers!
            a[x][y].second = 0;
        }
        else
        {
            a[x][y].second = -1;
        }
        return true;
    }
}

bool west(std::pair<bool, int> (*a)[96], int x, int y)
{
    if (a[x][y - 1].first || a[x - 1][y - 1].first || a[x + 1][y - 1].first)
    {
        return false;
    }
    else
    {
        a[x][y - 1].second += 1;
        if (a[x][y - 1].second > 2)
        {
            // two movers!
            a[x][y].second = 0;
        }
        else
        {
            a[x][y].second = -1;
        }
        return true;
    }
}

void move(std::pair<bool, int> (*array)[96], int turn, int x, int y)
{
    if (!(array[x + 1][y].first ||
          array[x + 1][y - 1].first ||
          array[x + 1][y + 1].first ||
          array[x][y + 1].first ||
          array[x][y - 1].first ||
          array[x - 1][y].first ||
          array[x - 1][y - 1].first ||
          array[x - 1][y + 1].first))
    {
        return;
    }
    if ((turn % 4) == 1)
    {
        if (north(array, x, y))
        {
            return;
        }
        if (south(array, x, y))
        {
            return;
        }
        if (west(array, x, y))
        {
            return;
        }
        if (east(array, x, y))
        {
            return;
        }
    }
    if ((turn % 4) == 2)
    {
        if (south(array, x, y))
        {
            return;
        }
        if (west(array, x, y))
        {
            return;
        }
        if (east(array, x, y))
        {
            return;
        }
        if (north(array, x, y))
        {
            return;
        }
    }
    if ((turn % 4) == 3)
    {
        if (west(array, x, y))
        {
            return;
        }
        if (east(array, x, y))
        {
            return;
        }
        if (north(array, x, y))
        {
            return;
        }
        if (south(array, x, y))
        {
            return;
        }
    }
    if ((turn % 4) == 0)
    {
        if (east(array, x, y))
        {
            return;
        }
        if (north(array, x, y))
        {
            return;
        }
        if (south(array, x, y))
        {
            return;
        }
        if (west(array, x, y))
        {
            return;
        }
    }
}

// update grid rules:
//      first val is just a bool for if that square is occupied
//      set second val to -1 if moving, 0 otherwise, exactly 2 if something wants to move there.
void update_grid(std::pair<bool, int> (*array)[96])
{
    for (int i = 0; i < 96; i++)
    {
        for (int j = 0; j < 96; j++)
        {
            if (array[i][j].second == -1)
            {
                array[i][j].first = false;
                array[i][j].second = 0;
            }
            else if (array[i][j].second == 2)
            {
                array[i][j].first = true;
                array[i][j].second = 0;
            }
            else if (array[i][j].second > 2)
            {
                array[i][j].second = 0;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // Desperately hope that part B won't be more than 10 steps so I can use a fixed size array
    std::pair<bool, int> array[96][96]{};
    auto input = read_input("day23_input");

    int i = 15;
    for (auto &&x : input)
    {
        int j = 15;
        for (auto &&y : x)
        {
            if (y == '#')
            {
                array[i][j] = std::make_pair(true, 0);
            }
            else
            {
                array[i][j] = std::make_pair(false, 0);
            }
            j++;
        }
        i++;
    }
    for (int z = 1; z < 11; z++)
    {
        for (int a = 0; a < 96; a++)
        {
            for (int b = 0; b < 96; b++)
            {
                if (array[a][b].first)
                {
                    move(array, z, a, b);
                }
            }
        }
        // LMAO
        for (int a = 0; a < 96; a++)
        {
            for (int b = 0; b < 96; b++)
            {
                if (array[a][b].first)
                {
                    move(array, z, a, b);
                }
            }
        }
        update_grid(array);
    }

    int x_low = 96;
    int x_high = 0;
    int y_low = 96;
    int y_high = 0;
    for (int a = 0; a < 96; a++)
    {
        for (int b = 0; b < 96; b++)
        {
            if (array[a][b].first)
            {
                if (a < x_low)
                {
                    x_low = a;
                }
                if (a > x_high)
                {
                    x_high = a;
                }
                if (b < y_low)
                {
                    y_low = b;
                }
                if (b > y_high)
                {
                    y_high = b;
                }
            }
        }
    }
    int empty_count = 0;
    for (int a = x_low; a <= x_high; a++)
    {
        for (int b = y_low; b <= y_high; b++)
        {
            if (!array[a][b].first)
            {
                std::cout << ".";
                empty_count++;
            }
            else
            {
                std::cout << "#";
            }
        }
        std::cout << "\n";
    }
    std::cout << empty_count << "\n";
}