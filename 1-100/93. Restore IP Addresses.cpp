#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<string> ans;

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if(n == 0 || n < 4 || n > 12) return ans;
        dfs(s , 0 , 0 ,"");
        return ans;
    }

    void dfs(string s , int u , int k , string res){
        if(u == s.size()){
            if(k==4) {
                res.pop_back();
                ans.push_back(res);
            }
            return ;
        }
        if(k == 4) return ;
        for(int i = u , t = 0; i <s.size() ; i++){
            if(i > u && s[u] == '0') break; //有前导0;
            t = t*10+s[i]-'0';
            if(t<=255) dfs(s,i+1,k+1,res+to_string(t)+'.');
            else break;
        }
    }
};



/*

给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。

有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

 

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

提示：

0 <= s.length <= 3000
s 仅由数字组成

*/