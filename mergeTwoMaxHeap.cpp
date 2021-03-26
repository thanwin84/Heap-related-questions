#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    void swap(int index1, int index2, vector<int> & arr){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    void heapify_max(vector<int> &arr, int n, int index){
        int left = (index * 2) + 1;
        int right = (index * 2) + 2;
        while (left < n){
            int largestIndex = left;
            if (right < n and arr[right] > arr[largestIndex]){
                largestIndex = right;
            }
            if (arr[index] > arr[largestIndex]){
                break;
            }
            else
                swap(index, largestIndex, arr);
            index = largestIndex;
            left = (index * 2) + 1;
            right = (index * 2) + 2;

        }
    }
    vector<int> mergeTwoMaxheap(vector<int> first_array, vector<int> second_array, int n, int m){
        vector<int> result;
        for (int i:first_array){
            result.push_back(i);
        }
        for (int i:second_array){
            result.push_back(i);
        }
        int size = result.size();
        for (int j = size /2 -1; j >= 0; j--){
            heapify_max(result, size, j);
        }
        return result;
    }
};

int main() {
    //code
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++){
        vector<int> first_array;
        vector<int> second_array;
        int n, m;
        cin >> n >> m;
        int a;
        for (int i = 0; i < n; i++){
            cin >> a;
            first_array.push_back(a);
        }
        int b;
        for (int i = 0; i < m; i++){
            cin >> b;
            second_array.push_back(b);
        }
        Solution obj;
        vector<int> result = obj.mergeTwoMaxheap(first_array, second_array, n, m);
        for (auto i: result){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

