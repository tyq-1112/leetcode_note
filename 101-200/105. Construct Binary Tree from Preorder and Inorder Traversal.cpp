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
    unordered_map<int,int> mp;
    int n;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //前序：根左右
        //中序：左根右
        //可以得知前序的第一个节点在中序遍历的idx ， idx左边的是左子树，右边的是右子树
        n = preorder.size();
        for(int i = 0 ; i < n ; i++) mp[inorder[i]] = i;   //直接得到节点在中序所对应的idx
        return build(preorder,inorder,0,n-1,0,n-1); 
    }

    TreeNode * build(vector<int>& preorder , vector<int>&inorder , int pl , int pr , int il , int lr){
        if(pl > pr || il > lr) return NULL;
        TreeNode* root = new TreeNode(preorder[pl]);  //先序的第一个节点就是根 
        int pos = mp[preorder[pl]];            //第一个节点在中序对应的位置
        int lsize = pos-il;
        root->left = build(preorder,inorder,pl+1,pl+lsize,il,pos-1);
        root->right = build(preorder,inorder,lsize+pl+1,pr,pos+1,lr);
        return root;
    }
};



/*

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7



*/