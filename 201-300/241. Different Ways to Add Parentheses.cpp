#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    for(int i = 0; i < input.size(); ++i){
        char c = input[i];
        if(c == '+'|| c == '-' || c == '*'){//递归划分
            auto res1 = diffWaysToCompute(input.substr(0, i));
            auto res2 = diffWaysToCompute(input.substr(i+1));
            for(auto r1 : res1){//计算结果
                for(auto r2 : res2){
                    if(c == '+'){
                        res.push_back(r1 + r2);
                    } else if(c == '-'){
                        res.push_back(r1 - r2);
                    } else if(c == '*'){
                        res.push_back(r1 * r2);
                    }
                }
            }
        }
    }
    if(res.empty()){//纯数字，input中没符号
        res.push_back(stoi(input));
    }   
    return res;
}
};




/*
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

示例 1:

输入: "2-1-1"
输出: [0, 2]
解释: 
((2-1)-1) = 0 
(2-(1-1)) = 2
示例 2:

输入: "2*3-4*5"
输出: [-34, -14, -10, -10, 10]
解释: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10


*/
