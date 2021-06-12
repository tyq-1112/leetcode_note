#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> A , B ;
        int n = num1.size() , m = num2.size();
        for(int i = n-1 ; i>=0 ; i--) A.push_back(num1[i]-'0');
        for(int i = m-1 ; i>=0 ; i--) B.push_back(num2[i]-'0');

        vector<int> C(n+m);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                C[i+j] += A[i]*B[j];
            }
        }

        for(int i = 0 , t = 0 ; i < C.size() ; i++){
            t+=C[i];
            C[i] = t%10;
            t = t/10;
        }

        int k = C.size()-1;
        while(k>0 && !C[k]) k--;

        string res;
        while(k>=0) res += C[k--]+'0';
        return res;
    }
};



int main()
{
    Solution solution;
    cout << solution.multiply("123","456") << endl;
    return 0;
}

/*

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。




*/