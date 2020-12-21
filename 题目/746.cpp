#include <vector>

using namespace std;



// 动态规划
// dp[i]表示“爬到”第i个的最低花费
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0x3f3f3f3f);
        
        dp[0] = dp[1] = 0;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};


// 滚动数组优化DP算法的空间复杂度
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int d1 = 0, d2 = 0;
        for (int i = 2; i < cost.size() + 1; ++i) {
            int temp = d2;
            d2 = d1;
            d1 = min(d1 + cost[i-1], temp + cost[i-2]);
        }
        return d1;
    }
};