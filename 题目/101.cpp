#include <iostream>
#include <vector>

using namespace std;

//***********
// 给定一棵二叉树，判断它是否是对称二叉树（包括结构和结点值）
//***********

 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool isS(TreeNode* l, TreeNode* r){
        // 左右都为空
        if (!l && !r)
            return true;
        // 左右其中一个为空
        if (!l || !r)
            return false;
        // 左右都不为空
        return (l->val == r->val && isS(l->left, r->right) && isS(l->right, r->left));
    }
    bool isSymmetric(TreeNode* root) {
        return isS(root, root);
    }
};