#include <string>
#include <unordered_map>

using namespace std;

// pattern和word之间是一个双射关系
// 用两个map来分别保存p2w和w2p
// 遍历每一对 (p, word)查看是否存在不匹配：
//      1.p2w中存在key为p但value不为word
//      2.w2p中存在key为word但value不为p
// 还要检查长度匹配
class Solution {
public:
    bool wordPattern(string pattern, string s) {    
        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;
        
        int prevIdx = 0; // 用来找s中的每个单词
        for (char curP : pattern) {
            if (prevIdx >= s.length()) { // pattern数 > 单词数：返回false
                return false;
            }

            // 找到当前单词curWord
            int curEnd = prevIdx;
            while (s[curEnd] != ' ' && curEnd < s.length()) {
                curEnd++;
            }
            string curWord = s.substr(prevIdx, curEnd - prevIdx);

            // (p, word)存在不匹配
            if (p2w.count(curP) && p2w[curP] != curWord) {
                return false;
            }
            if (w2p.count(curWord) && w2p[curWord] != curP) {
                return false;
            }
            // (p, word)不存在不匹配
            p2w[curP] = curWord;
            w2p[curWord] = curP;
            prevIdx = curEnd + 1;
        }
        return prevIdx >= s.length(); // 单词数 > pattern数：返回false
    }
};