#input array is sorted
import heapq
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        result = []
        heap = []
        for i in arr:
            heapq.heappush(heap, [abs(i-x), i])
        for i in range(k):
            result.append(heapq.heappop(heap)[1])
        return sorted(result)
            
