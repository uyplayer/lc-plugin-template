#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "print_vector.h"

int main()
{
    std::cout << "Hello heap-sort\n";

    std::vector<int> array{
        1, 4, 8, 9, 3, 4, 7, 2, 4, 8, 5, 63, 9, 31, 455, 36, 48, 2135, 6,
        3, 4, 8, 19, 6, 3, 58, 4, 1, 4, 64, 64, 64, 651, 31, 98, 98, 3031, 3};

    print_vector(array, "原始数组");

    std::priority_queue<int> pq;

    for (int x : array)
        pq.push(x);

    std::vector<int> sorted_desc;
    while (!pq.empty())
    {
        sorted_desc.push_back(pq.top());
        pq.pop();
    }

    print_vector(sorted_desc, "降序排序结果");

    std::reverse(sorted_desc.begin(), sorted_desc.end());
    print_vector(sorted_desc, "升序排序结果");

    return 0;
}

void siftDown(vector<int> &a, int root, int heap_size)
{
    while (true)
    {
        // 取当前根节点的左右边 叶子节点索引
        int left = 2 * root + 1;
        if (left >= heap_size)
            break;
        int right = left + 1;
        int largest = root;

        if (a[left] > a[largest])
            largest = left;
        if (right < heap_size && a[right] > a[largest])
            largest = right;
        if (largest == root)
            break;
        // 切换位置
        std::swap(a[root], a[largest]);
        root = largest;
    }
}

void buildMaxHeap(std::vector<int> &array)
{
    // 从最后一个非叶子节点开始，下沉到根,这就是最后结果根节点成为最大值
    auto size = array.size();
    for (auto i = (size / 2) - 1; i >= 0; --i)
    {
        siftDown(array, i, size);
    }
}

void heapSort(std::vector<int> &a)
{
    int n = static_cast<int>(a.size());
    if (n <= 1)
        return;
    // 先构建大堆  就是根节点最大值的
    buildMaxHeap(a);
    for (int heap_size = n; heap_size > 1; --heap_size)
    {
        std::swap(a[0], a[heap_size - 1]);
        siftDown(a, 0, heap_size - 1);
    }
}

/*

好的，我们在原来的例子基础上，加上**小顶堆（最小堆）堆排序**的操作，完整对比大顶堆和小顶堆的每轮变化。

---

## 原数组

```
[3,5,1,2,4]
```

---

## 1️⃣ 大顶堆（最大堆） → 升序排序

建堆后：

```
[5,4,1,2,3]
堆顶 = 最大值
```

每轮操作：

1. **第一轮**

   * 堆顶 = 5 → 放到末尾
   * 剩余堆 `[4,3,1,2]` → siftDown → `[4,3,1,2]`

2. **第二轮**

   * 堆顶 = 4 → 放到末尾
   * 剩余堆 `[3,2,1]` → siftDown → `[3,2,1]`

3. **第三轮**

   * 堆顶 = 3 → 放到末尾
   * 剩余堆 `[2,1]` → siftDown → `[2,1]`

4. **第四轮**

   * 堆顶 = 2 → 放到末尾
   * 剩余堆 `[1]` → 已排好

✅ 最终数组（升序）：

```
[1,2,3,4,5]
```

---

## 2️⃣ 小顶堆（最小堆） → 降序排序

建小顶堆后：

```
[1,2,3,5,4]
堆顶 = 最小值
```

每轮操作：

1. **第一轮**

   * 堆顶 = 1 → 放到末尾
   * 剩余堆 `[2,4,3,5]` → siftDown → `[2,4,3,5]`

2. **第二轮**

   * 堆顶 = 2 → 放到末尾
   * 剩余堆 `[3,4,5]` → siftDown → `[3,4,5]`

3. **第三轮**

   * 堆顶 = 3 → 放到末尾
   * 剩余堆 `[4,5]` → siftDown → `[4,5]`

4. **第四轮**

   * 堆顶 = 4 → 放到末尾
   * 剩余堆 `[5]` → 已排好

✅ 最终数组（降序）：

```
[5,4,3,2,1]
```

---

## 🔹 总结对比

| 堆类型 | 堆顶元素 | 排序方向 | 每轮放到末尾的值 |
| --- | ---- | ---- | -------- |
| 大顶堆 | 最大值  | 升序   | 最大值依次放末尾 |
| 小顶堆 | 最小值  | 降序   | 最小值依次放末尾 |

* 大顶堆 → 升序
* 小顶堆 → 降序
* 核心机制相同：**堆顶值被“摘出来”，放到数组末尾 → 下沉恢复剩余堆**

---

如果你希望，我可以画一个**图解版堆排序对比表**，显示大顶堆和小顶堆每轮 swap 与下沉过程，让升序和降序的形成过程直观可见。

你想看吗？


*/
