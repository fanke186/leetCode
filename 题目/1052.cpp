#include <vector>

using namespace std;


// 模拟法
// 超时
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int maxProfit = 0, maxProfitTime = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            int ori = 0;
            int after = 0;
            for (int j = 0; j < X && (i+j) < n; j++) {
                if (grumpy[i+j] == 0) {
                    ori += customers[i+j];
                }
                after += customers[i+j];
            }
            if ((after - ori) > maxProfit) {
                maxProfit = after - ori;
                maxProfitTime = i;
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (i == maxProfitTime) {
                for (int j = 0; j < X && (i+j) < n; j++) {
                    ret += customers[i+j];
                }
                i += X - 1;
                continue;
            }
            if (grumpy[i] == 0) {
                ret += customers[i];
            }
        }
        return ret;
    }
};

// 通过了，但还是慢
// 思路是对的，但是求maxProfit的过程很慢
/*
    先确定不使用技能时的客人总数，然后找到使用技能的最大收益值，
    这样问题就转化为了：求指定长度的连续子数组之和的最大值问题
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int before = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                before += customers[i];
            }
        }
        // 原来的求maxProfit方法
        // for (int i = 0; i + X <= n; i++) {
        //     int profit = 0;
        //     for (int j = 0; j < X; j++) {
        //         profit += customers[i+j] * grumpy[i+j];
        //     }
        //     maxProfit = max(maxProfit, profit);
        // }
        //
        // 滑动窗口思想（窗口大小为X）
        int profit = 0;
        for (int i = 0; i < X; i++) {
            profit += customers[i] * grumpy[i];
        }
        int maxProfit = profit;
        for (int i = X; i < n; i++) {
            profit = profit - customers[i-X] * grumpy[i-X] + customers[i] * grumpy[i];
            maxProfit = max(maxProfit, profit);
        }
        return before + maxProfit;
    }
};