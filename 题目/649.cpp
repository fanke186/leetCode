#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        char winner = 'G';
        while (!senate.empty()) {
            for (int i = 0; i < senate.length(); ++i) {
                char cur = senate[i];
                char opp = senate[i] == 'D' ? 'R' : 'D';
                int next = senate.find(opp, i);
                if (next != string::npos) { // 在i之后找到
                    senate.erase(next, 1);
                } else {
                    next = senate.find(opp);
                    if (next != string::npos) { // 在i之前找到
                        senate.erase(next, 1);
                        i--;
                    } else { // 没找到
                        winner = cur;
                        break;
                    }
                }
            }
            if (winner != 'G')
                break;
        }
        return winner == 'R' ? "Radiant" : "Dire";
    }
};