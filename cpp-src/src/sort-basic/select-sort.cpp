

#include <iostream>
#include <vector>

void select_sort(const std::vector<int> &array);

int main() {

  std::cout << "hello select sort \n";

  std::vector<int> array{1, 4, 8, 9,  3,  4,  7,   2,  9,  6,  3, 58,4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};
  select_sort(array);

  return 0;
}



void select_sort(const std::vector<int> &array) {
  std::cout << "原始数组 \n";
  for (std::size_t i = 0; i < array.size(); ++i) {
    std::cout << array[i];
    if (i + 1 < array.size()) {
      std::cout << ", ";
    }
  }
  std::cout << '\n';
  
  auto array_size = array.size();


}
