#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:

    typedef long long ll;
    ll res ;

    int countDigitOne(int n) {
        ll high = n/10 , low = 0 , cur = n%10 , dig = 1;
        while(high || cur){
            if(cur == 0) res+=high*dig;
            else if(cur == 1) res+=(high*dig + low + 1);
            else res+=(high+1)*dig;

            low += dig * cur;
            cur = high%10;
            high = high/10;
            dig = dig*10;
        }

        return res;
    }
};

/*
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

 

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6
 

限制：

1 <= n < 2^31



*/