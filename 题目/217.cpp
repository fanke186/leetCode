#include <vector>
#include <unordered_set>

using namespace std;


// 注意使用的是unordered_set
// set是有序的，插入效率要低一些
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numbers;
        for (int& num : nums) {
            if (numbers.count(num)) {
                return true;
            }
            numbers.insert(num);
        }
        return false;
    }
};