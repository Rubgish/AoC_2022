#include "utils.hpp"

class Tree
{
private:
    int _height = 0;
    int _visibility = 0;

public:
    Tree(/* args */);
    ~Tree();

    void set_height(int height);
    int get_height();
    void add_visibility(int input);
    int get_visibility();
};

Tree::Tree(/* args */)
{
    _height = 0;
}

Tree::~Tree()
{
}

void Tree::set_height(int height)
{
    if (height > 9)
    {
        std::cout << height
                  << "\n";
    }
    _height = height;
}

void Tree::add_visibility(int input)
{
    _visibility += input;
}

int Tree::get_height()
{
    return _height;
}

int Tree::get_visibility()
{
    return _visibility;
}

int main(int argc, char *argv[])
{
    auto input = read_input("day8_input");

    static int left = 1;
    static int right = 2;
    static int up = 4;
    static int down = 8;

    const int array_size = 99;

    // [0][99] -> top right
    // [99][0] -> bottom left
    Tree visibility[array_size][array_size]{};
    int line = 0;
    for (auto &&x : input)
    {
        int pos = 0;
        for (auto &&y : x)
        {
            visibility[line][pos].set_height(y - '0');
            pos++;
        }
        line++;
    }

    for (int i = 0; i < array_size; i++)
    {
        int max_l = -1;
        int max_r = -1;
        int max_u = -1;
        int max_d = -1;
        for (int j = 0; j < array_size; j++)
        {
            // viewable from the left
            if (max_l != 9)
            {
                auto cur_l = visibility[i][j].get_height();
                if (cur_l > max_l)
                {
                    visibility[i][j].add_visibility(left);
                    max_l = cur_l;
                }
            }

            // viewable from the right
            if (max_r != 9)
            {
                auto cur_r = visibility[i][array_size - j - 1].get_height();
                if (cur_r > max_r)
                {
                    visibility[i][array_size - j - 1].add_visibility(right);
                    max_r = cur_r;
                }
            }

            // viewable from up
            if (max_u != 9)
            {
                auto cur_u = visibility[j][i].get_height();
                if (cur_u > max_u)
                {
                    visibility[j][i].add_visibility(up);
                    max_u = cur_u;
                }
            }

            // viewable from down
            if (max_d != 9)
            {
                auto cur_d = visibility[array_size - j - 1][i].get_height();
                if (cur_d > max_d)
                {
                    visibility[array_size - j - 1][i].add_visibility(down);
                    max_d = cur_d;
                }
            }
        }
    }

    int count = 0;
    for (int a = 0; a < array_size; a++)
    {
        for (int b = 0; b < array_size; b++)
        {
            if (visibility[a][b].get_visibility() != 0)
            {
                count++;
            }
        }
    }
    std::cout << count << "\n";
}