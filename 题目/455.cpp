#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        int ret = 0;
        while (child < g.size() && cookie < s.size()) {
            // 满足
            if (g[child] <= s[cookie]) {
                ret++;
                child++;
                cookie++;
            } else { // 不满足
                cookie++;
            }
        }
        return ret;
    }
};