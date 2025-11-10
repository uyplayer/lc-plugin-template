## 排序算法按是否基于元素比较分类

### 比较排序（Comparison-based Sorting）


这些算法通过两两比较元素来决定顺序，平均时间复杂度通常不会优于 `O(n log n)`。

-   冒泡排序（`bubble-sort.cpp`）
-   插入排序（`insertion-sort.cpp`）
-   选择排序（`select-sort.cpp`）
-   希尔排序（`shell-sort.cpp`）
-   堆排序（`heap-sort.cpp`）
-   归并排序（`merge-sort.cpp`）
-   快速排序（`quick-sort.cpp`）

### 非比较排序（Non-comparison Sorting）

利用元素的取值特征或桶/计数结构，不依赖直接比较，因此在特定场景可达到线性时间复杂度。

-   桶排序（`bucket-sort.cpp`）
-   计数排序（`counting-sort.cpp`）
-   基数排序（`radix-sort.cpp`）