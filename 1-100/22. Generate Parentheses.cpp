#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:

    int len ;
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        len = n;
        dfs(0 , 0 ,  "");
        return ans;
    }

    void dfs(int left , int right , string s){
        
        if(left < right || s.size() > len*2) return ;  //保证左括号要大于右括号
        
        if(left == len && right == len && s.size() == len*2){   //满足条件
            ans.push_back(s);
            return ;
        }
        
        dfs(left + 1 , right , s+"(");  // 放左括号
        dfs(left , right+1, s+")");     //放右括号
    }
};


int main()
{
    Solution solution;
    auto t = solution.generateParenthesis(3);
    for(auto tt : t) cout << tt << " ";
    return 0;
}

/*

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]
 

提示：

1 <= n <= 8


*/