/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30306
 *
 * [344] 反转字符串
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
    void reverseString(vector<char>& s) {
        
        int left = 0;
        int right = s.size();

        while(left < right){
            char temp = s[left];
            s[left] = s[right-1];
            s[right-1] = temp;
            left++;
            right--;
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
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */

