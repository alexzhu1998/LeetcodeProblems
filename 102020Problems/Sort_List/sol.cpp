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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
//         merge sort the list
//         find the middle node
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* left = head;
        ListNode* right = slow->next;
        slow->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
    }
private:
    ListNode* merge(ListNode* L, ListNode* R) {
        if (!L) return R;
        if (!R) return L;
        ListNode* h = NULL;
        if (L->val < R->val) {
            h = L;
            h->next = merge(L->next,R);
        } else {
            h = R;
            h->next = merge(L,R->next);
        }
        return h;
    }
};

