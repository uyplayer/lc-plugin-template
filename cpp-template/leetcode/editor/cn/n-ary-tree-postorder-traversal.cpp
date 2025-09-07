/*
 * @lc app=leetcode.cn id=590 lang=cpp
 * @lcpr version=30202
 *
 * [590] N 叉树的后序遍历
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> result;
    vector<int> postorder(Node* root) {
        if (root == nullptr) {
            return result;
        }
        traverse(root);
        return result;
        
    }
    void traverse(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        
        for (auto child : root->children)
        {
            traverse(child);
        }
        result.push_back(root->val);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,null,3,2,4,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
// @lcpr case=end

 */

