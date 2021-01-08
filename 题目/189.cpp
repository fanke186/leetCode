#include <vector>
#include <algorithm>

using namespace std;

// 时间效率太低
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp, n = nums.size();
        for (int i = 0; i < k; i++) {
            temp = nums[n-1];
            for (int j = n-1; j > 0; j--) {
                nums[j] = nums[j-1];
            }
            nums[0] = temp;
        }
    }
};

// 用太多空间
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums2(nums);
        int n = nums.size();
        k %= n;
        for (int i = 0; i < n; ++i) {
            nums[(i+k)%n] = nums2[i];
        }
    }
};

// 环状
class Solution {
public:
        void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
};