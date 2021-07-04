#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll ;
    static const int mod = 1e9+7;
    int cuttingRope(int n) {
        if(n<3) return 1;
        if(n==3) return 2;
        if(n%3 == 0) {
            return pow(3,n/3);
        }else if(n%3 == 1){
            ll ans = pow(3,(n-4)/3);
            return ans*4%mod;
        }else{
            ll ans = pow(3 , n/3);
            return ans*2%mod;
        }
    }

    ll pow(ll a, ll p){
        ll ans = 1;
        while(p){
            if(p&1) ans = ans*a%mod;
            a = a*a %mod;
            p = p>>1;
        }
        return ans%mod;
    }
};



/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
 

提示：

2 <= n <= 1000


*/
