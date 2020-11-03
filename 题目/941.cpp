#include <iostream>
#include <vector>

using namespace std;

// *************************************
// 给定一个数组，判断它是否是山脉；
// *************************************

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        int n = A.size();
        int i = 0;
        // 是否可以上山
        if (i+1 < n && A[i] < A[i+1]) {
            while (i+1 < n && A[i] < A[i+1])
                i++;
            // 是否可以下山
            if (i+1 < n && A[i] > A[i+1]) {
                while (i+1 < n && A[i] > A[i+1])
                    i++;
            } else return false;
            
            if (i < n-1)
                return false;
        } else return false;
        return true;
    }
};