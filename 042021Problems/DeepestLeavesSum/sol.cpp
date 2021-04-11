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
    
    int deepestLeavesSum(TreeNode* root) {
        int deep = depth(root,0);
        // cout << deep <<endl;
        int sum = 0;
        dfs(root,deep,sum);
        return sum;
    }
    void dfs(TreeNode* root, int deep, int& sum) {
        if (!root) return;
        // cout << root->val <<" " << deep<< endl;
        if (deep == 1) {
            sum += root->val;
        } else {
            dfs(root->left,deep-1,sum);
            dfs(root->right,deep-1,sum);
        }
        
    }
    
    int depth(TreeNode* root, int level) {
        if (!root) return level;
        int left = depth(root->left,level+1);
        int right = depth(root->right, level+1);
        
        return max(left,right);
        
    }
};
