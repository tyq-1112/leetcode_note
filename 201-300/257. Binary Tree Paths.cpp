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

    vector<string> ans;
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root , "");
        return ans;
    }

    void dfs(TreeNode* root , string path){
        if(root == nullptr) return ;
        if(root->left == nullptr && root->right == nullptr){
            path+=to_string(root->val);
            ans.push_back(path);
            return ;
        }

        if(root->left) dfs(root->left , path+to_string(root->val) + "->");
        if(root->right) dfs(root->right , path+to_string(root->val) + "->");
        
    }
};




/*

给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3


*/
