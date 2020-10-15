#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <numeric>

using namespace std;

// ***********
// 0/1背包问题，恰好填充
// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
// ***********

// 时间：O(nc)，n为数组长度，c为sum/2
// 空间：O(nc)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxNum = 0;
        for (int i = 0; i < n; i++){
            maxNum = max(maxNum, nums[i]);
            sum += nums[i];
        }

        // 如果和是奇数，肯定不存在
        // 如果最大值大于和的一半，也肯定不存在
        if (sum % 2)
            return false;
        if (maxNum > sum /2)
            return false;

        // 容量为 target 的背包
        int target = sum / 2;
        // dp[i][j] ：nums的前 i 个数是否能选出一些数的组合，使得其和为j；
        bool dp[n][target+1];
        memset(dp, false, sizeof(dp));

        // 设置DP数组第一行的值，前0个数，也就是只有一个数啦
        if (nums[0] <= target)
            dp[0][nums[0]] = true;
        // 为了状态转移的方便，设置第0列为true，即背包容量为0；
        for (int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        // 设置DP数组的其他行
        for (int i = 1; i < n; i++){
            for (int j = 0; j < target+1; j++){
                dp[i][j] = dp[i-1][j];

                if (j >= nums[i])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][target];
    }
        
};


// 时间：O(nc)，n为数组长度，c为sum/2
// 空间：O(c)：抓住两个点：从后往前逆序写入dp数组，初始化仍是只有nums[0]
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxNum = 0;
        for (int i = 0; i < n; i++){
            maxNum = max(maxNum, nums[i]);
            sum += nums[i];
        }

        // 如果和是奇数，肯定不存在
        // 如果最大值大于和的一半，也肯定不存在
        if (sum % 2)
            return false;
        if (maxNum > sum /2)
            return false;

        // 容量为 target 的背包
        int target = sum / 2;
        // dp[j] ：nums的前任意个数是否能选出一些数的组合，使得其和为j；
        bool dp[target+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;

        // 设置DP数组第一行的值，前0个数，也就是只有一个数啦，整列是or起来的
        if (nums[0] <= target)
            dp[nums[0]] = true;
        
        // 设置DP数组的其他行
        // 这个过程还是和二维DP数组一样的：
        //      外层循环是对每个数，也是从前往后一个个比较，当前的数要不要放进去；
        for (int i = 1; i < n; i++){
            for (int j = target; nums[i] <= j; j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[target];
    }
        
};