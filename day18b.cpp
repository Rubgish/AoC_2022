#include "utils.hpp"

int face_count(bool (*array)[23][23], int x, int y, int z)
{
    int face_count = 6;
    if (array[x - 1][y][z])
    {
        face_count--;
    }
    if (array[x + 1][y][z])
    {
        face_count--;
    }
    if (array[x][y - 1][z])
    {
        face_count--;
    }
    if (array[x][y + 1][z])
    {
        face_count--;
    }
    if (array[x][y][z - 1])
    {
        face_count--;
    }
    if (array[x][y][z + 1])
    {
        face_count--;
    }

    return face_count;
}

void random_walk(bool (*array)[23][23], int x, int y, int z)
{
    int rand_moves = 0;
    std::set<std::vector<int>> visited_squares = {};
    visited_squares.insert({x, y, z});
    int no_change = 1000;
    int size = 1;
    int unchanged_count = 0;

    for (int a = 0; a < 5000000; a++)
    {
        auto rand = std::rand() % 6;
        if (rand == 0)
        {
            x++;
            if (x > 21)
            {
                return;
            }
        }
        if (rand == 1)
        {
            x--;
            if (x < 1)
            {
                return;
            }
        }
        if (rand == 2)
        {
            y++;
            if (y > 21)
            {
                return;
            }
        }
        if (rand == 3)
        {
            y--;
            if (y < 1)
            {
                return;
            }
        }
        if (rand == 4)
        {
            z++;
            if (z > 21)
            {
                return;
            }
        }
        if (rand == 5)
        {
            z--;
            if (z < 1)
            {
                return;
            }
        }
        if (array[x][y][z])
        {
            if (rand == 0)
            {
                x--;
            }
            if (rand == 1)
            {
                x++;
            }
            if (rand == 2)
            {
                y--;
            }
            if (rand == 3)
            {
                y++;
            }
            if (rand == 4)
            {
                z--;
            }
            if (rand == 5)
            {
                z++;
            }
        }
        else
        {
            visited_squares.insert({x, y, z});
        }
        if (visited_squares.size() == size)
        {
            unchanged_count++;
        }
        else
        {
            size = visited_squares.size();
            unchanged_count = 0;
        }

        if (unchanged_count == no_change)
        {
            for (auto &&m : visited_squares)
            {
                array[m[0]][m[1]][m[2]] = true;
            }
            return;
        }
    }
}

int main(int argc, char *argv[])
{
    bool field[23][23][23]{false};
    auto input = read_input("day18_input");
    std::regex reg_exp("([0-9]+),([0-9]+),([0-9]+)");
    std::smatch reg_out;
    for (auto &&x : input)
    {
        if (std::regex_search(x, reg_out, reg_exp))
        {
            field[std::stoi(reg_out[1])][std::stoi(reg_out[2])][std::stoi(reg_out[3])] = true;
        }
    }

    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            for (int k = 0; k < 22; k++)
            {
                if (!field[i][j][k])
                {
                    random_walk(field, i, j, k);
                }
            }
        }
    }

    int total_count = 0;
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            for (int k = 0; k < 22; k++)
            {
                if (field[i][j][k])
                {
                    total_count += face_count(field, i, j, k);
                }
            }
        }
    }
    std::cout << total_count << "\n";
}