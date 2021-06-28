#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    static const int M = 10;
    bool vis[M];
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k , n , 1);
        return ans;
    }

    void dfs(int k , int n , int s){
        
        if(k == 0 && n == 0) {
            ans.push_back(path);
            return ;
        }
        if(n<s || s>9) return ;
        dfs(k,n , s+1);
        path.push_back(s);
        dfs(k-1 , n-s , s+1);
        path.pop_back();
       
    }
};



/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

*/
