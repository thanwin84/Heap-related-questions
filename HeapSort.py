class Solution:
    def swap(self, index1, index2, storage):
        temp = storage[index1]
        storage[index1] = storage[index2]
        storage[index2] = temp

    def heapify(self, arr, n, i):
        '''
        :param arr: original array
        :param n: size of original array
        :param i: subtree rooted at ith index
        :return:
        '''
        index = i
        left = (2 * index) + 1
        right = (2 * index) + 2
        parernt = (index - 1) / 2
        while left < n:
            largestIndex = left
            if right < n and arr[right] > arr[largestIndex]:
                largestIndex = right
            if arr[index] > arr[largestIndex]:
                break
            else:
                self.swap(index, largestIndex, arr)
                index = largestIndex
                left = (2 * index) + 1
                right = (2 * index) + 2

    def buildHeap(self, arr, n):
        '''
        :param arr: given array
        :param n: size of array
        :return: None
        '''
        for i in range(len(arr)//2 - 1, -1, -1):
            self.heapify(arr, n, i)
        return arr

    def HeapSort(self, arr, n):
        self.buildHeap(arr, n)
        for i in range(n -1, 0, -1):
            self.swap(0, i, arr)
            n = n- 1
            self.heapify(arr, n, 0)
        return arr
ob = Solution()
arr = ob.buildHeap([15, 5, 20, 1, 17, 10, 30], 7)
print(ob.HeapSort(arr, 7))

