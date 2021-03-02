#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n+1); // sums[i]储存的是前i项和，下标0不用
        for (int i = 0; i < n; i++) {
            sums[i+1] = sums[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        // 也就是第i+1项到第j+1项之和
        return sums[j+1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */