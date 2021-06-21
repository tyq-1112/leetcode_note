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
    void reorderList(ListNode* head) {
        int n = 0;
        for(auto p = head ; p ; p = p ->next) n++;
        if(n<=2) return ;
        ListNode *half = head;
        for(int i = 0 ; i< n/2-1 ; i++) half = half->next;

        //cout<<half->val<<endl;
        ListNode *p = half->next;
        //cout<<p->val<<endl;
        half->next = nullptr;
        //head: 1 2 null
        //p: 3 4 5 null
        ListNode *ptr = new ListNode(-1);
        // ptr：5 4 3 null
        while(p){     //后面一半翻转
            half = p->next;
            p->next = ptr;
            ptr = p;
            p = half;
        }
        // while(ptr) {
        //     cout<<ptr->val<<endl;
        //     ptr= ptr->next;
        // }
        p = head->next;
        //p: 2
        //ptr:5 4 3 -1
        while(p || ptr->next){
            if(ptr){
                head = head->next = ptr;
                ptr = ptr->next;
            }
            if(p){
                head = head->next = p;
                p = p->next;
            }
        }
        head->next = nullptr;
    }
};
/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

*/