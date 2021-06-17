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
    int n ;
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //中序：左根右
        //后序：左右根
        //可以发现后序遍历的最后一个节点就是根，然后在中序遍历确定左子树和右子树
        int n = inorder.size();
        for(int i = 0 ; i < n ; i++) mp[inorder[i]] = i;
        return build(inorder,postorder,0,n-1,0,n-1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder , int il , int ir , int pl , int pr){
        if(il > ir || pl > pr) return NULL;
        TreeNode* root = new TreeNode(postorder[pr]);  //后序遍历最后一个点就是根节点
        int pos = mp[postorder[pr]];    //根在中序遍历中的pos;
        int lsize = pos-il ;   //左子树的个数
        root->left = build(inorder , postorder , il , pos-1 , pl , pl+lsize-1);
        root->right = build(inorder, postorder , pos+1 , ir , pl+lsize , pr-1);
        return root;
    }
};



/*

根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

*/