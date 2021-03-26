class Solution:
    def solve(self, nums, k):
        lookup = {}
        heap = []
        result = []
        for i in nums:
            if i in lookup:
                lookup[i] += 1
            else:
                lookup[i] = 1
        for key, frequency in lookup.items():
            heap.append([frequency, key])
        for i in range(len(heap)//2-1, -1, -1):
            self.heapify(heap, len(heap), i)
        n = len(heap)
        for i in range(k):
            result.append(heap[0][1])
            self.swap(0, n-1, heap)
            heap.pop()
            n = n -1
            self.heapify(heap, n, 0)
        return result

    def swap(self, index1, index2, storage):
        temp = storage[index1]
        storage[index1] = storage[index2]
        storage[index2] = temp

    def heapify(self, arr, n, i):
        index = i
        left = (2 * index) + 1
        right = (2 * index) + 2
        while left < n:
            largestIndex = left
            if right < n and arr[right][0] > arr[largestIndex][0]:
                largestIndex = right
            if arr[index][0] > arr[largestIndex][0]:
                break
            else:
                self.swap(index, largestIndex, arr)
                index = largestIndex
                left = (2 * index) + 1
                right = (2 * index) + 2
nums = [1, 1, 1, 2, 2, 3]
k = 2
ob = Solution()
print(ob.solve([1], 1))
