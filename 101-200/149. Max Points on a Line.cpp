#cinlude<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        typedef long double LD;

        int res = 0;
        for (auto& p: points) {    //枚举每一个点作为定点
            int ss = 0, vs = 0;   // ss 表示与定点重合 ， vs表示与定点垂直，没斜率，单独算
            unordered_map<LD, int> cnt;   //哈希表存直线
            for (auto& q: points)       //其他点与定点构成的直线 ， 斜率相同就是同一条直线
                if (p == q) ss ++ ;
                else if (p[0] == q[0]) vs ++ ;
                else {
                    LD k = (LD)(q[1] - p[1]) / (q[0] - p[0]);
                    cnt[k] ++ ;
                }
            int c = vs;
            for (auto [k, t]: cnt) c = max(c, t);
            //答案就是每条直线上的点 + 重点 ，
            res = max(res, c + ss);
        }
        return res;
    }
};

/*

给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

示例 1:

输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
示例 2:

输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

*/