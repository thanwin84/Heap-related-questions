import heapq
class Solution:
    def __init__(self):
        self.storage = []
        self.result = []
    def merge(self, numbers):
        for i in range(len(numbers)):
            heapq.heappush(self.storage, [numbers[i][0], i, 0])
        while self.storage:
            pair = heapq.heappop(self.storage)
            self.result.append(pair[0])
            pair[2] += 1
            if pair[2] < len(numbers[pair[1]]):
                heapq.heappush(self.storage, [numbers[pair[1]][pair[2]], pair[1], pair[2]])
        return self.result