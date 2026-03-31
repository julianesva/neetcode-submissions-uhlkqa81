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
    void inverthorTree(TreeNode* root){
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = right;
        root->right = left;

        if(root->left)inverthorTree(root->left);
        if(root->right)inverthorTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;

        inverthorTree(root);

        return root;
        
    }
};
