/*
 * @lc app=leetcode.cn id=773 lang=cpp
 * @lcpr version=30400
 *
 * [773] 滑动谜题
 */

#include <iostream>
#include <string_view>
#include <unordered_set>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        // 将 2x3 的数组转化成字符串作为 BFS 的起点
        string start = "";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                start = start + to_string(board[i][j]);
            }
        }

        // ****** BFS 算法框架开始 ******
        queue<string> q;
        unordered_set<string> visited;
        // 从起点开始 BFS 搜索
        q.push(start);
        visited.insert(start);

        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                // 判断是否达到目标局面
                if (target == cur) {
                    return step;
                }
                // 将数字 0 和相邻的数字交换位置
                for (string neighborBoard : getNeighbors(cur)) {
                    // 防止走回头路
                    if (!visited.count(neighborBoard)) {
                        q.push(neighborBoard);
                        visited.insert(neighborBoard);
                    }
                }
            }
            step++;
        }
        // ****** BFS 算法框架结束 ******
        return -1;
    }

    vector<string> getNeighbors(string board) {
        // 记录一维字符串的相邻索引
        vector<vector<int>> mapping = {
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {4, 2}
        };

        int idx = board.find('0');
        vector<string> neighbors;
        for (int adj : mapping[idx]) {
            string new_board = swap(board, idx, adj);
            neighbors.push_back(new_board);
        }
        return neighbors;
    }

    string swap(string board, int i, int j) {
        char temp = board[i];
        board[i] = board[j];
        board[j] = temp;
        return board;
    }
 
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [[1,2,3],[4,0,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[5,4,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,1,2],[5,0,3]]\n
// @lcpr case=end

 */

