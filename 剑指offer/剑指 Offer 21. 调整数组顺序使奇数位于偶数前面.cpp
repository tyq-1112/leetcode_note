#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size()<2) return nums;
        int k = nums.size() - 1 ;

        for(int i = 0 ; i < k ; i++){
            if(nums[i] % 2 == 1) continue;
            else{
                while(k>i && nums[k] %2 == 0) k--;
                swap(nums[i] , nums[k]);
            }
        }
        return nums;
    }
};



/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

 

示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
 

提示：

0 <= nums.length <= 50000
1 <= nums[i] <= 10000

*/
