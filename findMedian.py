from heapq import heappush, heappop
# smaller item should go to max_heap
# larger item should go to min_heap
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.count = 0
        self.median = 0
        self.max_heap = []
        self.min_heap = []

    def addNum(self, num: int) -> None:
        if self.count % 2 ==0:
            if len(self.max_heap) == 0:
                heappush(self.max_heap, num*(-1))
                self.median = num
                self.count += 1
            elif self.min_heap[0] > num:
                heappush(self.max_heap, num*(-1))
                if self.max_heap[0] < 0:
                    self.median = abs(self.max_heap[0])
                else:
                    self.median = self.max_heap[0] * (-1)
                self.count += 1
            else:
                poped_item = heappop(self.min_heap)
                heappush(self.max_heap, poped_item*(-1))
                heappush(self.min_heap, num)
                self.count += 1
                if self.max_heap[0] < 0:
                    self.median = abs(self.max_heap[0])
                else:
                    self.median = self.max_heap[0] * (-1)
        elif self.count % 2 != 0:
            if self.max_heap[0] < 0:
                max_top = abs(self.max_heap[0])
            else:
                max_top = self.max_heap[0] * (-1)
            if max_top > num:
                poped_item = heappop(self.max_heap)
                if poped_item > 0:
                    poped_item = poped_item *(-1)
                else:
                    poped_item = abs(poped_item)
                heappush(self.min_heap, poped_item)
                heappush(self.max_heap, num*(-1))
                if self.max_heap[0] < 0:
                    max_top = abs(self.max_heap[0])
                else:
                    max_top = self.max_heap[0] *(-1)
                self.median = (max_top + self.min_heap[0]) / 2
                self.count += 1
            else:
                heappush(self.min_heap, num)
                if self.max_heap[0] < 0:
                    max_top = abs(self.max_heap[0])
                else:
                    max_top = self.max_heap[0] *(-1)
                self.median = (max_top + self.min_heap[0]) / 2
                self.count += 1





    def findMedian(self) -> float:
        return self.median
ob = MedianFinder()
ob.addNum(3)
print(ob.findMedian())
ob.addNum(5)
print(ob.findMedian())
print(ob.max_heap, ob.min_heap)
ob.addNum(4)
print(ob.findMedian())
print(ob.max_heap, ob.min_heap)
ob.addNum(2)
print(ob.findMedian())
print(ob.max_heap, ob.min_heap)
ob.addNum(6)
print(ob.findMedian())
print(ob.max_heap, ob.min_heap)
