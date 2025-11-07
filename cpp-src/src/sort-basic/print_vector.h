/*
 * @Author: uyplayer
 * @Email: uyplayer@outlook.com
 * @Date: 2025-11-07 19:54:31
 * @LastEditTime: 2025-11-07 19:58:50
 * @LastEditors: uyplayer
 * @Description:
 * @FilePath: /cpp-src/include/print.h
 * @copyright Copyright (c) 2025 by uyplayer
 */

#pragma once

#include <iostream>
#include <vector>

inline void print_vector(const std::vector<int> &array, const char *tag)
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
