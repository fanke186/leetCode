#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// **********
// 两数之和
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
// **********



/*
// map 在插入后是会严格按照key的大小顺序存储的；
// unordered_map 则是依照插入顺序；
// auto 关键字是让变量通过初始化定义来自动识别数据类型，可以用来简化代码；
*/




/*
// O(n**2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    a.push_back(i);
                    a.push_back(j);
                }
            }
        }
        return a;
    }
};
*/


// O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapNum;
        for (int i = 0; i < nums.size(); i++){
            auto it = mapNum.find(target - nums[i]);
            // 补数存在 hashmap 中，直接返回
            if (it != mapNum.end())
                return {it->second, i};
            // 补数不在 hashmap 中，插入；
            mapNum[nums[i]] = i;
        }
        return {};
    }
};