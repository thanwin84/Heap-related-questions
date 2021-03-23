
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void swap(int index1, int index2, int arr[]) {
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
	void heapify(int arr[], int n, int i) {
		int index = i;
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		while (left < n) {
			int smallestIndex = left;
			if (right < n and arr[right] < arr[smallestIndex]) {
				smallestIndex = right;
			}
			if (arr[index] < arr[smallestIndex]) {
				break;
			}
			else
				swap(index, smallestIndex, arr);
			index = smallestIndex;
			left = 2 * index + 1;
			right = 2 * index + 2;
		}
	}
	int kthSmallest(int arr[], int l, int r, int k) {
		// code here
		int result;
		for (int i = r + 1 / 2 - 1; i >= 0; i--) {
			heapify(arr, r + 1, i);
		}
		int n = r + 1;
		for (int i = 0; i < k; i++) {
			result = arr[0];
			//cout << arr[0] << endl;
			swap(0, n- 1, arr);
			n = n - 1;
			heapify(arr, n, 0);
		}
		return result;


	}

};
int main() {
	int data[] = { 15, 5, 20, 1, 17, 10, 30 };
	Solution obj;
	cout << obj.kthSmallest(data, 0, 6, 3);

	
	return 0;

}