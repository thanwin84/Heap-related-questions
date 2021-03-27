#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
        map<int, int> lookup;
        vector<int> result;
        for (auto item: nums){
            if (lookup.count(item)){
                lookup[item] += 1;
            }
            else{
                lookup[item] = 1;
            }
        }
        for (auto element: lookup){
            cout << element.first << " " << element.second << endl;
            heap.push({element.first, element.second});
        }
        int i = 0;
        while (i < k){
            result.push_back(heap.top().second);
            heap.pop();
            i++;
        }
        return result;
        
        }
};
int main(){
    Solution obj;
    vector<int> arr = {-1, -1};
    obj.topKFrequent(arr, 1);

}
