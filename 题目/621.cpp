#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>


using namespace std;


// 将tasks按出现次数重新排序,且保证同频字母各自挨在一起
// 如: ABABCABC -> AAABBBCC
// 每次循环输出n+1个字母，依次取频率最大的n+1个，不够就待命
// 不OK：无法做 input = {'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E'};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (auto& c : tasks)
            cnt[c - 'A']++;
        sort(tasks.begin(), tasks.end(), [&](char c1, char c2){    
            if (cnt[c1 - 'A'] == cnt[c2 - 'A'] && c1 != c2)
                return c2 > c1;            
            return cnt[c1 - 'A'] > cnt[c2 - 'A'];
        });
        int ret = 0;
        
        while (!tasks.empty()) {
            int toExecute = 0;
            for (int i = 0; i <= n; ++i) {
                if (toExecute >= tasks.size()) { // 说明要待命了
                    if (!tasks.empty()) {
                        ret += (n - i + 1);
                        for (int j = 0; j < n-i+1; ++j)
                            cout << "待命,";
                    }
                    break;
                }
                cnt[tasks[toExecute] - 'A']--;
                cout << tasks[toExecute] << ',';
                int temp = cnt[tasks[toExecute] - 'A'];
                tasks.erase(tasks.begin() + toExecute);
                ret++;
                toExecute += temp;
            }
        }
        cout << endl;
        return ret;
    }
};


// 数学方法
// 妙啊
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }

        // 最多的执行次数
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
            return u.second < v.second;
        })->second;
        // 具有最多执行次数的任务数量
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u) {
            return acc + (u.second == maxExec);
        });

        return max((maxExec - 1) * (n + 1) + maxCount, 
                    static_cast<int>(tasks.size()));
    }
};