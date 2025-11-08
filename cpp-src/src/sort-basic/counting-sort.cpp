#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "print_vector.h"

void countingSort(std::vector<int> &a);
int main()
{

    std::cout << "Hello counting-sort\n";

    std::vector<int> array{1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6, 3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print_vector(array, "原始数组");
    countingSort(array);
    print_vector(array, "排序结果");
    return 0;
}

void countingSort(std::vector<int> &a)
{
    if (a.empty())
        return;
    int maxVal = *max_element(a.begin(), a.end());
    std::vector<int> count(maxVal + 1, 0);

    // 统计计数
    // 索引0 表示 0 的出现次数
    // 索引1 表表示 元素1 出现次数
    for (int num : a)
        count[num]++;

    // 重建排序数组
    // maxVal 0 开始意味着咱们0开始便便利，所以数组自然有序
    // index 表示元素放在真确位置
    int index = 0;
    for (int i = 0; i <= maxVal; ++i)
    {
        while (count[i]-- > 0)
        {
            a[index++] = i;
        }
    }
}

void countingSort1(std::vector<int> &a)
{
    if (a.empty())
        return;

    // 找最小值和最大值
    int minVal = *std::min_element(a.begin(), a.end());
    int maxVal = *std::max_element(a.begin(), a.end());

    // 偏移量 = minVal
    // 计数数组长度 = maxVal - minVal + 1
    std::vector<int> count(maxVal - minVal + 1, 0);

    // 统计计数
    for (int num : a)
        count[num - minVal]++; // 索引 = 数字 - minVal，保证索引非负

    // 重建排序数组
    int index = 0;
    for (int i = 0; i <= maxVal - minVal; ++i)
    {
        while (count[i]-- > 0)
        {
            a[index++] = i + minVal; // 恢复原来的数字
        }
    }
}
