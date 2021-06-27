#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    static const int M = 5e6+6;
    bool vis[M];
    int countPrimes(int n) {
        vector<int> prime;
        for(int i = 2 ; i<n ; i++){
            if(!vis[i]) prime.push_back(i);
            for(int j = 0 ; prime[j]<=n/i ; j++){
                vis[prime[j]*i] = true;
                if(i % prime[j] == 0) break;
            }
        }

        return prime.size();
    }
};


/*
统计所有小于非负整数 n 的质数的数量。

 

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0
 

提示：

0 <= n <= 5 * 106

*/