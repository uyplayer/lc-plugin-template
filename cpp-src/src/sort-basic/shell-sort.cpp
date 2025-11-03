

#include <iostream>
#include <vector>

void print(const std::vector<int> &array, const char *tag);

int main()
{

    std::cout << "hello shell sort \n";

    std::vector<int> array{1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6,
                           3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print(array, "原始数组");

    return 0;
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
        {
            std::cout << ' ';
        }
    }

    std::cout << '\n';
}
