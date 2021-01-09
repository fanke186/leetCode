#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit[n][3][2]; // 天, 完成了的交易次数, 是否持有
        // 第x次卖掉，称为完成了x次交易
        //
        // 边界:设置第一天
        // 第一天只需要区分是否持有
        for (int i = 0; i < 3; i++) {
            profit[0][i][0] = 0;
            profit[0][i][1] = -prices[0];
        }
        // 状态转移
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; j++) {
                if (j != 0) { // 完成非零次数的交易且未持有：两个转移源头，一是前一天未持有，继续观望；二是前一天持有，卖出；
                    profit[i][j][0] = max(profit[i-1][j][0], profit[i-1][j-1][1] + prices[i]);
                } else { // 完成0次交易且未持有：只有一个转移源头，就是前一天未持有，继续观望；
                    profit[i][j][0] = profit[i-1][j][0];
                } // 持有股票：两个转移源头，一是前一天持有，继续持有；二是前一天未持有，今天买入；
                profit[i][j][1] = max(profit[i-1][j][1], profit[i-1][j][0] - prices[i]);
            }
        }
        // 最大利润就是最后一天未持有的最大值
        return max(profit[n-1][0][0], max(profit[n-1][1][0], profit[n-1][2][0]));
    }
};


// 一天结束，一共有五种状态：
// 1一直无作为；（这个不用记录，利润一直为0）
// 2第一次买入，尚未卖出；3第一次卖出，尚未再次买入；
// 4第二次买入，尚未卖出；5第二次卖出；
// 分别记为 buy1, sell1, buy2, sell2;
// 各自的转移方程：
//      buy1  = max(buy1, -prices[i])
//      sell1 = max(sell1, buy1 + prices[i])
//      buy2  = max(buy2, sell1 - prices[i])
//      sell2 = max(sell2, buy2 + prices[i])
// 初始条件：
//      buy1 第一天买入，即为-prices[0]
//      sell1第一天买入后卖出，即为0
//      buy2 在sell1基础上再买入，即为-prices[0]
//      sell2在buy2基础上卖出，即为0
// 最终返回值：
//      是0, sell1, sell2的最大值，显然后二者都大于等于0；
//      更进一步地，如果最后最大值出现在sell1，
//          也可以通过在最后一天买入再卖出来使得sell2也达到同样的最大值；
//      所以最终返回值为sell2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 0; i < n; ++i) {
            buy1  = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2  = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};
