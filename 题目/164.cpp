#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



// O(nlogn)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ret = -1;
        for (int i = 0; i < nums.size()-1; i++) {
            ret = max(ret, nums[i+1]-nums[i]);
        }
        return ret;
    }
};


// 桶排序的思想
// 假设有n个数，则求出最大最小值后分n个桶，
// 再次遍历将元素一一映射到桶内，但并不保存每个元素
// 比如桶(10~50)只保存属于这个桶的最小和最大
// 完成桶的装填后
// 遍历桶，求最大间隔

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxNum = -1;
        int minNum = 0x3f3f3f3f;
        for (int& num : nums) {
            maxNum = max(maxNum, num);
            minNum = max(minNum, num);
        }

        // 创建桶
        // 每个桶只放两个数，[1]最小和[2]最大,[0]记录桶内是否有元素
        int bucketNum = nums.size() + 1;
        vector<int> single = {0, 0x3f3f3f3f, -1};
        vector<vector<int>> buckets(bucketNum, single);

        // 映射到桶
        for (int& num : nums) {
            int idx = num / (maxNum - minNum);
            buckets[idx][0] = 1;
            buckets[idx][1] = min(buckets[idx][0], num);
            buckets[idx][2] = max(buckets[idx][1], num);
        }

        // 遍历桶求最大间隔
        // 要记录前一个不为0的桶的idx
        int ret = 0;
        int prev = 0;
        while (buckets[prev][0] == 0) {
            prev++;
        }
        //ret = max(ret, buckets[prev][2] - buckets[prev][1]);
        for (int i = prev + 1; i < nums.size()+1; i++) {
            if (buckets[i][0] == 1) {
                ret = max(ret, buckets[i][1] - buckets[prev][2]);
                prev = i;
            } else {
                continue;
            }
        }
    }
};
