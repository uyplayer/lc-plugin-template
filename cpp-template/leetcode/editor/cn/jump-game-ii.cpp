/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30402
 *
 * [45] 跳跃游戏 II
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> memo;
  int jump(vector<int> &nums) {
    int n = nums.size();
    memo = vector<int>(n, n);
    return dp(nums, 0);
  }
  int dp(vector<int> &nums, int p) {
    int n = nums.size();

    if (p >= n - 1) {

      return 0;
    }

    if (memo[p] != n) {
      return memo[p];
    }
    int steps = nums[p];

    for (int i = 1; i <= steps; i++) {

      int subProblem = dp(nums, p + i);
      memo[p] = min(memo[p], subProblem + 1);
    }
    return memo[p];
  }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */
