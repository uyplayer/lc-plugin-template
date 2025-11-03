

#include <iostream>
#include <vector>

void shell_sort(std::vector<int> &array);
void print(const std::vector<int> &array, const char *tag);

int main()
{

    std::cout << "hello shell sort \n";

    std::vector<int> array{1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6,
                           3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print(array, "原始数组");
    shell_sort(array);
    print(array, "排序后的数组");

    return 0;
}

void shell_sort(std::vector<int> &a)
{

    auto generator = 2;
    // a.size() = 6
    // [10, 8, 6, 4, 2, 1]，gap = 2
    // 子串  ： 路径1：索引 0, 2, 4 → [10, 6, 2]  ；路径2：索引 1, 3, 5 → [8, 4, 1]
    for (size_t gap = a.size() / generator; gap > 0; gap /= generator)
    {
        // gap ：  2， 1
        for (size_t i = gap; i < a.size(); ++i)
        {
            int x = a[i];
            size_t j = i;
            // 移动位置 就是处理gap
            while (j >= gap && a[j - gap] > x)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = x;
        }
    }
}

void print(const std::vector<int> &array, const char *tag)
{
    if (tag != nullptr && *tag != '\0')
    {
        std::cout << tag << ": ";
    }

    for (std::size_t i = 0; i < array.size(); ++i)
    {
        std::cout << array[i];
        if (i + 1 < array.size())
        {
            std::cout << ' ';
        }
    }

    std::cout << '\n';
}
