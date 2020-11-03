#include <iostream>
#include <vector>

using namespace std;

// 新建一个数组, 其长度为n1+n1,
// 将nums1和nums2的合并结果存放到这个数组里面
// 时间O(n), 空间O(n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums(nums1.size() + nums2.size());
        int i = 0, j = 0, k = 0;
        // 双指针插入
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                nums[k] = nums1[i];
                i++;
                k++;
            } else {
                nums[k] = nums2[j];
                j++;
                k++;
            }
        }
        // 如果先把nums1的插完了
        if (i >= nums1.size()) {
            while (j < nums2.size()) {
                nums[k] = nums2[j];
                j++;
                k++;
            }
        } else {    // 如果先把nums2的插完了
            while (i < nums1.size()) {
                nums[k] = nums1[i];
                i++;
                k++;
            }
        }
        // 找中位数
        // 奇
        if (nums.size() % 2)
            return nums[nums.size() / 2];
        // 偶
        return (double)(nums[nums.size()/2 - 1] + nums[nums.size()/2]) / 2;
    }
};

// 不建立数组
// 时间O(n), 空间O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size() + nums2.size()) / 2;
        int i = 0, j = 0, k = 0;
        int m1 = 0, m2 = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                if (k == mid - 1) m1 = nums1[i];
                else if (k == mid) m2 = nums1[i];
                i++;
                k++;
            } else {
                if (k == mid - 1) m1 = nums2[j];
                if (k == mid) m2 = nums2[j];
                j++;
                k++;
            }
        }
        if (i >= nums1.size()) {
            while (j < nums2.size()) {
                if (k == mid - 1) m1 = nums2[j];
                if (k == mid) m2 = nums2[j];
                j++;
                k++;
            }
        } else {
            while (i < nums1.size()) {
                if (k == mid - 1) m1 = nums1[i];
                if (k == mid) m2 = nums1[i];
                i++;
                k++;
            }
        }
        cout << m1 << m2;
        if ((nums1.size() + nums2.size()) % 2)
            return m2;
        // 偶
        return (double)(m1 + m2) / 2;
    }
};

// 二分法
// 数组的中点取
class Solution {
public:
    // getK(nums1, nums2, k)
    // 返回这两个数组中第k小的元素值
    int getK(vector<int>& nums1, vector<int> nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0, j = 0;

        while (1) {
            // 边界
            // nums1全部被排除
            if (i == len1)
                return nums2[j + k - 1];
            // nums2全部被排除
            if (j == len2)
                return nums1[i + k - 1];
            // k减到1, 直接取当前两数组的最小值即可
            if (k == 1)
                return min(nums1[i], nums2[j]);

            // 循环
            // 取两个数组的中点, 取min防止数组越界
            int iNew = min(i + k/2 - 1, len1 - 1);
            int jNew = min(j + k/2 - 1, len2 - 1);
            // 截断中点小的那个数组
            // 更新：K -= 已被删除的个数
            if (nums1[iNew] <= nums2[jNew]) {
                k -= iNew - i + 1;
                i = iNew + 1;
            } else {
                k -= jNew - j + 1;
                j = jNew + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        // 奇数
        if (n % 2)
            return getK(nums1, nums2, n/2 + 1);
        // 偶数
        return (getK(nums1, nums2, n/2) + getK(nums1, nums2, n/2+1)) / 2.0;
    }
};


// 数组A, B, 长度分别记nA, nB, 总长度n = nA + nB
// 划分A为 Al, Ar, 二分, 下标记i
// 划分B为 Bl, Br, 二分, 下标记j
// left = Al U Bl, right = Ar U Br,
// 总长度n是奇数：
//      1.left的长度 = right的长度
//      2.left的max <= right的min
// 总长度n是偶数:
//      1.left的长度 = right的长度 + 1 
//      2.left的max <= right的min
// 解决:
//      1.i+j = (m+n+1)/2 -> j = (m+n+1)/2-i
//      2.max(A[i-1], B[j-1]) <= min(A[i], B[j])
//          ->A[i-1] <= B[j] && B[j-1] <= A[i]
// 转化为求：
//      最大的i, st: A[i-1] <= B[j]
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 让A成为较短的数组
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m, ansi = -1;
        // lMax表示左半部分的最大, rMin表示右半部分的最小
        int lMax = 0, rMin = 0;
        while (left <= right) {
            // 分别以下标i, j划分数组A, B
            // i由A的中点得到, j由划分后的左右半元素数量得到
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            // 依次表示A[i-1], A[i], B[j-1], B[j]
            // 越界处理：
            //      左边界:给一个最小值
            //      右边界:给一个最大值
            int nums_is1 = (i == 0?INT_MIN : nums1[i-1]);
            int nums_i = (i == m?INT_MAX : nums1[i]);
            int nums_js1 = (j == 0?INT_MIN : nums2[j-1]);
            int nums_j = (j == n?INT_MAX : nums2[j]);
            // A[i-1] <= B[j]
            if (nums_is1 <= nums_j) {
                ansi = i;
                lMax = max(nums_is1, nums_js1);
                rMin = min(nums_i, nums_j);
                left = i + 1;
            } else {
                right = i - 1;
            } 
        }
        // odd
        if ((m + n) % 2)
            return lMax;
        return (lMax + rMin) / 2.0;
    }
};
