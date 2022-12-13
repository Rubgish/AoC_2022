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
    void move(int cursor_x, int cursor_y);
    int visited_squares();
};

tail::tail(/* args */)
{
    _visited.emplace(std::make_pair(0, 0), 1);
}

tail::~tail()
{
}

void tail::move(int cursor_x, int cursor_y)
{
    if (abs(_x - cursor_x) == 2)
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
    tail _tail;

public:
    cursor(/* args */);
    ~cursor();
    void move_right(int count);
    void move_left(int count);
    void move_up(int count);
    void move_down(int count);
    int get_visit_count() { return _tail.visited_squares(); }
};

cursor::cursor(/* args */)
{
}

cursor::~cursor()
{
}

void cursor::move_right(int count)
{
    for (int i = 0; i < count; i++)
    {
        _x++;
        _tail.move(_x, _y);
    }
}

void cursor::move_left(int count)
{
    for (int i = 0; i < count; i++)
    {
        _x--;
        _tail.move(_x, _y);
    }
}

void cursor::move_up(int count)
{
    for (int i = 0; i < count; i++)
    {
        _y++;
        _tail.move(_x, _y);
    }
}

void cursor::move_down(int count)
{
    for (int i = 0; i < count; i++)
    {
        _y--;
        _tail.move(_x, _y);
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