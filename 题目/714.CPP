#include <vector>

using namespace std;


// 动态规划
// dp[i][1/0] 表示第i天手上持有和未持有股票的最大收益
// 可以优化到两个int
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -prices[0], notHeld = 0;
        for (int i = 1; i < n; ++i) {
            notHeld = max(notHeld, hold + prices[i] - fee);
            hold = max(hold, notHeld - prices[i]);
        }
        return max(hold, notHeld);
    }
};