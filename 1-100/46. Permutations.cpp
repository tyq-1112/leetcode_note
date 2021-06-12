#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n ; 
    vector<vector<int>> ans ;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        bool st[n+1];
        memset(st,false,sizeof st);
        dfs(0 , nums , st);
        return ans;
    }

    void dfs(int u , vector<int> nums , bool st[]){
        if(u==n){
            ans.push_back(path);
            return ;
        }
        for(int i = 0 ; i < n ; i++){
            if(!st[i]){
                st[i] = true;
                path.push_back(nums[i]);
                dfs(u+1 , nums , st);
                st[i] = false;
                path.pop_back();
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

给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
 

提示：

1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同

*/