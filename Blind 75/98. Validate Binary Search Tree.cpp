class Solution {
    
    bool isValidBST_rec(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) 
            return true;
        
        if((minNode && root->val <= minNode->val) or (maxNode && root->val >= maxNode->val))
            return false;

        return isValidBST_rec(root->left, minNode, root) and isValidBST_rec(root->right, root, maxNode);
    }

    ///////////////////////////////////////
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
    bool isValidBST_better(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
public:
    bool isValidBST(TreeNode* root) {
        // return isValidBST_rec(root, NULL, NULL);
        return isValidBST_better(root);
    }
};
