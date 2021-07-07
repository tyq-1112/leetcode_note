#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n) , ans(n);
        if(n<1) return ans;
        pre[0] = a[0];
        for(int i = 1 ; i < n ; i++)  pre[i] = pre[i-1] * a[i];

        int sum = a[n-1];
        ans[n-1] = pre[n-2];

        for(int i = n-2 ; i>0 ; i--){
            ans[i] = pre[i-1] * sum;
            sum = sum*a[i];
        }
        ans[0] = sum;
        return ans;
    }
};


/*
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

 

示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
 

提示：

所有元素乘积之和不会溢出 32 位整数
a.length <= 100000


*/