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

    struct cmp{
        bool operator () (ListNode *a , ListNode *b){
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //类似与合并两个链表的思路，可以用一个小根堆维护最小值，降低时间复杂度
        priority_queue< ListNode* , vector<ListNode*> , cmp > q;
        //把每个链表的根放进队列
        for(auto list : lists) {
            if(list) q.push(list);
        }
        
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        
        while(q.size()){
            auto t = q.top();
            q.pop();
            tail = tail->next = t;
            if(t->next) q.push(t->next);
        }
        return head->next;
    }
};


int main()
{
    Solution solution;
    
    return 0;
}

/*

给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：

输入：lists = []
输出：[]
示例 3：

输入：lists = [[]]
输出：[]
 

提示：

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4
*/