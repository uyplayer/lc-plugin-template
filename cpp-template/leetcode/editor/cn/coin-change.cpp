/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30307
 *
 * [322] 零钱兑换
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
    // 这里的 memo 相当于 Python 里的字典
    vector<int> memo;

public:
    int coinChange(vector<int>& coins, int amount) {
        // 初始化备忘录，大小为 amount + 1，初始值设为 -2
        // -2 表示这个金额还没计算过
        // -1 表示这个金额计算过但无解
        memo.assign(amount + 1, -2);
        
        return dfs(coins, amount);
    }

    int dfs(vector<int>& coins, int n) {
        // 1. 基本情况
        if (n == 0) return 0;
        if (n < 0) return -1;

        // 2. 查备忘录，避免重复计算
        if (memo[n] != -2) return memo[n];

        int res = INT_MAX;
        for (int coin : coins) {
            // 递归计算子问题
            int sub = dfs(coins, n - coin);
            
            // 如果子问题有解
            if (sub != -1) {
                // sub + 1 可能会导致 INT_MAX 溢出，所以先判断一下
                res = min(res, 1 + sub);
            }
        }

        // 3. 把计算结果存入备忘录
        memo[n] = (res == INT_MAX) ? -1 : res;
        return memo[n];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

