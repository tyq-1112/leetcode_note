#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;
    int n ;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        n = nums.size();
        path = vector<int>(n);
        st = vector<bool>(n);
        dfs(nums , 0);
        return ans;
    }

    void dfs(vector<int> nums , int u){
        if(u == n) {
            ans.push_back(path);
            return ;
        }

        for(int i = 0 ; i < n ; i++){
            if(!st[i]){
                if(i && nums[i-1] == nums[i] && !st[i-1]) continue;
                st[i] = true;
                path[u] = nums[i];
                dfs(nums,u+1);
                st[i] = false;
            }
        }
    }
};

int main()
{
    Solution solution;
    return 0;
}

/*

给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10

*/