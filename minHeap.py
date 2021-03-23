class MinHeap:
    def __init__(self, capacity):
        self.storage = [0] * capacity
        self.capacity = capacity
        self.size = 0

    def getParentInd(self, index):
        return (index - 1) // 2

    def getLeftChildInd(self, index):
        return 2*index + 1

    def getRightChildInd(self, index):
        return 2 * index + 2

    def hasParent(self, index):
        return self.getParentInd(index) >= 0

    def hasLeftChild(self, index):
        return self.getLeftChildInd(index) < self.size

    def hasRightChild(self, index):
        return self.getRightChildInd(index) < self.size

    def isFull(self):
        return self.size == self.capacity

    def swap(self, index1, index2):
        temp = self.storage[index1]
        self.storage[index1] = self.storage[index2]
        self.storage[index2] = temp

    def insert(self, data):
        if self.isFull():
            print("heap is full")
        self.storage[self.size] = data
        self.size += 1
        self.heapifyUp()
    def recursive_insert(self, data):
        if self.isFull():
            print("heap is full")
        self.storage[self.size] = data
        self.size += 1
        self.recursiveHeapifyUp(self.size - 1)

    def heapifyUp(self):
        index = self.size - 1
        while self.hasParent(index) and self.storage[self.getParentInd(index)] > self.storage[index]:
            self.swap(self.getParentInd(index), index)
            index = self.getParentInd(index)

    def recursiveHeapifyUp(self, index):
        if self.hasParent(index) and self.storage[self.getParentInd(index)] > self.storage[index]:
            self.swap(self.getParentInd(index), index)
            self.recursiveHeapifyUp(self.getParentInd(index))

    def remove(self):
        if self.size == 0:
            print("heap is empty")
        data = self.storage[0]
        self.storage[0] = self.storage[self.size - 1]
        self.storage[self.size - 1] = 0
        self.size -= 1
        self.heapifyDown()
        return data

    def recursive_remove(self):
        if self.size == 0:
            print("heap is empty")
        data = self.storage[0]
        self.storage[0] = self.storage[self.size - 1]
        self.storage[self.size - 1] = 0
        self.size -= 1
        self.recursive_heapifyDown(0)
        return data
    def heapifyDown(self):
        index = 0
        while self.hasLeftChild(index):
            smallerChildIndex = self.getLeftChildInd(index)
            if self.hasRightChild(index) and self.storage[self.getRightChildInd(index)] < self.storage[smallerChildIndex]:
                smallerChildIndex = self.getRightChildInd(index)
            if self.storage[index] < self.storage[smallerChildIndex]:
                break
            else:
                self.swap(index, smallerChildIndex)
            index = smallerChildIndex

    def recursive_heapifyDown(self, index):
        if self.hasLeftChild(index):
            smallerChildIndex = self.getLeftChildInd(index)
            if self.hasRightChild(index) and self.storage[self.getRightChildInd(index)] < self.storage[smallerChildIndex]:
                smallerChildIndex = self.getRightChildInd(index)
            if self.storage[index] < self.storage[smallerChildIndex]:
                return
            else:
                self.swap(index, smallerChildIndex)
            index = smallerChildIndex
            self.recursive_heapifyDown(index)


ob = MinHeap(5)
ob.insert(5)
ob.insert(3)
ob.insert(6)
print(ob.storage)