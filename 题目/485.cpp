#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0, curLen = 0;
        for (int num : nums) {
            if (num) {
                curLen++;
            } else {
                maxLen = max(maxLen, curLen);
                curLen = 0;
            }
        }
        return max(maxLen, curLen);
    }
};