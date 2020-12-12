#include <vector>

using namespace std;

// 贪心法
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int ret = 1;
        int prev = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int cur = nums[i] - nums[i-1];
            if (cur == 0) {
                continue;
            } else if (cur > 0) {
                if (prev <= 0) {
                    ret++;
                    prev = 1;
                }
            } else {
                if (prev >= 0) {
                    ret++;
                    prev = -1;
                }
            }
        }
        return ret;
    }
};

// 贪心法写法的改进
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int ret = 1;
        int prev = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int cur = nums[i] - nums[i-1];
            if (cur > 0 && prev <= 0 || cur < 0 && prev >= 0) {
                ret++;
                prev = cur;
            }
        }
        return ret;
    }
};


// DP
