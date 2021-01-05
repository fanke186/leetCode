#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ret;
        int n = s.length();
        int left = 0, right = 0;
        while (right < n + 1) {
            if (s[left] == s[right]) {
                right++;
            } else {
                if (right - left >= 3){
                    ret.push_back({left, right - 1});
                }
                left = right;
            }
        }
        return ret;
    }
};