class MaxHeap:
    def __init__(self, capacity):
        self.capacity = capacity
        self.storage = [0] * capacity
        self.size = 0
    def getParentInd(self, index):
        return (index - 1) // 2

    def getLeftChildInd(self, index):
        return 2 * index + 1

    def getRightChildInd(self, index):
        return 2 * index + 2

    def hasParent(self, index):
        return self.getParentInd(index) >= 0

    def hasLeftChild(self, index):
        return self.getLeftChildInd(index) < self.size

    def hasRightChild(self, index):
        return self.getRightChildInd(index) < self.size

    def isFull(self):
        return self.size == len(self.storage)

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
        self.recursive_heapifyUp(self.size - 1)

    def recursive_heapifyUp(self, index):
        if self.hasParent(index) and self.storage[self.getParentInd(index)] < self.storage[index]:
            self.swap(self.getParentInd(index), index)
            index = self.getParentInd(index)
            self.recursive_heapifyUp(index)

    def remove(self):
        data = self.storage[0]
        self.storage[0] = self.storage[self.size -1]
        self.storage[self.size - 1] = 0
        self.size -= 1
        self.heapifyDown()

    def recursive_remove(self):
        data = self.storage[0]
        self.storage[0] = self.storage[self.size -1]
        self.storage[self.size - 1] = 0
        self.size -= 1
        self.recursive_heapifyDown(0)

    def recursive_heapifyDown(self, index):
        if self.hasLeftChild(index):
            largerChildIndex = self.getLeftChildInd(index)
            if self.hasRightChild(index) and self.storage[self.getRightChildInd(index)] > self.storage[largerChildIndex]:
                largerChildIndex = self.getRightChildInd(index)
            if self.storage[index] > self.storage[largerChildIndex]:
                return
            else:
                self.swap(index, largerChildIndex)
            index = largerChildIndex
            self.recursive_heapifyDown(index)

    def heapifyDown(self):
        index = 0
        while self.hasLeftChild(index):
            largerChildIndex = self.getLeftChildInd(index)
            if self.hasRightChild(index) and self.storage[self.getRightChildInd(index)] > self.storage[largerChildIndex]:
                largerChildIndex = self.getRightChildInd(index)
            if self.storage[index] > self.storage[largerChildIndex]:
                break
            else:
                self.swap(index, largerChildIndex)
            index = largerChildIndex


ob = MaxHeap(5)
ob.recursive_insert(10)
ob.recursive_insert(30)
ob.recursive_insert(50)
ob.recursive_insert(60)
ob.recursive_insert(100)

print(ob.storage)