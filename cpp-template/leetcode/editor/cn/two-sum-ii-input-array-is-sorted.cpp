/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=30306
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
               
                return vector<int>{left + 1, right + 1};
            } else if (sum < target) {
               
                left++;
            } else if (sum > target) {
      
                right--;
            }
        }
        return vector<int>{-1, -1};        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */

