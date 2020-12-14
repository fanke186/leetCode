#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // my_map：key为字符组合，vector<string>为从属这个组合的单词
        unordered_map<string, vector<string>> my_map;
        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            my_map[key].emplace_back(strs[i]);
        }
        vector<vector<string>> ret;
        for (auto it = my_map.begin(); it != my_map.end(); ++it) {
            ret.emplace_back(it->second);
        }
        return ret;
    }
};