#include <vector>

using namespace std;


// 没啥好说的
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int& pay : bills) {
            if (pay == 20) {
                if (ten >= 1 && five >= 1) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            } else if (pay == 10) {
                if (five >= 1) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else {
                five++;
            }
        }
        return true;
    }
};