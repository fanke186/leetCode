#include <vector>
#include <algorithm>

using namespace std;

// 贪心的思想
// 从小到大排序数组A,选最大的作为第三边,选它前两个作为另外两边
// 这是包含最长边的最大周长
// 若不满足成三角形的条件,一直往前选择最长边
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for(int i = A.size() - 1; i >= 2; i--){
            if(A[i] < A[i-1] + A[i-2])
                return A[i] + A[i-1] + A[i-2];
        }
        return 0;
    }
};