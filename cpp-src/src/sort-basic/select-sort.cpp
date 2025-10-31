

#include <iostream>
#include <vector>

void select_sort(const std::vector<int> &array);

int main()
{
    std::cout << "hello select sort \n";

    std::vector<int> array{1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6,
                           3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};
    select_sort(array);

    return 0;
}

/**
 * @brief 快速排序算法
 *
 * @param array 要排序的数组
 */
void select_sort(const std::vector<int> &array)
{
    std::cout << "原始数组 \n";
    for (std::size_t i = 0; i < array.size(); ++i)
    {
        std::cout << array[i];
        if (i + 1 < array.size())
        {
            std::cout << ", ";
        }
    }
    std::cout << '\n';

    auto array_size = array.size();
    auto current_index = 0;
    while (current_index < array_size)
    {
        for (int i = current_index; i < array_size; i++)
        {
        }
    }
}
