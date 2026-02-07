/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30307
 *
 * [509] 斐波那契数
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
    int fib(int n) {
        vector<int>    memo(n + 1, -1); 
        return dp(memo,n);
    }
    // 自顶上下的解法
    int dp(vector<int>& memo,int n){
        if(n<=1){
            return n;
        }
        if(memo[n]!=-1){
            return memo[n];

        }
        memo[n]=dp(memo,n-1)+dp(memo,n-2);
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
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

