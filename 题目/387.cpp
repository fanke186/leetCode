#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        //vector<int> cnt(26, 0);
        int cnt[26] = {0};
        int ret = -1;
        for (int i = 0; i < s.length(); ++i) {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};