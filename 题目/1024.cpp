#include <iostream>
#include <vector>

using namespace std;

// 硬解：找end >= T的clip，找不到就返回-1，找到了就在其中找start最小的，
//      更新T=minStart，继续找下一片。
// 时间上太慢
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> starts, ends;
        int minStart = 999;
        int cnt = 0;
        while (1){
            int flag = 0;
            for (auto it = clips.begin(); it < clips.end(); it++){
                if ((*it)[1] >= T && (*it)[0] != minStart){
                    flag = 1;
                    minStart = min(minStart, (*it)[0]);
                }
            }
            if (flag == 0)
                return -1;
            cnt++;
            if (minStart == 0)
                break;
            T = minStart;
        }
        return cnt;
    }
};


// 动态规划
// dp[i]表示覆盖区间[0, i)最少需要多少个子区间；
// 转移方程为：dp[i] = min(dp[i], dp[aj]+1), 
//            aj为所有满足 aj < i <= bj的, 其中aj, bj分别为start, end
// 直观的解释：对于dp[i]，要找到能覆盖[0, i)的最少，先找到能覆盖[0, i)后面一部分的所有子区间，
//            即满足aj < i <= bj的，如果分别用这些子区间覆盖后面一部分，则需要的最优子区间数为dp[aj] + 1，
//            从中选择最小的就得到了最优dp[i]；
// 如果没有更新到dp[T]，表示无法覆盖[0, i)；
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T+1, 1024);
        dp[0] = 0;
        for (int i = 1; i <= T; i++){
            for (auto& it : clips){
                if (it[0] < i && it[1] >= i)
                    dp[i] = min(dp[i], dp[it[0]] + 1);
            }
        }
        return dp[T] == 1024 ? -1 : dp[T];
    }
};


// 贪心
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> maxn(T);
        int cnt = 0, curEnd = 0, nextEnd = 0;
        // maxn[i]记录左端点为i的，最大的右端点值
        for (auto& it : clips){
            if (it[0] < T) // 小心越界
                maxn[it[0]] = max(maxn[it[0]], it[1]);
        }
        // curEnd 记录目前在循环内的(最优)右端点
        // nextEnd 记录下一个能最远跨到的右端点
        // 如果指针 i 在遇到curEnd之前, 没法将nextEnd更新到更远，表示断链
        for (int i = 0; i < T; i++){
            nextEnd = max(nextEnd, maxn[i]);
            if (i == nextEnd)
                return -1;
            if (i == curEnd){
                cnt++;
                curEnd = nextEnd;
            }
        }
        return cnt;
    }
};


