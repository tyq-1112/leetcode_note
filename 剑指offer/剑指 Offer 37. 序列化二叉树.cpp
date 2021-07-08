#cinlude<bits/stdc++.h>

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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        // 如果根为空
        if(root == nullptr) {
            return res;
        } 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* demo = q.front();
            q.pop();
            if(demo != nullptr) {
                res += to_string(demo -> val) + ",";
                q.push(demo -> left);
                q.push(demo -> right);
            } else {
                res += "null,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") {
            return nullptr;
        }
        vector<string> vals;
        // 分割字符串
        string s;
        for(int i = 0; i < data.size(); i ++) {
            if(data[i] == ',') {
                vals.push_back(s);
                s = "";
            } else {
                s += data[i];
            }
        }
        
        TreeNode* root = new TreeNode(atoi(vals[0].c_str()));
        queue<TreeNode*> q;
        q.push(root);

        int i = 0;
        while(!q.empty()) {
            TreeNode* demo = q.front();
            q.pop();
            // 有左节点
            if(vals[i * 2 + 1] != "null") {
                demo -> left = new TreeNode(atoi(vals[i * 2 + 1].c_str()));
                q.push(demo -> left);
            }
            // 有右节点
            if(vals[i * 2 + 2] != "null") {
                demo -> right = new TreeNode(atoi(vals[i * 2 + 2].c_str()));
                q.push(demo -> right);
            }
            i ++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


/*
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

示例：


输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]

*/