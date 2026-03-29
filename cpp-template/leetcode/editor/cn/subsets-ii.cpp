/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30401
 *
 * [90] 子集 II
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> result;
  deque<int> track;
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {

    // 排序就是相同元素方便跳过
    sort(nums.begin(), nums.end());

    backtrack(nums, 0);
    return result;
  }

  void backtrack(vector<int> &nums, int start) {
    result.push_back(vector<int>(track.begin(), track.end()));

    for (int i = start; i < nums.size(); i++) {
      // 上面做了排序
      if (i > start && nums[i] == nums[i - 1]) {
        continue;
      }

      track.push_back(nums[i]);
      backtrack(nums, i + 1);
      track.pop_back();
    }
  }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}

/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
