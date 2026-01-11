/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=30306
 *
 * [26] 删除有序数组中的重复项
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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                // 没有重复的话迁移数组元素，这能slow向前走
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
 
        return slow + 1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */

