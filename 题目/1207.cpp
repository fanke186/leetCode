#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // 哈希表记录 key(数字)--val(cnt)
        unordered_map<int, int> lookup;
        for (int num : arr) {
            if (!lookup.count(num))
                lookup.emplace(num, 1);
            else
                lookup.at(num)++;
        }
        // 哈希集合记录 cnt，需保证其唯一性，否则返回false
        unordered_set<int> cnts;
        for (auto it = lookup.begin(); it != lookup.end(); it++) {
            if (cnts.count(it->second))
                return false;
            else 
                cnts.emplace(it->second);
        }
        return true;
    }
};

