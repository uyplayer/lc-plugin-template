
## 排序算法 


-   选择排序所面临的问题
-   拥有稳定性：冒泡排序
-   运用逆向思维：插入排序
-   突破 O(N^2)：希尔排序
-   妙用二叉树前序位置：快速排序
-   妙用二叉树后序位置：归并排序
-   二叉堆结构的运用：堆排序
-   全新的排序原理：计数排序
-   博采众长：桶排序
-   基数排序（Radix Sort）

### 排序算法的关键指标

-   **时间复杂度**：平均、最坏、最好三种情况决定了算法在不同输入下的理论上限。
-   **空间复杂度**：原地算法（如 `select-sort.cpp`）更节省内存，而 `merge-sort.cpp` 需要额外缓冲。
-   **稳定性**：是否保持相同键值元素的相对次序；`bubble-sort.cpp` 与 `insertion-sort.cpp` 是稳定代表。
-   **实现复杂度与适用场景**：`quick-sort.cpp` 对随机数据高效但需警惕退化，而 `counting-sort.cpp` 要求整数范围有限。



## 排序算法按是否基于元素比较分类

### 比较排序（Comparison-based Sorting）


这些算法通过两两比较元素来决定顺序，平均时间复杂度通常不会优于 `O(n log n)`。

-   选择排序（`select-sort.cpp`）
-   冒泡排序（`bubble-sort.cpp`）
-   插入排序（`insertion-sort.cpp`）
-   希尔排序（`shell-sort.cpp`）
-   快速排序（`quick-sort.cpp`）
-   归并排序（`merge-sort.cpp`）
-   堆排序（`heap-sort.cpp`）


### 非比较排序（Non-comparison Sorting）

利用元素的取值特征或桶/计数结构，不依赖直接比较，因此在特定场景可达到线性时间复杂度。

-   桶排序（`bucket-sort.cpp`）
-   计数排序（`counting-sort.cpp`）
-   基数排序（`radix-sort.cpp`）
