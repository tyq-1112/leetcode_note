#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(root->val);

        while(q.size()){
            TreeNode* last = nullptr ;
            int len = q.size();
            for(int i = 0 ; i < len ; i++){
                auto x = q.front() ;
                q.pop();
                if(x->left) {
                    last = x->left;
                    q.push(last);
                }
                if(x->right) {
                    last = x->right;
                    q.push(last);
                }
            }
            if(last) ans.push_back(last->val);
        }
        return ans;
    }
};


/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

*/