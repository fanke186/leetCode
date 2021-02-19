#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0, sumB = 0, half;
        for (int it : A) {
            sumA += it;
        }
        for (int it : B) {
            sumB += it;
        }
        half = (sumA + sumB) / 2;
        for (int i : A) {
            for (int j : B) {
                if (sumA - i + j == half) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> map;
        int sumA = 0, sumB = 0, half;
        for (int it : A) {
            sumA += it;
        }
        for (int it : B) {
            sumB += it;
        }
        half = (sumA + sumB) / 2;
        for (int i : A) {
            map.emplace(pair<int, int>(half - i, i));
        }
        for (int j : B) {
            if (map.count(j)) {
                return {map.at(j), j};
            }
        }
        return {};
    }
};