from heapq import heappush, heappop
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists):
        if not lists and len(lists) == 0:
            return None

        heap = []
        dummy = ListNode(None)
        current = dummy
        for i in lists:
            heappush(heap, (i.val, i))
        while heap:
            pair = heappop(heap)
            current.next = pair[1]
            current = pair[1]
            if pair[1].next is not None:
                heappush(heap, (pair[1].next.val, pair[1].next))
        return dummy.next

arr = [0, 0, 0]
arr[0] = ListNode(1)
arr[0].next = ListNode(2)
#arr[0].next.next = ListNode(3)
arr[1] = ListNode(4)
arr[1].next = ListNode(5)
arr[1].next.next = ListNode(6)
arr[2] = ListNode(7)
arr[2].next = ListNode(8)
arr[2].next.next = ListNode(9)
ob = Solution()
cur = ob.mergeKLists(arr)
while cur:
    print(cur.val, end=" ")
    cur = cur.next
