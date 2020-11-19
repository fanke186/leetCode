#include <vector>

using namespace std;

// 不断的交换数组中 第一个0元素 和 第一个非0元素 即可
// zero 记录第一个0的下标
// nonZero 记录第一个0之后的第一个非0的下标
class Solution {
public:        
    void moveZeroes(vector<int>& nums) {
        int zero = 0, nonZero = 0;
        int n = nums.size();
        while (1) {
            while (zero < n && nums[zero] != 0)
                zero++;
            nonZero = zero;
            while (nonZero < n && nums[nonZero] == 0)
                nonZero++;
            if (nonZero < n)
                swap(nums[zero], nums[nonZero]);
            else 
                break;
        }
    }
};


// 双指针法2
// 思路：
// 从前往后找非零元素，依次将它们存放到要求的位置：即第l个非零元素存放到nums[l]，
// l表示当前应存放第l个非零元素，r为遍历nums的指针，每当nums[r]非零，则交换nums(l, r)，且l++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        while (r < n) {
            if (nums[r]) {
                swap(nums[l], nums[r]);
                l++;
            }
            r++;
        }
    }
};