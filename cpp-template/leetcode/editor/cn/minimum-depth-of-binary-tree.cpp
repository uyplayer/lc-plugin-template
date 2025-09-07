/*
 * @lc app=leetcode.cn id=111 lang=cpp
 * @lcpr version=30202
 *
 * [111] 二叉树的最小深度
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
// class Solution
// {
// private:
//     int current = 0;
//     int mini_depth = INT_MAX;

// public:
//     int minDepth(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }
//         traverse(root);
//         return mini_depth;
//     }
//     void traverse(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return;
//         }

//         current++;
//         if(root->left == nullptr && root->right == nullptr){
//             mini_depth = min(mini_depth,current);
//         }
//         traverse(root->left);
//         traverse(root->right);
//         current--;
//     }
// };


class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }

            if (node->left) q.push({node->left, depth + 1});
            if (node->right) q.push({node->right, depth + 1});
        }

        return 0;  
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
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,null,3,null,4,null,5,null,6]\n
// @lcpr case=end

 */
