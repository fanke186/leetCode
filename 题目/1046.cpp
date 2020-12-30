#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int num : stones) {
            q.push(num);
        }
        while (q.size() >= 2) {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (x != y) {
                q.push(y - x);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};