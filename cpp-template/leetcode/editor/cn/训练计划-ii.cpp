/*
 * @lc app=leetcode.cn id=LCR 140 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 140] 训练计划 II
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* trainingPlan(ListNode* head, int cnt) {
         int n = 0;
        ListNode* node = nullptr;

        for (node = head; node; node = node->next) {
            n++;
        }
        for (node = head; n > cnt; n--) {
            node = node->next;
        }
      
        return node;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [2,4,7,8]\n1\n
// @lcpr case=end

 */

