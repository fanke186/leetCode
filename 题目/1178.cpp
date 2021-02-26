#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> map;
        for (string& word : words) {
            int mask = 0;
            for (char& ch : word) {
                mask |= (1 << (ch - 'a'));
            }
            if (__builtin_popcount(mask) <= 7) {
                map[mask]++;
            }
        }

        vector<int> ret;
        for (string& puzzle : puzzles) {
            int total = 0;
            for (int choose = 0; choose < (1 << 6); choose++) {
                int mask = 0;
                mask |= (1 << puzzle[0] - 'a'); // 必选首字符
                for (int i = 0; i < 6; i++) { // 选或者不选后续6个字符
                    if (choose & (1 << i)) {
                        mask |= (1 << (puzzle[i+1] - 'a'));
                    }
                }
                if (map.count(mask)) {
                    total += map[mask];
                }
            }
            ret.push_back(total);
        }
        return ret;
    }
};