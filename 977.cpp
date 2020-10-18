#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret(A.size(), 0);
        int l = 0, r = A.size() - 1;
        for (int i = 0; i < A.size(); i++){
            if(abs(A[l]) > abs(A[r])){
                ret[A.size() - i -1] = A[l]*A[l];
                l++;
            }else{
                ret[A.size() - i -1] = A[r]*A[r];
                r--;
            }
        }
        return ret;
    }
};