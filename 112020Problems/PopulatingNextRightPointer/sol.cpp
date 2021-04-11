/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
//         store each node into a queue
        Node* curr = root;
        int level = 0;
//         build a queue
        deque<tuple<Node *,int>> q;
        
//         start by adding the root
        q.push_back({root,level});
        
        while (!q.empty()) {
            Node* curr = get<0>(q.front());
            int currLevel = get<1>(q.front());
            q.pop_front();
//             do stuff with curr node
            if (get<1>(q.front()) == currLevel) {
                curr->next = get<0>(q.front());    
            } else {
                curr->next = NULL;
            }
            
//             iterate through the tree
            if (curr->left) q.push_back({curr->left,currLevel +1});
            if (curr->right) q.push_back({curr->right,currLevel +1});
        }
//         printing level Order
        // printLevelOrder(root);
        return root;
    }
    // ######### Print level order Using Height of BST
    // void printLevelOrder(Node* root, int level) {
    //     if (root == NULL || level == 0) return;
    //     if (level == 1) {
    //         std::cout << root->val << std::endl;
    //     } else {
    //         printLevelOrder(root->left,level -1);
    //         printLevelOrder(root->right,level - 1);
    //     }
    // }
    // ######### Print level order Using queues
//     void printLevelOrder(Node* root) {
//         deque<Node *> q;
//         q.push_back(root);
        
//         while (!q.empty()) {
//             Node* curr = q.front();
//             std::cout << curr->val << std::endl;
//             q.pop_front();
            
//             if (curr->left) q.push_back(curr->left);
//             if (curr->right) q.push_back(curr->right);
//         }
//     }
};


// class Solution {
// public:
//     Node* connect(Node* root) {
//         if (root == nullptr) {
//             return nullptr;
//         }
//         dfs(root->left, root->right, root);
//         return root;
//     }
    
//     void dfs(Node* left, Node* right, Node* root) {
//         if (!(left && right)) {
//             return;
//         }
//         left->next = right;
//         if (root->next) {
//             right->next = root->next->left;
//         }
//         dfs(left->left, left->right, left);
//         dfs(right->left, right->right, right);
//     }
// };