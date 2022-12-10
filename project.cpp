#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int rows;
std::unordered_map<std::string, long long unsigned> computed_values;

long long unsigned compute(std::vector<int> &stairs)
{
    std::string str_stairs;
    for (int i = 0; i < rows; i++)
    {
        str_stairs += std::to_string(stairs[i]);
    }

    if (computed_values.count(str_stairs) > 0)
    {
        return computed_values[str_stairs];
    }

    int row = rows - 1, height = 1;
    long long unsigned result = 0;

    while (row > 0 && stairs[row - 1] >= stairs[row])
    {
        if (stairs[row] > height)
        {
            height++;
        }

        if (stairs[row - 1] > stairs[row])
        {
            height = 1;
        }

        row--;
    };

    if (stairs[row] == 0)
    {
        return 0;
    }

    while (height > 0)
    {
        std::vector<int> stairs_copy(stairs);

        for (int i = 0; i < height; i++)
        {
            stairs_copy[row + i] -= height;
        }

        result += height > 1 ? compute(stairs_copy) + 1 : compute(stairs_copy);
        height--;
    }

    computed_values[str_stairs] = result;
    return result;
}

int main()
{
    int columns;
    bool empty = true;
    std::cin >> rows >> columns;

    std::vector<int> stairs(rows);
    for (int i = 0; i < rows; i++)
    {
        std::cin >> stairs[i];

        if (stairs[i] != 0)
        {
            empty = false;
        }
    }

    if (empty)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::cout << compute(stairs) + 1 << std::endl;
    return 0;
}
