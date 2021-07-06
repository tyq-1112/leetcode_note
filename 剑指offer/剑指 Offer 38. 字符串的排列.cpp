#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int vis[10];
    int n ;
    string res,ss;
    set<string> ans;

    void dfs(int s){
        if(s==n){
            ans.insert(res);
            return ;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i] = 1;
                res.push_back(ss[i]);
                dfs(s+1);
                vis[i] = 0;
                res.pop_back();
            }
        }
    }

    vector<string> permutation(string s) {
        n = s.size();
        ss = s;
        dfs(0);
        vector<string> gg;
        for(auto t: ans){
            gg.push_back(t);
        }
        return gg;
    }
};

/*
输入一个字符串，打印出该字符串中字符的所有排列。


你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。


示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8

*/