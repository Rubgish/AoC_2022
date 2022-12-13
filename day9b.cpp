#include "utils.hpp"

class tail
{
private:
    int _x = 0;
    int _y = 0;
    std::map<std::pair<int, int>, int> _visited{};

public:
    tail(/* args */);
    ~tail();
    std::pair<int, int> move(int cursor_x, int cursor_y);
    int visited_squares();
};

tail::tail(/* args */)
{
    _visited.emplace(std::make_pair(0, 0), 1);
}

tail::~tail()
{
}

std::pair<int, int> tail::move(int cursor_x, int cursor_y)
{
    if ((abs(_x - cursor_x) == 2) && (abs(_y - cursor_y) == 2))
    {
        _x = (_x + cursor_x) / 2;
        _y = (_y + cursor_y) / 2;
        _visited.emplace(std::make_pair(_x, _y), 1);
    }
    else if (abs(_x - cursor_x) == 2)
    {
        _x = (_x + cursor_x) / 2;
        _y = cursor_y;
        _visited.emplace(std::make_pair(_x, _y), 1);
    }
    else if (abs(_y - cursor_y) == 2)
    {
        _y = (_y + cursor_y) / 2;
        _x = cursor_x;
        _visited.emplace(std::make_pair(_x, _y), 1);
    }
    return std::make_pair(_x, _y);
}

int tail::visited_squares()
{
    return _visited.size();
}

class cursor
{
private:
    int _x = 0;
    int _y = 0;
    tail _tail1;
    tail _tail2;
    tail _tail3;
    tail _tail4;
    tail _tail5;
    tail _tail6;
    tail _tail7;
    tail _tail8;
    tail _tail9;

public:
    cursor(/* args */);
    ~cursor();
    void move_right(int count);
    void move_left(int count);
    void move_up(int count);
    void move_down(int count);
    int get_visit_count() { return _tail9.visited_squares(); }
};

cursor::cursor(/* args */)
{
}

cursor::~cursor()
{
}

void cursor::move_right(int count)
{
    std::pair<int, int> val;
    for (int i = 0; i < count; i++)
    {
        _x++;
        val = _tail1.move(_x, _y);
        val = _tail2.move(val.first, val.second);
        val = _tail3.move(val.first, val.second);
        val = _tail4.move(val.first, val.second);
        val = _tail5.move(val.first, val.second);
        val = _tail6.move(val.first, val.second);
        val = _tail7.move(val.first, val.second);
        val = _tail8.move(val.first, val.second);
        val = _tail9.move(val.first, val.second);
    }
}

void cursor::move_left(int count)
{
    std::pair<int, int> val;
    for (int i = 0; i < count; i++)
    {
        _x--;
        val = _tail1.move(_x, _y);
        val = _tail2.move(val.first, val.second);
        val = _tail3.move(val.first, val.second);
        val = _tail4.move(val.first, val.second);
        val = _tail5.move(val.first, val.second);
        val = _tail6.move(val.first, val.second);
        val = _tail7.move(val.first, val.second);
        val = _tail8.move(val.first, val.second);
        val = _tail9.move(val.first, val.second);
    }
}

void cursor::move_up(int count)
{
    std::pair<int, int> val;
    for (int i = 0; i < count; i++)
    {
        _y++;
        val = _tail1.move(_x, _y);
        val = _tail2.move(val.first, val.second);
        val = _tail3.move(val.first, val.second);
        val = _tail4.move(val.first, val.second);
        val = _tail5.move(val.first, val.second);
        val = _tail6.move(val.first, val.second);
        val = _tail7.move(val.first, val.second);
        val = _tail8.move(val.first, val.second);
        val = _tail9.move(val.first, val.second);
    }
}

void cursor::move_down(int count)
{
    std::pair<int, int> val;
    for (int i = 0; i < count; i++)
    {
        _y--;
        val = _tail1.move(_x, _y);
        val = _tail2.move(val.first, val.second);
        val = _tail3.move(val.first, val.second);
        val = _tail4.move(val.first, val.second);
        val = _tail5.move(val.first, val.second);
        val = _tail6.move(val.first, val.second);
        val = _tail7.move(val.first, val.second);
        val = _tail8.move(val.first, val.second);
        val = _tail9.move(val.first, val.second);
    }
}

int main(int argc, char *argv[])
{
    auto input = read_input("day9_input");
    cursor cur_cursor;
    for (auto &&x : input)
    {
        auto dir = x.substr(0, 1);
        auto move_count = std::stoi(x.substr(2));
        if (dir == "R")
        {
            cur_cursor.move_right(move_count);
        }
        else if (dir == "L")
        {
            cur_cursor.move_left(move_count);
        }
        else if (dir == "U")
        {
            cur_cursor.move_up(move_count);
        }
        else if (dir == "D")
        {
            cur_cursor.move_down(move_count);
        }
    }
    std::cout << cur_cursor.get_visit_count() << "\n";
}