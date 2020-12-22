#include <vector>
#include <queue>
#include <deque>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {{}};

        int flag = 1; // 对每一层的vector，0表示正向，1表示反向
        vector<vector<int>> ret;
        vector<TreeNode*> curLayerNodes, nextLayerNodes;
        vector<int> nextLayerVals;
        ret.push_back(vector<int>(1, root->val));
        curLayerNodes.emplace_back(root);
        while (!curLayerNodes.empty()) {
            if (flag) { // 反向
                flag = 0;
                for (TreeNode* node : curLayerNodes) {
                    if (node->left != nullptr) {
                        nextLayerVals.insert(nextLayerVals.begin(), node->left->val);
                        nextLayerNodes.emplace_back(node->left);
                    }
                    if (node->right != nullptr) {
                        nextLayerVals.insert(nextLayerVals.begin(), node->right->val);
                        nextLayerNodes.emplace_back(node->right);
                    }
                }
            } else { // 正向
                flag = 1;
                for (TreeNode* node : curLayerNodes) {
                    if (node->left != nullptr) {
                        nextLayerVals.push_back(node->left->val);
                        nextLayerNodes.emplace_back(node->left);
                    }
                    if (node->right != nullptr) {
                        nextLayerVals.push_back(node->right->val);
                        nextLayerNodes.emplace_back(node->right);
                    }
                }
            }
            if(!nextLayerVals.empty()) ret.emplace_back(nextLayerVals);
            curLayerNodes.swap(nextLayerNodes);
            nextLayerNodes.clear();
            nextLayerVals.clear();
        }
        return ret;
    }
};


// 单个queue
// 效率其实是一样的
// deque 双端队列，在队列前后插入/删除的效率都是O(1)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        int flag = 1; // 对每一层的vector，1表示正向，0表示反向
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            deque<int> numList;
            int curLayerSize = q.size();
            for (int i = 0; i < curLayerSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (flag) {
                    numList.push_back(node->val);
                } else {
                    numList.push_front(node->val);
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ret.emplace_back(vector<int>{numList.begin(), numList.end()});
            flag = !flag;
        }
        return ret;
    }
};