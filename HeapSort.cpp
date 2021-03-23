#include <iostream>
using namespace std;
class Solution {
public:
	void swap(int index1, int index2, int arr[]) {
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	void heapify(int arr[], int n, int i) {
		// Your Code Here
		int index = i;
		int left = (2 * index) + 1;
		int right = (2 * index) + 2;
		while (left < n) {
			int largestIndex = left;
			if (right < n and arr[right] > arr[largestIndex]) {
				largestIndex = right;
			}
			if (arr[index] > arr[largestIndex]) {
				break;
			}
			else
				swap(index, largestIndex, arr);
				index = largestIndex;
				left = (2 * index) + 1;
				right = (2 * index) + 2;
		}
		
	}
	void buildHeap(int arr[], int n) {
		// Your Code Here
		for (int i = n / 2 - 1; i >= 0; i--) {
			heapify(arr, n, i);
		}
		
	}
	void heapSort(int arr[], int n)
	{
		//code here
		buildHeap(arr, n);
		for (int i = n - 1; i >= 1; i--) {
			swap(0, i, arr);
			n = n - 1;
			heapify(arr, n, 0);
		}
		/*for (int j = 0; j < 7; j++) {
			cout << arr[j] << " ";
		}*/
	}
};
int main() {
	int arr[] = { 15, 5, 20, 1, 17, 10, 30 };
	Solution obj;
	obj.heapSort(arr, 7);
	
}