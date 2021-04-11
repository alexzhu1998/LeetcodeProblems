/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         recursion
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA) {
            curA->val = -curA->val;
            curA = curA->next;
        }
        ListNode *res;
        while (curB) {
            if (curB->val < 0) {
                res = curB;
                break;
            }
            curB->val = -curB->val;
            curB = curB->next;
        }
        
        while (headA) {
            if (headA->val < 0) {
                headA->val = -headA->val;
            }
            headA = headA->next;
        }
        
        while (headB) {
            if (headB->val < 0) {
                headB->val = -headB->val;
            }
            headB = headB->next;
        }
        
        return res;
        
    }
};

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *curA = headA;
//         ListNode *curB = headB;
//         while(curA!=curB)
//         {
//             if(curA != NULL)
//                 curA = curA->next;
//             else
//                 curA = headB;
            
//             if(curB != NULL)
//                 curB = curB->next;
//             else
//                 curB = headA;
//         }
//         return curA;
//     }
// };
