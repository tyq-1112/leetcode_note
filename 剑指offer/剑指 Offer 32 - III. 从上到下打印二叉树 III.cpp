#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        int row = 0;
        if(root == NULL) return res;
        q.push(root);

        while(q.size()){
            int s = q.size();
            vector<int> path;
            for(int i = 0 ; i < s ; i++){
                TreeNode *now = q.front();
                q.pop();
                path.push_back(now->val);
                if(now->left) q.push(now->left);
                if(now->right) q.push(now->right);
            }
            if(row) reverse(path.begin() , path.end());
            row = row^1;
            res.push_back(path);
        }
        return res;
    }
};


/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
 

提示：

节点总数 <= 1000

*/
