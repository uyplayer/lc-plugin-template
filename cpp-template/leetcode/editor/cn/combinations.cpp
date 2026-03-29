/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30401
 *
 * [77] 组合
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
  vector<vector<int>> result;
  deque<int> path;
  vector<vector<int>> combine(int n, int k) {
    backtrack(1, n, k);

    return result;
  }

  void backtrack(int start, int n, int k) {

    if (path.size() == k) {
      result.push_back(vector<int>(path.begin(), path.end()));
      return;
    }

    for (int i = start; i <= n; i++) {
      path.push_back(i);
      backtrack(i + 1, n, k);
      path.pop_back();
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
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
