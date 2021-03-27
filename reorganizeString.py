import heapq
class Solution:
    def reorganizeString(self, S: str) -> str:
        lookup = {}
        result = ""
        for i in S:
            if i in lookup:
                lookup[i] += 1
            else:
                lookup[i] = 1
        heap = []
        for key, value in lookup.items():
            heapq.heappush(heap, [value*(-1), key])
        _max = abs(heap[0][0])
        if _max > len(S) - _max + 1:
            return " "
        else:
            while len(lookup) > 1:
                first = heapq.heappop(heap)
                second = heapq.heappop(heap)
                result += first[1]
                result += second[1]
                lookup[first[1]] -= 1
                lookup[second[1]] -= 1
                if lookup[first[1]] > 0:
                    heapq.heappush(heap, [lookup[first[1]]*(-1), first[1]])
                else:
                    lookup.pop(first[1])
                if lookup[second[1]] > 0:
                    heapq.heappush(heap, [lookup[second[1]]*(-1), second[1]])
                else:
                    lookup.pop(second[1])
            if len(lookup) == 1:
                item = lookup.popitem()
                result += item[0]

            return result

ob = Solution()
print(ob.reorganizeString("aab"))


