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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);


        while(q.size()){
            TreeNode *now = q.front() ; q.pop();
            ans.push_back(now->val);
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
        }

        return ans;
    }
};


/*
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]
 

提示：

节点总数 <= 1000


*/
