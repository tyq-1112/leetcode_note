#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int len ; 
    //返回第一次出现的值
    int left(vector<int>& nums , int target){
        int l = 0 , r = len-1 , mid;
        while(l<r){
            mid = l+r>>1;
            if(nums[mid] >= target) r = mid;
            else l = mid+1; 
        }
        if(nums[l] != target) return -1; // 如果数组不存在这个target
        return l;
    }

    //返回最后一次出现的值
    int right(vector<int>& nums , int target){
        int l = 0 , r = len-1 , mid;
        while(l<r){
            mid = l+r+1>>1;
            if(nums[mid] <= target) l = mid;
            else r = mid-1; 
        }
        return l;
    }

    int search(vector<int>& nums, int target) {
        if(!nums.size()) return 0;
        len = nums.size();
        int l = left(nums,target);
        if(l == -1 ) return 0;
        int r = right(nums,target);
        return r-l+1;
    }
};

/*
统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

限制：

0 <= 数组长度 <= 50000


*/