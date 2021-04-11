/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
// //         check if the tail node has next node
// //         see if there is a way to check if there is a tail node
//         if (!head || !head->next) return false;
//         unordered_set<ListNode*> s;
//         ListNode* cur = head;
//         while (cur) {
//             if (s.find(cur) == s.end()) {
//                 s.insert(cur);
//             } else {
//                 return true;
//             }
//             cur = cur->next;
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool hasCycle(ListNode *head) {
//         check if the tail node has next node
//         see if there is a way to check if there is a tail node
        if (!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            if (fast == slow) return true;
            slow = slow->next;
            fast = fast->next->next;
        } 
        
        return false;
    }
};
