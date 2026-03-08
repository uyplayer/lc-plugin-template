/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30400
 *
 * [78] 子集
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;

    vector<int> track;

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int> &nums, int start)
    {

        res.push_back(track);
        // 如果 i= 0 开始的话  会出现这种的 [2 ,3,1 ] 情况，所以这里每次开始 i = start
        for (int i = start; i < nums.size(); i++)
        {

            track.push_back(nums[i]);

            backtrack(nums, i + 1);

            track.pop_back();
        }
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
