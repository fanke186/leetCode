#include <iostream>
#include <cstdio>
using namespace std;



//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (root == NULL) {
            return newNode;
        }
        TreeNode* cur = root;
        while (1){
            if(cur->val < val){
                if(cur->right == NULL){
                    cur->right = newNode;
                    break;
                }
                cur = cur->right;
            }

            if(cur->val > val){
                if(cur->left == NULL){
                    cur->left = newNode;
                    break;
                }
                cur = cur->left;
            }
        }
        return root;
    }
};