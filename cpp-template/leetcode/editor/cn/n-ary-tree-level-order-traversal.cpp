/*
 * @lc app=leetcode.cn id=429 lang=cpp
 * @lcpr version=30202
 *
 * [429] N 叉树的层序遍历
 */

#include <queue>
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

// class Solution
// {
// public:
//     vector<vector<int>> levelOrder(Node *root)
//     {
//         vector<vector<int>> result;
//         if (root == nullptr)
//         {
//             return result;
//         }

//         queue<Node *> my_queue;
//         my_queue.push(root);
//         while (!my_queue.empty())
//         {

//             vector<int> level;
//             auto size = my_queue.size();
//             for (int i = 0; i < size; i++)
//             {
//                 Node *node = my_queue.front();
//                 my_queue.pop();
//                 level.push_back(node->val);

//                 for (auto child : node->children)
//                 {
//                     my_queue.push(child);
//                 }
//             }
//             result.push_back(level);
//         }
//         return result;
//     }
// };

class Solution
{
public:
    vector<vector<int>> result;

    vector<vector<int>> levelOrder(Node *root)
    {
        dfs(root, 0);
        return result;
    }

    void dfs(Node *node, int depth)
    {
        if (node == nullptr)
            return;

        // 确保 result 有足够的层数
        if (depth == result.size())
        {
            result.push_back({});
        }

        // 把当前节点的值放到对应层
        result[depth].push_back(node->val);

        // 递归处理孩子节点，深度+1
        for (Node *child : node->children)
        {
            dfs(child, depth + 1);
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
// [1,null,3,2,4,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
// @lcpr case=end

 */
