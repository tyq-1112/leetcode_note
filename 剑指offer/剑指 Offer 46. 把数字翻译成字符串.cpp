#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int len = str.size();

        int f[len+1];
        memset(f , 0 , sizeof f);
        f[0] = f[1] = 1;

        // 1 1 2 2
        // 1 2 3 5 
        for(int i = 1 ; i < len ; i++){
            int s = (str[i-1] - '0') * 10 + str[i] - '0';
            if(s>25 || str[i-1] == '0') f[i] = f[i-1];
            else {
                if(i>=2) f[i] = f[i-1] + f[i-2];
                else f[i] = f[i-1]+1;
            }
        }

        return f[len-1];
    }
};


/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 

提示：

0 <= num < 231


*/