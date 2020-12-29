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
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> visited(10,0);
        int total = 0;
        dfs(root,visited,total);
        return total;
    }
    
    void dfs(TreeNode* cur, vector<int> & visited, int &total) {
        if (!cur) return;
        visited[cur->val]++;
        if (cur->left == NULL && cur->right == NULL) {
            int numOfPal = 0;
            for (int i = 0; i < visited.size(); i++) {
                if (visited[i]%2) numOfPal++;
                // cout<< visited[i] << " ";
            }
            // cout<<endl;
            if (numOfPal <= 1) total++;

        }
        dfs(cur->left,visited,total);
        dfs(cur->right,visited,total);
        visited[cur->val]--;
    }
};
