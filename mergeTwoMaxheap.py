def swap(index1, index2, storage):
    temp = storage[index1]
    storage[index1] = storage[index2]
    storage[index2] = temp


def heapify(arr, n, i):
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
            swap(index, largestIndex, arr)
            index = largestIndex
            left = (2 * index) + 1
            right = (2 * index) + 2
def solve(first_array, second_array, n, m):
    result = []
    for i in first_array:
        result.append(i)
    for i in second_array:
        result.append(i)
    for i in range(len(result)//2-1, -1, -1):
        heapify(result, len(result), i)
    return result
if __name__ == "__main__":
    test_case = int(input())
    for _ in range(test_case):
        n, m = map(int, input().split())
        first_array = list(map(int, input().split()))
        second_array = list(map(int, input().split()))
    print(solve(first_array,second_array, n, m))