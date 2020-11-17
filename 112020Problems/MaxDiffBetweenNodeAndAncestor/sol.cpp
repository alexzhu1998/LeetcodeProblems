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
    int maxAncestorDiff(TreeNode* root) {
//         recursively trickle down to the 
        if (!root) return 0;
        int max_cur = INT_MIN;
        int min_cur = INT_MAX;
        
        return helper(root,min_cur,max_cur);
    }
private:
    int helper(TreeNode* root, int min_cur, int max_cur) {
        if (!root) {
            return (max_cur-min_cur);
        }
        if (root->val > max_cur) max_cur = root->val;
        if (root->val < min_cur) min_cur = root->val;
        
        int l = helper(root->left, min_cur, max_cur);
        int r = helper(root->right, min_cur, max_cur);
        return max(l,r);
    }
};