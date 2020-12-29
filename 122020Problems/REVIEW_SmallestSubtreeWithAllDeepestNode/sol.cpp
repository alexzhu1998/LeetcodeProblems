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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         if (root == NULL) return NULL;
         int left = getDepth(root->left);
         int right = getDepth(root->right);
        if (left == right) return root;
        else if (left > right) return subtreeWithAllDeepest(root->left);
        else return subtreeWithAllDeepest(root->right);
    }
    
private :
     int getDepth(TreeNode* node)
     {
         if (node == NULL) return 0;
         return 1 + std::max(getDepth(node->left),getDepth(node->right));
     }
};
// class Solution {
// public:
//     TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//         Queue<TreeNode*> q;
//         TreeNode* curr = root;
//         q.push_back(curr);
//         while (!q.empty()) {
//             curr = q.pop_front();
            
//             q.push_back(curr->left);
//             q.push_back(curr->right);
//         }
//         int depth = depth(root);
        
        
//     }
    
//     int depth(TreeNode*root) {
//         if(!root) return 0;
//         return 1+ max(depth(root->left),depth(root->right));
//     }
    
//     TreeNode* checkDeepest(TreeNode* root, int depth) {
//         if (root == NULL) return NULL;
//         if (depth == 0) {
//             return root;
            
//         } else {
//             return 
//         }
//     }
// };
