#include <vector>

using namespace std;

// *******************************************************
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target
// 找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// *******************************************************

// O(n)
// 顺序检查每一个元素
class Solution {
public:
    vector<int> searchRange(vector<int> nums, int target) {
        int begin, end, flag = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (flag == 0) {
                    flag = 1;
                    begin = end = i;
                } else 
                    end++;
            }
        }
        if (flag == 0)
            return {-1, -1};
        return {begin, end};
    }
};


// O(logn)
// 二分查找到某个下标found
// found向前直到不是target,是为begin
// found向后直到不是target,是为end
class Solution {
public:
    vector<int> searchRange(vector<int> nums, int target) {
        int begin, end, found = -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else {
                found = mid;
                break;
            }       
        }
        if (found == -1)
            return {-1, -1};
        begin = end = found;
        while (begin >= 0 && nums[begin] == target)
            begin--;
        while (end < nums.size() && nums[end] == target)
            end++;
        return {begin + 1, end - 1};
    }
};