#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // n = 4 , k = 14;
    /**
     * 首先我们将所有排位按首位分组
     * 1.1+(2，3，4的全排列)
     * 2.2+(1，3，4的全排列)
     * 3.3+(1，2，4的全排列)
     * 4.4+(1，2，3的全排列)
     * 接下来确定第k=14个排列在哪一组中，每组的排列数是6个
     * 所有首位已经可以确定是3
     * 然后将第3组的排列继续分组
    */
    string getPermutation(int n, int k) {
        string res ;
        vector<bool> st(n);
        //从高位到低位依次考虑每一位
        
        for(int i = 0 ; i < n ; i++){
            int f = 1;
            for(int j=1 ; j<n-i ; j++) f = f*j; // 阶乘
            
            //从小到大枚举未使用过的数
            for(int j=0 ; j<n;j++){
                if(!st[j]){
                    if(k<=f) {
                        res+=to_string(j+1);
                        st[j] = true;
                        break;
                    }
                    k-=f; 
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    cout << solution.getPermutation(3,3) << endl;
    return 0;
}

/*

给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

 

示例 1：

输入：n = 3, k = 3
输出："213"
示例 2：

输入：n = 4, k = 9
输出："2314"
示例 3：

输入：n = 3, k = 1
输出："123"
 

提示：

1 <= n <= 9
1 <= k <= n!


*/