/*
 * @lc app=leetcode.cn id=144 lang=cpp
 * @lcpr version=30307
 *
 * [144] 二叉树的前序遍历
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
    std::vector<int> pre;
    std::vector<int> mid;
    std::vector<int> back;
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return pre;
    }
    void traverse(TreeNode* root){

        if(root==nullptr){
            return;
        }
        pre.push_back(root->val);
        traverse(root->left);
        mid.push_back(root->val);
        traverse(root->right);
        back.push_back(root->val);

    }

};
// @lc code=end


class Solution1 {
public:
    std::vector<int> pre;
   
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return pre;
        }
        auto result = vector<int>{root->val};
        auto left = preorderTraversal(root->left);
        result->insert(result->end(), left.begin(), left.end()); 
        auto right = preorderTraversal(root->left);
        result->insert(result->end(), right.begin(), right.end()); 
        return result;
    }
     

};
int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

