import array 
import bisect
import collections 

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        if head.next == None:
            return head
        if head.next.next == None:
            return head
        ptr1 = head
        ptr2 = head.next
        ptr3 = head.next.next
        
        while ptr3 != None:
            temp = ptr1.next
            ptr1.next = ptr3
            ptr2.next = ptr3.next
            ptr3.next = temp
            
            ptr1 = ptr1.next
            ptr2 = ptr2.next
            if ptr2:
                ptr3 = ptr2.next
            else:
                ptr3 = None
            
        return head

if __name__ == "__main__":
    with open("input.txt", "r") as f:
        lstr = f.readline().strip("[").strip("]")
    l = lstr.split(",")

    assert(l != [])
    curPtr = ListNode(int(l[0]),None)
    head = curPtr
    prevPtr = curPtr
    curPtr = curPtr.next
    for i in range(1,len(l)):
        curPtr = ListNode(int(l[i]),None)
        prevPtr.next = curPtr

        prevPtr = curPtr
        curPtr = curPtr.next
    
    sol = Solution()
    newhead = sol.oddEvenList(head)
    ptr = newhead
    while ptr != None:
        print(ptr.val)
        ptr = ptr.next