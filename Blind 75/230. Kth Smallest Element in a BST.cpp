/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // approach-1
    void inorder(TreeNode* root, int &k, int &kth_small_node) {
        if(!root)
           return;

       inorder(root->left, k, kth_small_node);
       k--;
       if(k == 0) {
           kth_small_node = root->val;
           return;
       }
       inorder(root->right, k, kth_small_node);
    }
    int kthSmallest_(TreeNode* root, int k) {
        int kth_small_node = 0;
        inorder(root, k, kth_small_node);
        return kth_small_node;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallest_(root, k);
    }
};
