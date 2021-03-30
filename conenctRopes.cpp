#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
class Solution{
public:
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> heap;
        for (long long i = 0; i < n; i++){
            heap.push(arr[i]);
        }
        if (n == 0){
            return 0;
        }
        long long result = 0;
        while (heap.size() > 1){
            long long first = heap.top();
            heap.pop();
            long long second = heap.top();
            heap.pop();
            long long sum = first + second;
            result += sum;
            heap.push(sum);


        }
        return result;
    }
};
int main(){
    long long arr[] = {4, 3, 2, 6};
    Solution obj;
    cout << obj.minCost(arr, 4);
}
