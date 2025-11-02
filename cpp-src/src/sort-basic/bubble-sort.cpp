

#include <vector>
#include <iostream>
#include <span>

void bubble_sort(std::vector<int> &array);
void print(const std::vector<int> &array, const char *tag);
void bubble_sort_improvement(std::vector<int> &array);

int main()
{

    std::cout << "hello bubble sort \n";

    std::vector<int> array{1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6,
                           3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print(array, "原始数组");
    bubble_sort_improvement(array);
    print(array, "排序结果");

    return 0;
}

void bubble_sort(std::vector<int> &array)
{

    auto array_size = array.size();

    auto current_index = 0;
    while (current_index < array_size)
    {

        for (auto i = array_size - 1; i > current_index; i--)
        {
            if (array[i] < array[i - 1])
            {
                auto tmp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = tmp;
            }
        }
        current_index++;
    }
}

void bubble_sort_improvement(std::vector<int> &array)
{

    auto array_size = array.size();

    auto current_index = 0;
    while (current_index < array_size)
    {
        // 如果没发生交换 说明元素位置正确
        bool swapped = false;
        for (auto i = array_size - 1; i > current_index; i--)
        {
            if (array[i] < array[i - 1])
            {
                auto tmp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = tmp;
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
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
