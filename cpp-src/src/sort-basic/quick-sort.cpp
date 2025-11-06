#include <iostream>
#include <vector>
#include <utility> // for std::swap

void quick_sort(std::vector<int> &array);
void quick_sort(std::vector<int> &array, int first, int last);
int partition(std::vector<int> &array, int first, int last);
void print(const std::vector<int> &array, const char *tag);

int main()
{
    std::cout << "Hello quick-sort\n";

    std::vector<int> array{
        1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6,
        3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print(array, "原始数组");
    quick_sort(array);
    print(array, "排序结果");

    return 0;
}

// 无参包装：把整个数组作为区间
void quick_sort(std::vector<int> &array)
{
    if (array.empty())
        return;
    quick_sort(array, 0, static_cast<int>(array.size()) - 1);
}

// 递归快速排序
void quick_sort(std::vector<int> &array, int first, int last)
{
    if (first >= last)
        return; // 终止条件：区间长度<=1

    int p = partition(array, first, last);
    quick_sort(array, first, p - 1);
    quick_sort(array, p + 1, last);
}

int partition(std::vector<int> &array, int first, int last)
{
    auto pivot = array[last];
    auto i = first;
    for (auto j = first; j < last; j++)
    {
        if (array[j] < pivot)
        {
            std::swap(array[j], array[i]);
            i++;
        }
    }
    std::swap(array[i], array[last]);
    return i;
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
            std::cout << ' ';
    }
    std::cout << '\n';
}
