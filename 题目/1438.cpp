#include <vector>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

// 从左到右，求得满足条件的下标i开始的最长连续子数组，长度记为maxLen，
// 然后查看从下标i+1开始的长度为maxLen+1的连续子数组是否满足条件
// 超时了
class Solution {
public:
    int getSubMax(vector<int>& nums, int l, int r) {
        int subMin = *min_element(nums.begin() + l, nums.begin() + r);
        int subMax = *max_element(nums.begin() + l, nums.begin() + r);
        return subMax - subMin;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + maxLen;
            if (j >= nums.size()) {
                return maxLen;
            }
            int subMax = getSubMax(nums, i, j);
            while (subMax <= limit) { // 满足条件
                maxLen = j - i + 1;
                j++;
                if (j >= nums.size()) {
                    return maxLen;
                }
                subMax = getSubMax(nums, i, j);
            }
        }
        return maxLen;
    }
};


// 主要提升的点是快速找到子数组的最大值和最小值，
// 上面是遍历一遍查找，复杂度为O(k)，超时了
// 考虑以空间换时间，可以利用更好（本身有序）的数据结构
//
// 在 C++ 中 set/multiset/map 内部元素是有序的，它们都基于红黑树实现。其中 set 会对元素去重，而 multiset 可以有重复元素，map 是 key 有序的哈希表。
// 在 Java 中 TreeSet 是有序的去重集合，TreeMap 是 key 有序的哈希表，它们也是基于红黑树实现的。
// 在 Python 中 sortedcontainers  实现了有序的容器
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int n = nums.size();
        int left = 0, right = 0;
        int ret = 0;
        while (right < n) {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[left++]));
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};