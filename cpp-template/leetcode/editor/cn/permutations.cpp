/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30400
 *
 * [46] 全排列
 */

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:


    std::vector<std::vector<int>> result;

    vector<vector<int>> permute(vector<int>& nums) {
        std::list<int> path;
        std::vector<bool> used(nums.size(), false);
        backtrack(nums,path,used);
        return result;
    }


    void backtrack(const std::vector<int>& nums, std::list<int>& track, std::vector<bool>& used){
            if(track.size() == nums.size()){
                result.push_back(std::vector<int>(track.begin(),track.end()));
                return;
            }

            for (int i = 0; i < nums.size(); i++) {
                if(used[i]){
                    continue;
                }
                used[i] = true;
                track.push_back(nums[i]);
                backtrack(nums,track,used);
                track.pop_back();
                used[i] = false;
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
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

