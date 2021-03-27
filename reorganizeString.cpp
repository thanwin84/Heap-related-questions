#include <iostream>
#include <vector>
#include<string>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> lookup;
        string result;
        for (char  &i :S ){
            if (lookup.count(i)){
                lookup[i] += 1;
            }
            else{
                lookup[i] = 1;
            }
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>> heap;
        for (auto &element: lookup){
            heap.push({element.second, element.first});
        }
        int _max = heap.top().first;
        if (_max > S.size() - _max + 1){
            return result;
        }
        else{
            while (lookup.size() > 1){
                pair<int, char> current = heap.top();
                heap.pop();
                pair<int, char> next = heap.top();
                heap.pop();
                result += current.second;
                result += next.second;
                lookup[current.second] -= 1;
                lookup[next.second] -= 1;
                if (lookup[current.second] > 0){
                    heap.push({lookup[current.second], current.second});
                }
                else{
                    lookup.erase(current.second);
                }
                if (lookup[next.second] > 0){
                    heap.push({lookup[next.second], next.second});
                }
                else {
                    lookup.erase(next.second);
                }
            }
            if (lookup.size() == 1){
                auto item = lookup.begin();
                result += item->first;
            }
            return result;

        }

    }
};
int main(){
    string a = "aab";
    Solution obj;
    cout << obj.reorganizeString(a);
    return 0;
}
