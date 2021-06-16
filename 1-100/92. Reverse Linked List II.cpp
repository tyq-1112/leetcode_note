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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode *dummy = nullptr , *q = dummy;  //反转的链表

        ListNode *pre  = new ListNode(-520) ;
        pre->next = head ; head = pre ;  //在头节点前面加一个节点

        for(int i = 1 ; i < left ; i++)  pre = pre->next; //走到需要开始反转的前一个节点
        ListNode *p = pre->next;
        //cout<<pre->val<<" "<<p->val<<endl; // 1 2

        //反转
        ListNode *tp = p;
        for(int i = 0 ; i < right-left+1 ; i++){
            tp = p->next;
            p->next = q;
            q = p;
            p = tp;
            //cout<<p->val<<endl;
        }

        // //cout<<p->val<<endl; 此时p在需要反转的链表的后一个节点

        pre -> next = q;
        while(q->next) q = q->next;
        q->next = p;
        return head->next;
    }
};


/*

给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 

示例 1：


输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
示例 2：

输入：head = [5], left = 1, right = 1
输出：[5]
 

提示：

链表中节点数目为 n
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

进阶： 你可以使用一趟扫描完成反转吗？

*/