#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//        priority_queue<Pair, vector<Pair>, decltype(compare)> heap(compare);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<int> result;
        for (auto i: arr){
            heap.push({abs(i-x), i});
        }
        for (int j = 0; j < k; j++){
            result.push_back(heap.top().second);
            heap.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};
