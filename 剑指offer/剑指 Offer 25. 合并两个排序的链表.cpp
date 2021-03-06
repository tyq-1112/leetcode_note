#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        while(l1 && l2){
            if(l1->val > l2->val) p->next = l2 , l2 = l2->next;
            else p->next = l1 , l1=l1->next;
            p = p->next;
        }

        if(l1) p->next = l1;
        else p->next = l2;
        return dummy->next;
    }
};



/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
限制：

0 <= 链表长度 <= 1000

*/
