#include <bits/stdc++.h>

using namespace std;

#define fx first
#define se second

class Solution {
public:
    typedef pair<int,int> PII;
    vector<vector<int>> ans;

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return intervals;
        vector<PII> temp;
        for(auto x : intervals){
            temp.push_back({x[0],x[1]});
        }
        sort(temp.begin() , temp.end());

        int l = temp[0].fx , r = temp[0].se;
        for(int i = 1 ; i < intervals.size() ; i++){
            if(temp[i].fx > r) {
                ans.push_back({l,r});
                l = temp[i].fx;
                r = temp[i].se;
            }else{
                r = max(r , temp[i].se);
            }
        }
        ans.push_back({l,r});
        return ans;
    }
};

int main()
{
    Solution solution;
    return 0;
}

/*

以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。


示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。


提示：

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104


*/