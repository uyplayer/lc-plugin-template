

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

    // 从个位到最高位，重复“计数 -> 前缀和 -> 分配”
    for (int exp = 1; mx / exp > 0; exp *= RADIX)
    {
        int cnt[RADIX] = {0};

        // 1) 计数：这一位是 0..9 各有多少个
        for (int x : nums)
        {
            int d = (x / exp) % RADIX; // 0..RADIX-1
            ++cnt[d];                  // 等价于 cnt[d] += 1;
        }

        // 2) 前缀和：把“个数”变成“在 out 里的起始写入位置”
        for (int i = 1; i < RADIX; ++i)
            cnt[i] += cnt[i - 1];
        // 也可写成从前累加；下面分配时用 --cnt[d] 反向填充更直观

        // 3) 稳定分配：倒序遍历，按当前位把元素放到 out 的正确位置
        for (int i = (int)nums.size() - 1; i >= 0; --i)
        {
            int d = (nums[i] / exp) % RADIX;
            out[--cnt[d]] = nums[i]; // 先 -- 再写，保证稳定
        }
        nums.swap(out); // 本轮结果成为下一轮的输入
    }
}