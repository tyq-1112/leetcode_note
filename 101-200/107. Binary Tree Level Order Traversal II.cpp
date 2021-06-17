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
    vector<vector<int>> ans;
    

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root);
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void dfs(TreeNode *root){
        if(root == nullptr) return ;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            vector<int> path;
            int len = q.size();
            for(int i = 0 ; i < len ; i++){
                TreeNode *u = q.front() ; q.pop();
                path.push_back(u->val);
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            ans.push_back(path);
        }
    }
};



/*

给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层序遍历为：

[
  [15,7],
  [9,20],
  [3]
]


*/