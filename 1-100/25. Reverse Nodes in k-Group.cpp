#include <bits/stdc++.h>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto  dummy = new ListNode(-1);
        dummy->next = head;
        for(auto p = dummy ; ;){
            auto q = p;
            for(int i = 0 ; i < k && q ; i++) q = q->next;   
            if(!q) break;  //看看后面是否有k个
            
            auto a = p->next , b = a->next;
            for(int i = 0 ; i< k-1 ; i++){
                auto c = b->next;    //内部翻转
                b -> next = a;
                a = b , b = c;
            }
            auto c = p->next;
            p->next = a;
            c->next = b;
            p = c;
        }
        return dummy->next;
    }
};


int main()
{
    Solution solution;
    return 0;
}

/*

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 

示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例 2：


输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
示例 3：

输入：head = [1,2,3,4,5], k = 1
输出：[1,2,3,4,5]
示例 4：

输入：head = [1], k = 1
输出：[1]
提示：

列表中节点的数量在范围 sz 内
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz



*/