#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0, cnt = 0;
        int ret = 0;
        for (right = 0; right < A.size(); ++right) {
            if (A[right] == 0) {
                ++cnt;
            }
            while (cnt > K) {
                if (A[left++] == 0) {
                    --cnt;
                }
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};


class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0, cnt = 0;
        int ret = 0;
        for (right = 0; right < A.size(); ++right) {
            if (A[right] == 0) {
                ++cnt;
            }
            if (cnt > K && A[left++] == 0) {
                --cnt;
            }
        }
        return right - left;
    }
};