#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "print_vector.h"

int main()
{

    std::cout << "Hello counting-sort\n";
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
