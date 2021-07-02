#include <bits/stdc++.h>

using namespace std;


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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        for (ListNode *p = head; p; p = p->next) n ++ ;
        if (n <= 1) return true;
        ListNode *a = head;
        for (int i = 0; i < (n + 1) / 2 - 1; i ++ ) a = a->next;
        ListNode *b = a->next;
        while (b)
        {
            ListNode *c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        b = head;
        ListNode *tail = a;
        bool res = true;
        for (int i = 0; i < n / 2; i ++ )
        {
            if (a->val != b->val)
            {
                res = false;
                break;
            }
            a = a->next;
            b = b->next;
        }
        a = tail, b = a->next;
        for (int i = 0; i < n / 2; i ++ )
        {
            ListNode *c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        tail->next = 0;
        return res;
    }
};



/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

*/
