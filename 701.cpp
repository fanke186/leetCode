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
        // 新结点
        TreeNode* newNode = new TreeNode(val);
        // 空树插入
        if (root == NULL) {
            return newNode;
        }
        TreeNode* cur = root;
        while (1){
            // 应插入当前结点的右子树
            if(cur->val < val){
                if(cur->right == NULL){
                    cur->right = newNode;
                    break;
                }
                cur = cur->right;
            }
            // 应插入当前结点的左子树
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