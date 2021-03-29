#include <iostream>
#include<string>
#include <vector>
#include <queue>
#include<climits>
using namespace std;
class Pair{
public:
    int value;
    int li;
    int di;
    Pair(int value, int li, int di){
        this->value = value;
        this->li = li;
        this->di = di;
    }
};
auto compare = [](Pair &a, Pair &b){
    return a.value > b.value;
};
class Solution {
public:
    pair<int, int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Pair, vector<Pair>, decltype(compare)> heap(compare);
        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        int min_range = INT_MAX;
        int finalMin, finalMax;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i][0] > maxElement){
                maxElement = nums[i][0];
            }
            heap.push(Pair(nums[i][0], i, 0));
        }
        while(true){
            Pair pair = heap.top();
            minElement = pair.value;
            heap.pop();
            if (maxElement - minElement < min_range){
                min_range = maxElement - minElement;
                finalMin = minElement;
                finalMax = maxElement;
            }
            pair.di += 1;

            if (pair.di < nums[pair.li].size()){
                heap.push(Pair(nums[pair.li][pair.di], pair.li, pair.di));
                if (nums[pair.li][pair.di] > maxElement){
                    maxElement = nums[pair.li][pair.di];
            }
        }
            else{
                break;
            }
        }
        return {finalMin, finalMax};

    }
};
int main(){
    vector<vector<int>> arr = {{1,2,3},{1,2,3},{1,2,3}};
    Solution ob;
    pair<int, int> data= ob.smallestRange(arr);
    cout << data.first << endl;
    cout << data.second << endl;


    return 0;
}
