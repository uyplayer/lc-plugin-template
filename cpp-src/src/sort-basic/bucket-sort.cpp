
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "print_vector.h"

void bucketSort(std::vector<int> &nums);
int main()
{

    std::cout << "Hello bucket-sort\n";

    std::vector<int> array{1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6, 3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print_vector(array, "原始数组");
    bucketSort(array);
    print_vector(array, "排序结果");

    return 0;
}

void bucketSort(std::vector<int> &nums)
{
    const size_t n = nums.size();
    if (n <= 1)
        return;
    auto minmax = minmax_element(nums.begin(), nums.end());
    int min_value = *minmax.first;
    int max_value = *minmax.second;
    int k = (max_value - min_value) / nums.size() + 1;
    std::vector<std::vector<int>> buckets(k);

    for (int num : nums)
    {
        int i = (num - min_value) / nums.size();
        buckets[i].push_back(num);
    }
    for (std::vector<int> &bucket : buckets)
    {
        sort(bucket.begin(), bucket.end());
    }

    int i = 0;
    for (std::vector<int> &bucket : buckets)
    {
        for (int num : bucket)
        {
            nums[i++] = num;
        }
    }
}
