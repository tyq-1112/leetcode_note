#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        dfs(n , k , 1);
        return ans;
    }

    void dfs(int n , int k , int s){
        if(!k){
            ans.push_back(path);
            return ;
        }
        for(int i=s ; i<=n ; i++){
            path.push_back(i);
            dfs(n,k-1,i+1);
            path.pop_back();
        }
    }

};

/*

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]


*/