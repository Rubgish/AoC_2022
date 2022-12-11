#include "utils.hpp"

int file_sum = 0;

class folder
{
private:
    std::string _name;
    std::vector<std::pair<std::string, int>> _files;
    std::vector<folder> _child_folders;
    folder *_parent_folder;

public:
    folder(std::string name, folder *parent_folder);
    std::string get_name();
    void add_file(std::string name, int size);
    void add_child_folder(std::string);
    folder *get_parent_folder();
    folder *move_to_folder(std::string name);
    int total_size();
    ~folder();
};

folder::folder(std::string name, folder *parent_folder)
{
    _name = name;
    _parent_folder = parent_folder;
}

folder::~folder()
{
}

std::string folder::get_name()
{
    return _name;
}

void folder::add_file(std::string name, int size)
{
    _files.push_back(std::make_pair(name, size));
}

void folder::add_child_folder(std::string name)
{
    auto new_folder = folder(name, this);
    _child_folders.push_back(new_folder);
}

folder *folder::get_parent_folder()
{
    return _parent_folder;
}

folder *folder::move_to_folder(std::string name)
{
    for (auto &&x : _child_folders)
    {
        if (x.get_name() == name)
        {
            return &x;
        }
    }

    std::cout << "oops"
              << "\n";
    exit(1);
}

int folder::total_size()
{
    int size = 0;
    for (auto &&x : _child_folders)
    {
        std::cout << x.get_name() << "\n";
        size += x.total_size();
    }

    for (auto &&y : _files)
    {
        std::cout << y.first << " : " << y.second << "\n";
        size += y.second;
    }
    // We only hit this once for each folder, so when we do just
    // add to a global.
    if (size <= 100000)
    {
        file_sum += size;
    }
    return size;
}

int main(int argc, char *argv[])
{
    auto input = read_input("day7_input");
    auto root_folder = folder("/", nullptr);
    auto active_folder = &root_folder;
    for (auto &&x : input)
    {
        if (x.find("$ ls") != std::string::npos)
        {
            continue;
        }
        else if (x.find("dir") != std::string::npos)
        {
            active_folder->add_child_folder(x.substr(4));
        }
        else if (x.find("$ cd ..") != std::string::npos)
        {
            active_folder = active_folder->get_parent_folder();
        }
        else if (x.find("$ cd") != std::string::npos)
        {
            active_folder = active_folder->move_to_folder(x.substr(5));
        }
        else
        {
            auto delimeter = " ";
            auto size = x.substr(0, x.find(delimeter));
            auto filename = x.substr(x.find(delimeter) + 1);
            active_folder->add_file(filename, std::stoi(size));
        }
    }
    std::cout << root_folder.total_size() << "\n";
    std::cout << file_sum << "\n";
}