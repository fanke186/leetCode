#include <iostream>
#include <vector>

using namespace std;

// 枚举山顶，
// 类似DP，
// 使用两个O(n)数组：left, right，分别记录 以i为山顶能向左向右“下山”多远，
// left的转移方程为：left[i] = left[i-1] + 1, 若A[i] > A[i-1],
//                  left[i] = 0, 若A[i] <= A[i-1] 或 i=0,
// right的转移方程类似,
// 得到两个数组后,枚举得到最长山脉,
// 以 A[i]为山顶的长度为: left[i] + right[i] + 1.
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if (!n) return 0;
        vector<int> left(n), right(n);
        left[0] = 0, right[n-1] = 0;
        // 处理两个数组
        for (int i = 1; i < n; i++){
            // 得到left数组
            if (A[i] <= A[i-1])
                left[i] = 0;
            else 
                left[i] = left[i-1] + 1;
            // 得到right数组
            if (A[n-i] >= A[n-i-1] )
                right[n-i-1] = 0;
            else 
                right[n-i-1] = right[n-i] + 1;
        }
        // 选出最长山脉
        int ret = 0;
        for (int j = 0; j < n; j++)
            if (left[j] && right[j])
                ret = max(ret, left[j] + right[j] +1);
        return ret;
    }
};


// 空间O(1)
// 双指针l, r分别记录山的左边和右边
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        int ret = 0, l = 0;
        while (l + 2 < n) {
            int r = l + 1;
            if (A[l] < A[l+1]) { // 可以上山？
                while (r+1 < n && A[r+1] > A[r]) // 上山
                    r++;
                if (r+1 < n && A[r+1] < A[r]) { //可以下山？
                    while (r+1 < n && A[r+1] < A[r]) // 下山 
                        r++;
                    ret = max(ret, r-l+1);
                }
                else // 不能下山
                    r++;
                
            }
            l = r; // 不能上山或者已经下山
        }
        return ret;
    }
};


