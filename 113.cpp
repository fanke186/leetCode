#include <vector>
#include <iostream>
using namespace std;

// 在二叉树中找到路径和为指定值的路径；
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    vector<vector<int>> a;
    vector<int> tempVec;
    int tempSum = 0;


    void findPath(TreeNode* t, int sum){
        if(t==nullptr)
            return;

        tempVec.push_back(t->val);
        tempSum += t->val;
        bool isLeave = (t->left==nullptr && t->right==nullptr);

        // 是叶子结点，且路径和符合要求
        if(isLeave && tempSum==sum)
            a.push_back(tempVec);
        // 如果左子树不为空
        if(t->left != nullptr)
            findPath(t->left, sum);
        // 如果右子树不为空
        if(t->right != nullptr)
            findPath(t->right, sum);
        
        tempVec.pop_back();
        tempSum -= t->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        findPath(root, sum);
        return a;
    }
};