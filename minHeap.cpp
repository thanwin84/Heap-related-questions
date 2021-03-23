#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MinHeap {
public:
	int Capacity;
	vector<int> storage;
	int size = 0;
	MinHeap(int Capacity) {
		this->Capacity = Capacity;
		storage.resize(Capacity);
	}

	double getParentIndex(int index) {
		return (index - 1) / 2.0;
	}
	int getLeftChildIndex(int index) {
		return 2 * index + 1;
	}
	int getRightChildIndex(int index) {
		return 2 * index + 2;
	}
	bool hasParent(int index) {
		return getParentIndex(index) >= 0;
	}
	bool hasLeftChild(int index) {
		return getLeftChildIndex(index) < size;
	}
	bool hasRightChild(int index) {
		return getRightChildIndex(index) > size;
	}
	bool isFull() {
		return storage.size() == size;
	}
	void swap(int index1, int index2, vector<int> &li) {
		int temp = li[index1];
		li[index1] = li[index2];
		li[index2] = temp;

	}
	void insert(int data) {
		if (isFull()) {
			cout << "heap is full" << endl;
		}
		storage[size] = data;
		size += 1;
		heapifyUp();
	}
	void recursive_insert(int data) {
		if (isFull()) {
			cout << "heap is full" << endl;
		}
		storage[size] = data;
		size += 1;
		recursive_heapifyUp(size-1);
	}
	void recursive_heapifyUp(int index) {
		if (hasParent(index) and storage[getParentIndex(index)] > storage[index]) {
			swap(getParentIndex(index), index, storage);
			recursive_heapifyUp(index);
		}
	}
	void heapifyUp() {
		int index = size - 1;
		while (hasParent(index) and storage[getParentIndex(index)] > storage[index]) {
			swap(getParentIndex(index), index, storage);
		}
	}
	int remove() {
		int data = storage[0];
		storage[0] = storage[size - 1];
		storage[size - 1] = 0;
		size -= 1;
		heapifyDown();
		return data;

	}
	int recursive_remove() {
		int data = storage[0];
		storage[0] = storage[size - 1];
		storage[size - 1] = 0;
		size -= 1;
		recursive_heapifyDown(0);
		return data;

	}
	void recursive_heapifyDown(int index) {
		if (hasLeftChild(index)) {
			int smallerIndex = getLeftChildIndex(index);
			if (hasRightChild(index) and storage[getRightChildIndex(index)] < storage[smallerIndex]) {
				smallerIndex = getRightChildIndex(index);
			}
			if (storage[index] < storage[smallerIndex]) {
				return;
			}
			else
				swap(index, smallerIndex, storage);
			recursive_heapifyDown(smallerIndex);
		}
	}
	void heapifyDown() {
		int index = 0;
		while (hasLeftChild(index)) {
			int smallerIndex = getLeftChildIndex(index);
			if (hasRightChild(index) and storage[getRightChildIndex(index)] < storage[smallerIndex]) {
				smallerIndex = getRightChildIndex(index);
			}
			if (storage[index] < storage[smallerIndex]) {
				break;
			}
			else
				swap(index, smallerIndex, storage);
			index = smallerIndex;
		}
	}
};
int main() {
	MinHeap heap(5);
	heap.recursive_insert(5);
	heap.recursive_insert(3);
	heap.recursive_insert(6);
	heap.recursive_remove();
	for (int i = 0; i < heap.storage.size(); i++) {
		cout << heap.storage[i] << '\t';
	}
	
	
	return 0;
}