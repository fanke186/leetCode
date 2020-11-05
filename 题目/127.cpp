#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

// ***************************************************
// 给定两个单词（beginWord 和 endWord）和一个字典,
// 找到从 beginWord 到 endWord 的最短转换序列的长度.
// 转换需遵循如下规则：
//      1.每次转换只能改变一个字母.
//      2.转换过程中的中间单词必须是字典中的单词.
// ***************************************************

using namespace std;

class Solution {
public:
    unordered_map<string, int> word2ID; // 单词-->ID
    vector<vector<int>> edges; // 建立无向图
    int nodeNum = 0;

    // 添加单词到 word2ID, 同时为其开辟一个边数组
    void addWord(string& word) {
        if(!word2ID.count(word)) {
            word2ID[word] = nodeNum++;
            edges.emplace_back();
        }
    }

    void addEdge(string& word) {
        addWord(word);
        int id1 = word2ID[word];
        // 对单词hot, 添加 *ot, h*t, ho* 到字典
        // 虚拟结点，这样可以减少开销
        for (char& it : word) {
            char temp = it;
            it = '*';
            addWord(word); 
            int id2 = word2ID[word];
            edges[id1].push_back(id2);
            edges[id2].push_back(id1);
            it = temp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 添加单词到字典
        for (string& word : wordList) 
            addEdge(word);   
        addEdge(beginWord);
        // 若endWord不在其中, 则返回0
        if(!word2ID.count(endWord)) 
            return 0;
        // dis记录beginWord到其他单词的距离
        vector<int> dis(nodeNum, INT_MAX);
        int beginID = word2ID[beginWord];
        int endID = word2ID[endWord];
        // begin到begin距离置0
        dis[beginID] = 0;
        // BFS
        queue<int> que;
        que.push(beginID);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            if (x == endID) 
                return dis[endID] / 2 + 1;
            for (int& it : edges[x]) {
                if(dis[it] == INT_MAX) {
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }
};

