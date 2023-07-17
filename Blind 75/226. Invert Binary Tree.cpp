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
public:
    /********approach 1******/
    // time: O(number of nodes)
   TreeNode* invertTreeItr(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
   }
    
    /**********approach-2*********/
    // time: O(number of nodes)
    TreeNode* invertTreeRec(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        
        while(st.size()) {
            TreeNode *top = st.top(); st.pop();
            if(!top) continue;
            st.push(top->left);
            st.push(top->right);
            swap(top->left, top->right);
        }
        return root;
    }
    
    /**********approach 3**********/
    TreeNode* invertTree_(TreeNode* root) {
        TreeNode *temp;
        return root ? (temp = invertTree_(root->left), root->left = invertTree_(root->right), root->right = temp, root):root;
        // it says if root then swap tree->left, tree->right and return root else return root
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return invertTree_(root);
    }
};
