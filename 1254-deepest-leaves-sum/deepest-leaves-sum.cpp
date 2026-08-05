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
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        
        return 1+max(height(root->left),height(root->right));
    }

    int SumLeaf(TreeNode *root,int height){
        if(root==NULL)
            return 0;
        if(height==1)
            return root->val;
        
        return SumLeaf(root->left,height-1)+SumLeaf(root->right,height-1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int hgt=height(root);

        return SumLeaf(root,hgt);
    }
};