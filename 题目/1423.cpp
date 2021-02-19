#include <vector>

using namespace std;


// 超出时间限制
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int remain = k, n = cardPoints.size();
        int ret = 0;

        while (remain) {
            int lSum = 0, rSum = 0;
            for (int i = 0; i < remain; i++) {
                lSum += *(cardPoints.begin() + i);
                rSum += *(cardPoints.end() - 1 - i);
            }
            if (lSum > rSum) {
                ret += *(cardPoints.begin());
                cardPoints.erase(cardPoints.begin());
            } else {
                ret += *(cardPoints.end() - 1);
                cardPoints.erase(cardPoints.end() - 1);
            }
            remain--;
        }
        return ret;
    }
};