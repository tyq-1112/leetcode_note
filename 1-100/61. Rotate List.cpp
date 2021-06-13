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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0 ;
        ListNode *tail;
        for(auto p = head ; p ; p = p->next){
            n++;  //得到链表长度
            tail = p;
        }
        if(n == 0) return head;
        k = k % n;
        if(k == 0) return head;
        auto p = head;
        for(int i = 0 ; i<n-k-1 ; i++) p = p->next;
        tail->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};


int main()
{
    Solution solution;
    return 0;
}

/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

 

示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：


输入：head = [0,1,2], k = 4
输出：[2,0,1]
 

提示：

链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109



*/