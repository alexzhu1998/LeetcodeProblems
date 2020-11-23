/**
  * Definition for a binary tree node->
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
        map<TreeNode*,int> m;
        int rob(TreeNode* root) {
            //         for each treenode, find the root
            m[NULL] = 0;
            
            if (m.find(root) != m.end()) return m[root];
            int val = 0;
            if (root->left) val += rob(root->left->left) + rob(root->left->right);
            if (root->right) val += rob(root->right->left) + rob(root->right->right);
            
            m[root] = max(val+ root->val, rob(root->left)+rob(root->right));
            return m[root];
        }
    
};

// very simple and elegant solution no memo
// class Solution {
// public:
//     int rob(TreeNode* root) {
//         if(root == nullptr) return 0;
        
//         int l=0;
//         int r =0;
//         return tryrob(root, l, r);
//     }
    
//     int tryrob(TreeNode* node, int& l, int& r)
//     {
//         if(node == nullptr) return 0;
        
//         int ll=0,rr=0,lr=0,rl =0;
//         l = tryrob(node->left, ll, lr);
//         r = tryrob(node->right, rl, rr);
        
//         return max(node->val + ll+lr+rl+rr, l+r);
//     }
// };