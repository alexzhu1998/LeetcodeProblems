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
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int len = lists.size();
//         if (len == 0) return NULL;
//         if (len == 1 && lists[0] == NULL) return NULL;
// //         for each linked list
//         ListNode* res = lists[0];
        
//         for (int i = 1; i < len; i++) {
//             res = merge(res,lists[i]);
//         }
//         return res;
        
//     }
//     ListNode* merge(ListNode* &head1, ListNode* &head2) {
//         ListNode* res;
//         ListNode* c1 = head1;
//         ListNode* c2 = head2;
//         if (!head1) return head2;
//         if (!head2) return head1;
//         if (head1->val < head2->val) {
//             res = head1;
//             c1 = c1->next;
//         } else {
//             res = head2;
//             c2 = c2->next;
//         }
//         ListNode* reshead = res;
//         while (c1 && c2) {
//             if (c1->val < c2->val) {
//                 res->next = c1;
//                 c1 = c1->next;
//             } else {
//                 res->next = c2;
//                 c2 = c2->next;
//             }
//             res = res->next;
//         }
//         if (!c1) {
//             res->next = c2;
//         } else {
//             res->next = c1;
//         }
        
//         return reshead;
        
//     }
// };

class Solution {
public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};
