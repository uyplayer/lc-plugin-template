/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30307
 *
 * [543] 二叉树的直径
 */

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
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return maxDiameter;
    }
    void traverse(TreeNode* root){
        if(root == nullptr){
            return;
        }
        auto left = maxDepth(root->left);
        auto right = maxDepth(root->right);
        int myDiameter = left + right;
        maxDiameter = max(maxDiameter, myDiameter);
        
        traverse(root->left);
        traverse(root->right);
    }
     int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return 1 + max(leftMax, rightMax);
    }
};
// @lc code=end


class Solution {
public:
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxDiameter;
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);

        int myDiameter = leftMax + rightMax;
        maxDiameter = max(maxDiameter, myDiameter);

        return 1 + max(leftMax, rightMax);    
    }

};

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

