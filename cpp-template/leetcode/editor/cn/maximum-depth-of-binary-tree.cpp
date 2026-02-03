/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30307
 *
 * [104] 二叉树的最大深度
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int res = 0;
     int depth = 0;
    int maxDepth(TreeNode* root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root){
        if (root == nullptr) {
            return;
        }
        depth++;
        if (root->left == nullptr && root->right == nullptr) {
            res = std::max(res, depth);
        }
        traverse(root->left);
        traverse(root->right);

        depth--;
         
        
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

