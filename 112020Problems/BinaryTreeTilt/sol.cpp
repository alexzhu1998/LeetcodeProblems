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
    int findTilt(TreeNode* root) {
        int sum = 0;
        s(root, sum);
        return sum;
        
    }
private:
    int s(TreeNode* root,int& sum) {
//         collect sum of left subtrees, sum of right subtrees
        if (!root) return 0;
        int left = s(root->left, sum);
        // std::cout<<sum<<std::endl;
        int right = s(root->right,sum);
        // std::cout<<sum<<std::endl;
        sum += abs(left-right);
        // std::cout<<sum<<std::endl;
        return left+right+root->val;
    }
};