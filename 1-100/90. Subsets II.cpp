#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());  //把相同的数放一起
        dfs(nums,0);
        return ans;
    }

    void dfs(vector<int>& nums , int u){
        if(u == nums.size()) {
            ans.push_back(path);
            return ;
        }

        int k = u+1; //相同数的个数
        while(k<nums.size() &&  nums[k] == nums[u]) k++;

        //枚举放一个还是放两个...
        for(int i = 0 ; i <= k-u ; i++){
            dfs(nums,k);
            path.push_back(nums[u]);
        }
        //恢复现场
        for(int i = 0 ; i <= k-u ; i++){
            path.pop_back();
        }
    }
};


/*

给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10

*/