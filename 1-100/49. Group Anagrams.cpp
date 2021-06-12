#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i = 0 ; i < strs.size() ; i++){
            string s = strs[i];
            sort(s.begin() , s.end());
            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto t : mp){
            vector<string> res = t.second;
            ans.push_back(res);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    return 0;
}

/*

给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

*/