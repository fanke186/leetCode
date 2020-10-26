#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 计数
// nums元素在[0, 100]
// 用cnt[i]来记录i出现的次数
// 则nums[i]的结果就是sum(cnt[j])，其中j为所有小于i的值
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        vector<int> ret(nums.size(), 0);
        // 构建cnt数组
        for (int num : nums)
            cnt[num]++;
        
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[i]; j++)
                ret[i] += cnt[j];
        return ret;
    }
};



