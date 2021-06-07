
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans(2,0);
        for(int i = 0 ; i < nums.size() ; ++i){
            int x = target - nums[i];
            if(mp.find(x) != mp.end()) {
                ans[1] = i ; 
                ans[0] = mp[x] ; 
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,7,11,15};
    auto t = solution.twoSum(nums,9);
    cout<<t[0]<<" "<<t[1]<<endl;
    return 0;
}

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target的那两个整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。


示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
只会存在一个有效答案
*/