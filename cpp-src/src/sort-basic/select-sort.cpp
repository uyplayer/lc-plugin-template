

#include <iostream>
#include <vector>

void select_sort(std::vector<int> &array);
void select_sort_stable(std::vector<int> &array);

int main()
{
    std::cout << "hello select sort \n";

    std::vector<int> array{1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6,
                           3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    std::cout << "原始数组 \n";
    for (std::size_t i = 0; i < array.size(); ++i)
    {
        std::cout << array[i];
        if (i + 1 < array.size())
        {
            std::cout << ", ";
        }
    }

    select_sort(array);

    std::cout << "快速排序后数组 \n";
    for (std::size_t i = 0; i < array.size(); ++i)
    {
        std::cout << array[i];
        if (i + 1 < array.size())
        {
            std::cout << ", ";
        }
    }
    std::cout << '\n';

    return 0;
}

/**
 * @brief 快速排序算法
 *
 * @param array 要排序的数组
 */
void select_sort(std::vector<int> &array)
{

    std::cout << '\n';

    std::size_t array_size = array.size();
    std::size_t current_index = 0;
    while (current_index < array_size)
    {

        // 记录当前的循环的最小元素的index
        std::size_t min_num_index = current_index;
        for (std::size_t i = current_index + 1; i < array_size; i++)
        {

            if (array[i] < array[min_num_index])
            {
                min_num_index = i;
            }
        }
        // 这一轮里找到最小值
        auto tmp = array[current_index];
        array[current_index] = array[min_num_index];
        array[min_num_index] = tmp;
        current_index++;
    }
}

/**
 * @brief 选择排序稳定版本
 * 基本原理是每一轮找到最小元素后对右侧进行旋转，就是就会
 * [ X(i), X(i+1), ..., X(minIdx-1), minVal ] 变为 [ minVal, X(i), X(i+1), ..., X(minIdx-1) ]
 * @param array 要排序的数组
 *
 */
void select_sort_stable(std::vector<int> &array)
{
}