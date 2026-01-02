/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30305
 *
 * [86] 分隔链表
 */

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
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy_small = new ListNode(0);
        ListNode *small = dummy_small;

        ListNode *dummy_big = new ListNode(0);
        ListNode *big = dummy_big;

        ListNode *p = head;
        while (p != nullptr)
        {
            if (p->val < x)
            {
                small->next = p;
                small = small->next;
            }
            else
            {
                big->next = p;
                big = big->next;
            }
            // 当前p节点 已经移动到 两个指针之一里面，所以先断开它的next；
            ListNode *temp = p->next;
            p->next = nullptr; // 防止原链表残留
            p = temp;
        }

        small->next = dummy_big->next;
        return dummy_small->next;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */
