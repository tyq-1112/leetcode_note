#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    struct Node {      //用一个tire树保存单词列表，剪枝
        int id ;   //单词在列表中的下标
        Node  *son[26];
        Node(){
            for(int i = 0 ; i<26 ; i++) son[i] = NULL;
            id = -1;
        }
    };
    Node *root ;
    int n , m ;
    unordered_set<int> res;   //记录存在的单词的id
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    void insert(string &word , int idx){    //单词插入tire树
        Node *p = root;
        for(char &x : word){
            int u = x-'a';
            if(!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->id = idx;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        n = board.size();
        m = board[0].size();
        for(int i = 0 ; i < words.size() ; i++) insert(words[i] , i);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int u = board[i][j] - 'a';
                if(root->son[u]) dfs(board , i , j , root->son[u]);
            }
        }

        vector<string> ans;
        for(auto x : res) ans.push_back(words[x]);
        return ans;

    }


    void dfs(vector<vector<char>> &board , int x , int y , Node *p){
        if(p->id != -1) res.insert(p->id);
        char t = board[x][y];
        board[x][y] = '.';
        for(int i = 0 ; i < 4 ; i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny] != '.'){
                int u = board[nx][ny] - 'a';
                if(p->son[u]) dfs(board , nx , ny , p->son[u]);
            }
        }
        board[x][y] = t;
        
    }
};



/*

给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

 

示例 1：


输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
输出：["eat","oath"]
示例 2：


输入：board = [["a","b"],["c","d"]], words = ["abcb"]
输出：[]
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] 是一个小写英文字母
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] 由小写英文字母组成
words 中的所有字符串互不相同

*/
