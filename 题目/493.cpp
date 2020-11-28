#include <vector>

using namespace std;


// 分治法  归并排序
// 子问题：求数组[left, right]的重要翻转对
// 分解：将待求解数组[left, right]由mid分为两部分，
//      重要翻转对有三种情况,一是ij都在左半,二是ij都在右半,三是i在左半j在右半。
// 合并：原问题的解等于两个子问题的解之和再加上情况三。
//
// 还有两个问题,一是如何求解这两个子问题,二是如何高效地求解“情况三”
// 一、子问题的解可以通过递归得到,递归边界是子数组只有一个数字；
// 二、求解“情况三”：如果直接枚举计算,完成所有递归,时间是O(n^2)；
//      若[left, mid]和[mid+1, right]分别是有序的,用ij分别维护下标。
//      给定下标i,不断向右移动j直到 nums[i] <= 2*nums[j]，
//      意味着当前i在右子数组有前j-mid-1个右端点满足条件。
//      注意：下标j是不回溯的,因为两个子数组都是有序的,若i有右子数组前j-mid-1个右端点满足条件
//            那么nums[i+1]也拥有必定有这j-mid-1个满足条件的右端点。
//      然后向右移动i,用相同的方法不断计算满足条件的右端点个数,这样就能求出所有左右端点分别位于两个子数组的解。
//
// 注意：完成当前子问题求解后要维持数组的有序，
//      即将[left, mid]有序且[mid+1, right]有序，变成[left, right]有序，以便后续的计算。
class Solution {
public:
    // 合并前[left, mid]有序,[mid+1, right]有序
    // 合并后[left, right]有序
    void merge(vector<int>& nums, int left, int right) {
        int mid = (left + right) / 2;
        int sorted[right - left + 1];
        int p1 = left, p2 = mid + 1;
        int cur = 0;
        while (p1 <= mid && p2 <= right) {
            if (nums[p1] <= nums[p2]) {
                sorted[cur++] = nums[p1++];
            } else {
                sorted[cur++] = nums[p2++];
            }
        }
        for (; p1 <= mid; p1++)
            sorted[cur++] = nums[p1];
        for (; p2 <= right; p2++)
            sorted[cur++] = nums[p2];
        for (int i = left; i <= right; i++) {
            nums[i] = sorted[i-left];
        }
    }
    
    int find_rPairs(vector<int>& nums, int left, int right) {
        // 递归边界
        if (left == right)
            return 0;
        // 子问题的解 = l + r + case3;
        int mid = (left + right) / 2;
        int l = find_rPairs(nums, left, mid);
        int r = find_rPairs(nums, mid+1, right);
        int ret = l + r;

        // 求解情况3
        int i = left;
        int j = mid + 1; // j不回溯，利用排序：时间n^2-->nlogn
        while (i <= mid) {
                while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) 
                    j++;
                ret += (j - mid - 1);
                i++;
        }
        // 维持数组的有序，以后后续的计算
        merge(nums, left, right);
        return ret;
    }
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        return find_rPairs(nums, 0, nums.size()-1);
    }
};