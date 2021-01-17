#include <vector>

using namespace std;

// 一般式
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int a, b, c, flag = 1; // line
        a = coordinates[1][1] - coordinates[0][1];
        b = coordinates[0][0] - coordinates[1][0];
        c = coordinates[0][1] * (coordinates[1][0] - coordinates[0][0]) - coordinates[0][0] * (coordinates[1][1] - coordinates[0][1]);

        for (auto p : coordinates) {
            if (a * p[0] + b * p[1] + c != 0) {
                flag = 0;
                break;
            }
        }
        return flag;
    }
};