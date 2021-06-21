#cinlude<bits/stdc++.h>

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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *low = head , *fast = head;
        while(fast->next && fast->next->next) low = low->next , fast = fast->next->next;
        fast = low->next , low->next = nullptr;
        return mer(sortList(head) , sortList(fast));
    }

    ListNode * mer(ListNode *l1 , ListNode *l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        while(l1 && l2){
            auto &node  = l1->val < l2->val ? l1 : l2;
            p = p ->next = node;
            node = node->next;
        }
        p->next = l1?l1:l2;
        return dummy->next;
    }
};
/*

给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 

示例 1：


输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：


输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105

*/