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
private:
    map<int, int> mp;
public:
    TreeNode* build(vector<int>& pre , vector<int> & in , int preL , int preR  , int inL , int inR){
	if(preL > preR || inL > inR) return NULL;
	TreeNode* root = new TreeNode(pre[preL]);  //先序的第一个节点就是根 
	int index = mp[pre[preL]];  //找到根在中序的位置 
	int left_size = index - inL; 
	root->left = build(pre ,in, preL+1 , preL+left_size , inL , index-1);
	root->right = build(pre ,in, preL+left_size+1 , preR , index+1 , inR);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    for(int i=0;i<n;i++) mp[inorder[i]] = i;
    return build(preorder,inorder,0,n-1,0,n-1); 
}
};


/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
 

限制：

0 <= 节点个数 <= 5000


*/
