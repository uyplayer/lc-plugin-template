

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "print_vector.h"

void radix_sort(std::vector<int> &nums);
int main()
{

    std::cout << "Hello radix-sort\n";

    std::vector<int> array{1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6, 3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print_vector(array, "原始数组");
    radix_sort(array);
    print_vector(array, "排序结果");

    return 0;
}

void radix_sort(std::vector<int> &nums)
{
    const size_t n = nums.size();
    if (n <= 1)
        return;
    int mx = *std::max_element(nums.begin(), nums.end());
    std::vector<int> out(nums.size());
    const int RADIX = 10;

    // 从最低位开始按位循环排序：`exp` 依次取 1、RADIX、RADIX²…，直到 `exp` 超过最大值 `mx` 的位数为止
    for (int exp = 1; mx / exp > 0; exp *= RADIX)
    {
        int cnt[RADIX] = {0};

        //   统计当前位数的出现次数
        for (int x : nums)
        {
            int d = (x / exp) % RADIX;
            ++cnt[d];
        }

        // 做前缀和
        for (int i = 1; i < RADIX; ++i)
            cnt[i] += cnt[i - 1];
        // 从最后一个元素开始，倒着遍历 nums（保证“稳定”——相同数字时，后出现的先放到更右边的位置
        for (int i = (int)nums.size() - 1; i >= 0; --i)
        {
            // 把当前元素 nums[i] 在“以 RADIX 为基数、位权为 exp”这一位上的数字取出来——也就是取它的当前位数码（十进制时 exp=1/10/100 对应个位/十位/百位）
            int d = (nums[i] / exp) % RADIX;
            // 把当前元素放到它在输出数组中应该去的正确位置上（根据当前位的数字 d 决定）
            out[--cnt[d]] = nums[i];
        }
        // 把本轮排好序的结果 out 和原数组 nums 交换，让 nums 立刻变成本轮结果，省去拷贝，准备下一轮
        nums.swap(out);
    }
}