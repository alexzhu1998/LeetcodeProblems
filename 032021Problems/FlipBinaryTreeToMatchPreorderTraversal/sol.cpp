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
    vector<int> res;
    int i = 0;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
//         dfs down the roots, if root->left != voyage[i], swap with root->right
//         it should equal, otherwise return -1.
        
        if (dfs(root,voyage)) {
            return res;
        } else {
            return vector<int>{-1};
        }
    }
    
    bool dfs(TreeNode* cur, vector<int>& v) {
        if (!cur) return true;
        
        if (cur->val != v[i++]) return false;
        if (cur->left && cur->left->val != v[i]) {
            res.push_back(cur->val);
            return dfs(cur->right,v) && dfs(cur->left,v);
        }
        return dfs(cur->left,v) && dfs(cur->right,v);
            
    }
};
