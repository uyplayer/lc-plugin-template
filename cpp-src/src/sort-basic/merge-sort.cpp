#include <iostream>
#include <vector>
#include "print_vector.h"

void merge_sort(std::vector<int> &array, int first_index, int last_index);
void merge(std::vector<int> &array, int first_index, int middle_index, int last_index);

int main()
{
    std::cout << " Hello merge-sort \n";

    std::vector<int> array{
        1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6,
        3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print_vector(array, "原始数组");

    if (!array.empty())
    {
        merge_sort(array, 0, static_cast<int>(array.size()) - 1);
    }

    print_vector(array, "排序结果");
    return 0;
}

void merge_sort(std::vector<int> &array, int first_index, int last_index)
{
    if (first_index >= last_index)
    {
        return;
    }

    int middle_index = first_index + (last_index - first_index) / 2;

    merge_sort(array, first_index, middle_index);
    merge_sort(array, middle_index + 1, last_index);

    merge(array, first_index, middle_index, last_index);
}

void merge(std::vector<int> &array, int first_index, int middle_index, int last_index)
{

    int left_num = middle_index - first_index + 1; // [first_index..middle_index]
    int right_num = last_index - middle_index;     // [middle_index+1..last_index]

    std::vector<int> left;
    std::vector<int> right;
    left.reserve(left_num);
    right.reserve(right_num);

    for (int i = 0; i < left_num; ++i)
    {
        left.push_back(array[first_index + i]);
    }

    for (int i = 0; i < right_num; ++i)
    {
        right.push_back(array[middle_index + 1 + i]);
    }

    int i = 0, j = 0;
    int k = first_index;
    while (i < left_num && j < right_num)
    {
        if (left[i] <= right[j])
        {
            array[k++] = left[i++];
        }
        else
        {
            array[k++] = right[j++];
        }
    }

    // 剩余元素拷回
    while (i < left_num)
    {
        array[k++] = left[i++];
    }

    while (j < right_num)
    {
        array[k++] = right[j++];
    }
}
