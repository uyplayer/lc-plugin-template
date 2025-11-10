

#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> &array);
void print(const std::vector<int> &array, const char *tag);

int main()
{

    std::cout << " Hello insertion-sort \n";

    std::vector<int> array{1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6,
                           3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print(array, "原始数组");
    insertion_sort(array);
    print(array, "排序结果");

    return 0;
}

void insertion_sort(std::vector<int> &array)
{

    auto array_size = array.size();

    auto current_index = 0;
    while (current_index < array_size)
    {

        for (auto i = current_index; i > 0; i--)
        {
            if (array[i] < array[i - 1])
            {
                auto tmp = array[i - 1];
                array[i - 1] = array[i];
                array[i] = tmp;
            }
            else
            {
                // 进入这里说明不用对比，array[current_index] 已经排序位置了
                break;
            }
        }

        current_index++;
    }
}

void insertion_sort1(std::vector<int> &array)
{

    auto array_size = array.size();

    auto current_index = 0;
    while (current_index < array_size)
    {
        for (auto i = current_index; i > 0; i--)
        {
            if (array[i] > array[i - 1])
            {
                auto tmp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = tmp;
            }
            else
            {
                // 因为 左边已经排序好的区域
                break;
            }
        }
        current_index++;
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
