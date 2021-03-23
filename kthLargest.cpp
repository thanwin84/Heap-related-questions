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
			left = 2 * index + 1;
			right = 2 * index + 2;
		}
	}
	vector<int> kLargest(int arr[], int n, int k) {
		// code here
		vector <int> result;
		for (int i = n / 2 - 1; i >= 0; i--) {
			heapify(arr, n, i);
		}

		for (int i = 0; i < k; i++) {
			result.push_back(arr[0]);
			//cout << arr[0] << endl;
			swap(0, n - 1, arr);
			n = n - 1;
			heapify(arr, n, 0);
		}
		return result;
		

	}

};
//int main() {
//	int data[] = { 15, 5, 20, 1, 17, 10, 30 };
//	Solution obj;
//	vector<int> result = obj.kLargest(data, 7, 3);
//	
//	for (int i = 0; i < result.size(); i++) {
//		cout << result[i] << endl;
//	}
//	return 0;
//
//}