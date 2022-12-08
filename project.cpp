#include <iostream>
#include <vector>
#include <string>

int rows;

int fn(std::vector<int> &stairs)
{
    int row = rows - 1, height = 1, result = 0;

    while (row > 0 && stairs.at(row - 1) >= stairs.at(row))
    {
        if (stairs.at(row) > height)
        {
            height++;
        }

        if (stairs.at(row - 1) > stairs.at(row))
        {
            height = 1;
        }

        row--;
    };

    if (stairs.at(row) == 0)
    {
        return 0;
    }

    while (height > 0)
    {
        std::vector<int> stairs_copy(stairs);

        for (int i = 0; i < height; i++)
        {
            stairs_copy.at(row + i) -= height;
        }

        result += height > 1 ? fn(stairs_copy) + 1 : fn(stairs_copy);
        height--;
    }

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
        std::cin >> stairs.at(i);

        if (stairs.at(i) != 0)
        {
            empty = false;
        }
    }

    if (empty)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::cout << fn(stairs) + 1 << std::endl;

    return 0;
}
