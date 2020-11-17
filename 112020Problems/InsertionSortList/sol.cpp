/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode* tail = head, *curr, *iter;
        while (tail->next) {
            
            if (tail->val <= tail->next->val) {
                tail = tail->next;
                continue;
            }
            //take one node
            curr = tail->next;
            tail->next = curr->next;
            //check if head is less
            if (head->val > curr->val) {
                curr->next = head;
                head = curr;
                continue;
            }
            
            // all other cases
            iter = head;
            while (iter != tail) {
                if (iter->next->val > curr->val) {
                    curr->next = iter->next;
                    iter->next = curr;
                    break;
                }
                iter = iter->next;
            }
            
            
        }
        return head;
//         Dont use this because this has a problem with the last pointer
//         ListNode* newLhead = NULL;
//         ListNode* newNode;
//         ListNode* curr;
//         ListNode* prev;
//         bool match = 0;
//         while (head) {
//             newNode = head;
//             head = head->next;
//             if (!newLhead) {
//                 newLhead = newNode;
//                 match = 1;
//             } else {
//                 std::cout << newLhead->val << std::endl;
//                 std::cout << newNode->val << std::endl;
//                 if (newLhead->val > newNode->val) {
//                     newNode->next = newLhead;
//                     newLhead = newNode;
//                 }
                
// //                     newNode->next = newLhead;
// //                     newLhead = newNode;
// //                     match = 1;
// //                 } else {
// //                 //     curr = newLhead;
// //                 //     prev = curr;
// //                     // while (curr && curr->next) {
// //                     //     if (prev->val < newNode->val && curr->val > newNode->val) {
// //                     //         prev->next = newNode;
// //                     //         newNode->next = curr;
// //                     //         match = 1;
// //                     //         break;
// //                     //     }
// //                     //     prev = curr;
// //                     //     curr = curr->next;
// //                     // }
                    
// //                     // if (curr && (curr->next == NULL) && (match == 0)) {
// //                     //     curr->next = newNode;
// //                     //     newNode->next = NULL;
// //                     // }
// //                 }
//             }
                
//         }
//         while (newNode) {
//             ListNode* tmp = newNode;
//             newNode = newNode->next;
//             delete tmp;
//         }
//         return newLhead;
    }
};
