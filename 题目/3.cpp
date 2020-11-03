#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

// 题目描述
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//      输入: "pwwkew"
//      输出: 3
//      解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。



// 使用string中的find函数来判断子串中是否存在当前字符
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        for (int i=0; i<s.length(); i++) {
            int cur = 1;
            int l = i, r = i+1;
            string curSub = s.substr(l, r-l);
            while (r < s.length() && curSub.find(s[r]) == string::npos){
                cur++;
                r++;
                curSub = s.substr(l, r-l);
            }
            ret = max(ret, cur);
        }
        return ret;
    }
};

// 使用hash集合来判断子串中是否存在当前字符
// 时间效率更优(其实并没有，或者string类里的find实现就是哈希结构的)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        for (int i=0; i<s.length(); i++) {
            int cur = 1;
            int l = i, r = i+1;
            unordered_set<char> set;
            while (r < s.length() && !set.count(s[r])){
                set.emplace(s[r]);
                cur++;
                r++;
            }
            ret = max(ret, cur);
        }
        return ret;
    }
};

// 在上面的基础上
// right指针不再回溯，left指针也不再是一格一格往前挪
// 维护哈希集合：
//      当right遇到重复字符的时候，不断的删除left所指向的字符，
//      直到right字符不再重复位置，并在期间维护ret的最大长度即可。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int ret = 0;
        int l = 0, r = 0;
        unordered_set<char> lookup;
        for (r = 0; r < s.length(); r++){
            while (lookup.count(s[r])){
                lookup.erase(s[l]);
                l++;
            }
            lookup.emplace(s[r]);
            ret = max(ret, r-l+1);
        }
        return ret;
    }
};


