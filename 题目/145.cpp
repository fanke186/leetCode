#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// *********
// 给定一个二叉树，返回它的 后序 遍历。
// *********




// 给定二叉树，返回它的后序遍历；
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// 递归写法
// class Solution {
// public:
//     void postOrder(TreeNode* t, vector<int>* a){
//         if(t == nullptr) return;
//         if(t->left) postOrder(t->left, a);
//         if(t->right) postOrder(t->right, a);
//         a->push_back(t->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> a;
//         postOrder(root, &a);
//         return a;
//     }
// };

// 非递归写法
class Solution{
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> a;
        TreeNode* cur;
        if(root != nullptr) s.push(root);
        while(!s.empty()){
            cur = s.top();
            s.pop();
            if(cur->left) s.push(cur->left);
            if(cur->right) s.push(cur->right);
            a.push_back(cur->val);
        }
        reverse(a.begin(), a.end());
        return a;
    }
};