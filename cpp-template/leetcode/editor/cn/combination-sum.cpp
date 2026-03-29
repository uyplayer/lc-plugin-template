/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30401
 *
 * [39] 组合总和
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> res;

  deque<int> track;

  int trackSum = 0;

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    backtrack(candidates, 0, target);
    return res;
  }

  void backtrack(vector<int> &nums, int start, int target) {

    if (trackSum == target) {
      res.push_back(vector<int>(track.begin(), track.end()));
      return;
    }
    if (trackSum > target) {
      return;
    }

    for (int i = start; i < nums.size(); i++) {
      trackSum += nums[i];
      track.push_back(nums[i]);
      backtrack(nums, i, target);
      trackSum -= nums[i];
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
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
