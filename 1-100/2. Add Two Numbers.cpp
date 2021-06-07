#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1 , *q = l2 ;
        ListNode *head = nullptr , *tail = nullptr ;
        int pre = 0 ;   //用来进位

        for( ; p || q ; ){
            int a = 0 , b = 0 ;
            if(p) a = p->val;   //如果到了null，就为0 ， 否则等于该val
            if(q) b = q->val;
            int sum = pre + a + b ;
            if(!head){
                head = tail = new ListNode(sum % 10);
            }else{
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            pre = sum/10;
            if(p)p = p->next;
            if(q)q = q->next;
        }
        if(pre) tail->next = new ListNode(pre);  //最后一次出现了进位
        return head;
    }
};

int main(){
    Solution solution;
    ListNode *l1 = nullptr , * l2 = nullptr;
    l1 = new ListNode(2);
    l2 = new ListNode(8);
    auto ans = solution.addTwoNumbers(l1,l2);
    cout << ans->val <<" "<< ans->next->val <<endl;
    return 0;
}


/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]

示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]

每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零
*/