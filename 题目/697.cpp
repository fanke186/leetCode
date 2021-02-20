#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> element;
        for (int i = 0; i < nums.size(); i++) {
            if (!element.count(nums[i])) {
                element[nums[i]] = {1, i, i};
            } else {
                element[nums[i]][0]++;
                element[nums[i]][2] = i;
            }
        }
        int maxCnt = 0, minLen = 0x3fff;
        for (auto& it : element) {
            // 找cnt最大中len最小的
            if (maxCnt < it.second[0]) { // 新的最大cnt
                maxCnt = it.second[0];
                minLen = it.second[2] - it.second[1] + 1;
            } else if (maxCnt == it.second[0]) { // 相同的cnt中找最小的
                minLen = min(minLen, it.second[2] - it.second[1] + 1);
            }
        }
        return minLen;
    }
};