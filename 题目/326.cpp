#include <string>
#include <vector>

using namespace std;


// 模拟过程
// vector：letters长度26
// letter[i]记录的是这个字母('a' + i)出现的下标集合，记不同字母数为n
// 贪心思想：类似于选最小的数字，从高位开始选“能选”的最小
// “能选”：因要保持相对顺序，选了当前第i个字母后，则"后置"还需有n-i个不同的字母
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<vector<int>> letters(26, vector<int>());
        for (int i = 0; i < s.length(); i++) {
            letters[s[i] - 'a'].push_back(i);
        }
        int n = 0;
        for (auto it : letters) {
            if (!it.empty()) {
                n++;
            }
        }

        string ret = "";
        // 一共需要选出n个不同的字母
        for (int i = 1; i < n+1; i++) {
            for (int j = 0; j < 26; j++) { // 依次检查每个字母是否符合条件
                if (!letters[j].empty()) {
                    char curLetter = 'a' + j;
                    int following = 0;
                    for (int k = 0; k < 26; k++) { // 后置的不同的字母数
                        if (k != j && !letters[k].empty() && letters[k].back() > letters[j].front()) {
                            following++;
                        }
                    }
                    if (following >= n - i) { // 符合条件
                        ret.push_back(curLetter);
                        int selectedIdx = letters[j].front();
                        letters[j].clear(); // 注意这里是clear而不是earse，不然下标会出错
                        // 将selectedIdx之前的字母都去除
                        for (auto& it : letters) {
                            for (int m = 0; m < it.size(); m++) {
                                if (it[m] < selectedIdx) {
                                    it.erase(it.begin() + m);
                                    m--; // earase会导致下标的变化
                                }
                            }
                        }
                        break;
                    }
                }
                
            }
        }
        return ret;
    }
};

// 贪心 + 栈
// 字典序最小也类似于数字最小：高位越小，就算低位大，它也是小的
// 贪心思想：字符串s去除一个字符，要求保留的字典序最小，
//          则要去除的就是满足s[i-1] > s[i]的最小下标i，
// 因为只需要与s[i-1]比较，考虑使用栈，这个栈内存储的元素其实是递增的，即为一个单调栈
//
// 题目还要求字符串中的字母出现且只出现一次，还需要加入以下机制：
// 1.用一个数组记录i后续的各个字母的数量，如果字母s[i-1]的数量等于0，那就不能pop它
// 2.用一个数组记录i是否已经入栈中，如果已在，则不能入栈
class Solution {
public:
    string removeDuplicateLetters1(string s) {
        string ret = ""; // 当栈来用
        vector<bool> inStack(26, false); // 记录是否在栈中
        vector<int> cntLetter(26, 0); // 记录后续各个字母的数量
        for (char ch : s) {
            cntLetter[ch - 'a']++;
        }
        
        for (char ch : s) {
            cntLetter[ch - 'a']--;
            if (!ret.empty()) {
                // 需要pop栈顶
                while (!ret.empty() && ret.back() > ch && cntLetter[ret.back() - 'a'] && !inStack[ch - 'a']) {
                    inStack[ret.back() - 'a'] = false;
                    ret.pop_back();
                }
            }
            // push当前字母
            if (!inStack[ch - 'a']) {
                ret.push_back(ch);
                inStack[ch - 'a'] = true;
            }
        }
        return ret;
    }
};