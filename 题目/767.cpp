#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>


using namespace std;


// 设共出现了x个字母,它们的出现次数分别为cnt[0],cnt[1]...cnt[x-1],都不为0
// 将cnt数组按从大到小排序:cnt[0] >= cnt[1] >=...>= cnt[x-1]
// 交叉输出前两个字母，并把相应的cnt--，若cnt=0则删除这个字母,维护顺序关系(大根堆)

// str只包含小写字母,长度为n
// str长为n，则单个字母最多出现ceil(n/2.0)次

// vector实现
class Solution {
public:
    static bool my_cmp(pair<int, char> a, pair<int, char> b) {
        return a.second >= b.second;
    } 

    string reorganizeString(string S) {
        int n = S.length();
        int MAX_CNT = ceil(n / 2.0);
        int max_cnt = 0;
        int cnt[26] = {0};
        for (char& c : S)
            cnt[c - 'a']++;
        for (int i = 0; i < 26; i++)
            max_cnt = max(max_cnt, cnt[i]);
        if (max_cnt > MAX_CNT)
            return "";
        
        vector<pair<char, int>> char_cnt;
        for (int i = 0; i < 26; i++)
            if (cnt[i] != 0)
                char_cnt.push_back(pair<char, int>('a' + i, cnt[i]));
        sort(char_cnt.begin(), char_cnt.end(), my_cmp);

        string ret = "";
        while (char_cnt.size() >= 2) {
            if (!ret.empty() && ret[ret.length()-1] == char_cnt[0].first) {
                ret += char_cnt[1].first;
                ret += char_cnt[0].first;
            } else {
                ret += char_cnt[0].first;
                ret += char_cnt[1].first;
            }
            // 注意这里要频度第二的先检查
            // 因为如果先删除了频度第一的，再删除第二，实际删除是原第三的；
            if (--char_cnt[1].second == 0)
                char_cnt.erase(char_cnt.begin() + 1);
            if (--char_cnt[0].second == 0)
                char_cnt.erase(char_cnt.begin());
        }
        if (char_cnt.size() != 0)
            ret += char_cnt[0].first;
        return ret;
    }
};


// 大根堆实现
class Solution {
public:
string reorganizeString(string S) {
        int n = S.length();
        int MAX_CNT = ceil(n / 2.0);
        int max_cnt = 0;
        int cnt[26] = {0};
        for (char& c : S)
            cnt[c - 'a']++;
        for (int i = 0; i < 26; i++)
            max_cnt = max(max_cnt, cnt[i]);
        if (max_cnt > MAX_CNT)
            return "";
        
        auto cmp = [&](char a, char b){ return cnt[a-'a'] < cnt[b-'a'];};
        priority_queue<char, vector<char>, decltype(cmp)> char_cnt(cmp);
        for (int i = 0; i < 26; i++)
            if (cnt[i] != 0)
                char_cnt.push('a' + i);

        string ret = "";
        while (char_cnt.size() >= 2) {
            char c1 = char_cnt.top();
            char_cnt.pop();
            ret += c1;
        
            char c2 = char_cnt.top();
            char_cnt.pop();
            ret += c2;
            
            if (--cnt[c1 - 'a'] > 0)
                char_cnt.push(c1);
            if (--cnt[c2 - 'a'] > 0)
                char_cnt.push(c2);
        }
        if (!char_cnt.empty())
            ret += char_cnt.top();
        return ret;
    }
};
