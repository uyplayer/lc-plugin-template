
#include <iostream>
#include <vector>
#include "print_vector.h"

int main()
{
    std::cout << " Hello heap-sort \n";

    std::vector<int> array{
        1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6,
        3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print_vector(array, "原始数组");

    print_vector(array, "排序结果");
    return 0;
}