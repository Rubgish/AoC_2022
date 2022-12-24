#include "utils.hpp"
bool north(std::pair<bool, int> (*a)[250], int x, int y)
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

bool south(std::pair<bool, int> (*a)[250], int x, int y)
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

bool east(std::pair<bool, int> (*a)[250], int x, int y)
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

bool west(std::pair<bool, int> (*a)[250], int x, int y)
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

void move(std::pair<bool, int> (*array)[250], int turn, int x, int y)
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
bool update_grid(std::pair<bool, int> (*array)[250])
{
    bool moved = false;
    for (int i = 0; i < 250; i++)
    {
        for (int j = 0; j < 250; j++)
        {
            if (array[i][j].second == -1)
            {
                moved = true;
                array[i][j].first = false;
                array[i][j].second = 0;
            }
            else if (array[i][j].second == 2)
            {
                moved = true;
                array[i][j].first = true;
                array[i][j].second = 0;
            }
            // idk what fucks up here but whatever just ignore it
            else if (array[i][j].second > 2)
            {
                array[i][j].second = 0;
            }
        }
    }
    return moved;
}

int main(int argc, char *argv[])
{
    // SO ABOUT THAT 10 STEP LIMIT THING. OOPS.
    std::pair<bool, int> array[250][250]{};
    auto input = read_input("day23_input");

    int i = 75;
    for (auto &&x : input)
    {
        int j = 75;
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
    int z = 1;
    bool done_moving = false;
    while (!done_moving)
    {
        for (int a = 0; a < 250; a++)
        {
            for (int b = 0; b < 250; b++)
            {
                if (array[a][b].first)
                {
                    move(array, z, a, b);
                }
            }
        }
        // LMAO
        for (int a = 0; a < 250; a++)
        {
            for (int b = 0; b < 250; b++)
            {
                if (array[a][b].first)
                {
                    move(array, z, a, b);
                }
            }
        }
        z++;
        done_moving = !(update_grid(array));
    }

    int x_low = 250;
    int x_high = 0;
    int y_low = 250;
    int y_high = 0;
    for (int a = 0; a < 250; a++)
    {
        for (int b = 0; b < 250; b++)
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
    std::cout << z - 1 << "\n";
}