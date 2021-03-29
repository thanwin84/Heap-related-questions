#include<bits/stdc++.h>
using namespace std;

class Pair{
public:
    int value;
    int li;
    int di;
public:
    Pair(int value, int li, int di){
        this->value = value;
        this->li = li;
        this->di = di;
    }

};
auto comp =[](Pair &a, Pair &b){
    return a.value > b.value;
};
class Solution{
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        priority_queue<Pair, vector<Pair>,decltype(comp)> storage(comp);
        vector<int> result;
        for(int i = 0; i < arr.size(); i++){
            storage.push(Pair(arr[i][0], i, 0));
        }

        while(!storage.empty()){
            Pair pair = storage.top();
            result.push_back(pair.value);
            storage.pop();
            pair.di += 1;
            if (pair.di < arr[pair.li].size()){
                storage.push(Pair(arr[pair.li][pair.di], pair.li, pair.di));
            }
        }
        return result;
    }
};
int main() {
    vector<vector<int>> data = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
   Solution obj;
   vector<int> result = obj.mergeKArrays(data, 3);
    for (auto i : result){
        cout << i << " ";
    }

}
