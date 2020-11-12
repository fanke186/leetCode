#include <vector>

using namespace std;

// ********************************************************
// 给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
// 对数组进行排序, 以便当 A[i] 为奇数时，i 也是奇数；
//                   当 A[i] 为偶数时，i 也是偶数。
// ********************************************************


// 创建新的vector
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd = 1, even = 0;
        vector<int> ret(A.size());
        for (int& num : A) {
            if (num % 2) {
                ret[odd] = num;
                odd += 2;
            } else {
                ret[even] = num;
                even += 2;
            }
        }
        return ret;
    }
};

// in-place
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd = 1, even = 0;
        while (odd < A.size() && even < A.size()) {
            if (A[even] % 2) {
                while (A[odd] % 2) {
                    odd += 2;
                }
                swap(A[even], A[odd]);
            }
        }
        return A;
    }
};