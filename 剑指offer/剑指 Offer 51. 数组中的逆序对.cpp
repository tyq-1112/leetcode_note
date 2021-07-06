#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
    
public:
    const static int N = 5e4+4;
    typedef long long ll;
    ll d[N] , n , ans;

    static int lowbit(int p){
        return p&-p;
    }

    void add(int p){
        while(p<=n){
            d[p]+=1;
            p+=lowbit(p);
        }
    }
    ll sum(int p){
        ll res = 0;
        while(p>0){
            res+=d[p];
            p-=lowbit(p);
        }
        return res;
    }

    int reversePairs(vector<int>& nums) {
        n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        //离散化
        for (int& num: nums) {
            num = lower_bound(temp.begin(), temp.end(), num) - temp.begin() + 1;
        }

        for(int i=nums.size()-1;i>=0;i--){
            ans+=sum(nums[i]-1);
            add(nums[i]);
        }
        return ans;
    }
};

/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5
 

限制：

0 <= 数组长度 <= 50000


*/