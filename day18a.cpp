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