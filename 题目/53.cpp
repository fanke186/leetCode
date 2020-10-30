#include <iostream>
#include <vector>

using namespace std;

// 动态规划V1.0
// dp[i] 记录以nums[i]结尾的最大子数组和
// 状态转移：dp[i] = max(dp[i-1]+nums[i], nums[i])
//      即：要么延长以nums[i-1]结尾的，要么一个数单独作为子数组；
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        vector<int> dp(nums.size(), 0);
        // 设置底
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

// 动态规划V1.1
// 考虑到状态转移中：dp[i]只与dp[i-1]有关
// 将dp数组压缩到只用一个int记录前驱dp值即可
// 这样可以将空间压缩到O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int preDP = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 更新dp[i]
            preDP = max(preDP + nums[i], nums[i]);
            ret = max(ret, preDP);
        }
        return ret;
    }
};

// 分治法
// 对于数组A[l, r]
// 定义一个递归方法get(A, l, r), 返回这个数组内的最大子数组和
//      将[l, r]分为两半:[l, m], [m+1, r], 其中m=(l+r)/2,
//      递归调用get(A, l, m), get(A, m+1, r)
// 递归子问题求解[l, r]:m是其中点
//      1.目标子数组完全在左半,即get(A, l, m)
//      2.目标子数组完全在右半,即get(A, m+1, r)
//      3.目标子数组跨越了中点
// 对于每个递归到的子区间[l, r]，维护一些信息：
//      1.lSum, 记录以A[l]为左端点的最大子数组
//      2.rSum, 记录以A[r]为右端点的最大子数组
//      3.mSum, 记录区间[l, r]内的最大子数组
//      4.iSum, 记录区间[l, r]的所有元素之和
class Solution {
public:
    struct info{
        int lSum, rSum, mSum, iSum;
    };

    info merge(info lHalf, info rHalf) {
        int iSum = lHalf.iSum + rHalf.iSum;
        int lSum = max(lHalf.lSum, lHalf.iSum + rHalf.lSum);
        int rSum = max(rHalf.rSum, rHalf.iSum + lHalf.rSum);
        int mSum = max(max(lHalf.mSum, rHalf.mSum), lHalf.rSum + rHalf.lSum);
        return (info){lSum, rSum, mSum, iSum};
    }

    info get(vector<int>& nums, int l, int r) {
        // 递归边界
        if (l == r)
            return (info){nums[l], nums[l], nums[l], nums[l]};
        int m = (l+r)/2;
        auto lHalf = get(nums, l, m);
        auto rHalf = get(nums, m+1, r);
        return merge(lHalf, rHalf);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size()-1).mSum;
    }
};