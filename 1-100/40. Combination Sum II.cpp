#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates , 0 , target);
        return ans;
    }

    void dfs(vector<int>& candidates , int u , int target){
        if(target == 0){
            ans.push_back(path);
            return ;
        }
        if(u == candidates.size()) return ;

        int k = u+1; // 有多少个
        while(k<candidates.size() && candidates[k] == candidates[u]) k++;
        int cnt = k-u;

        for(int i = 0 ; candidates[u]*i <= target && i<=cnt ; i++){
            dfs(candidates , k , target-candidates[u]*i);
            path.push_back(candidates[u]);
        }

        for(int i = 0 ; candidates[u]*i <= target && i<=cnt ; i++) path.pop_back();
    }
};


int main()
{
    Solution solution;
    return 0;
}

/*

给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

*/