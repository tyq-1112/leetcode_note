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
    

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root);
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

给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层序遍历结果：

[
  [3],
  [9,20],
  [15,7]
]


*/