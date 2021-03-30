#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> min_heap;
    priority_queue<int, vector<int>> max_heap;
    int count = 0;
    double median = 0.0;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (count % 2 == 0){
            if (max_heap.empty()){
                max_heap.push(num);
                median = num;
                count += 1;
            }
            else if (min_heap.top() > num){
                max_heap.push(num);
                count += 1;
                median = max_heap.top();
            }
            else {
                int min_top = min_heap.top();
                min_heap.pop();
                max_heap.push(min_top);
                min_heap.push(num);
                count += 1;
                median = max_heap.top();
            }
        }
        else if (count % 2 != 0){
            if (max_heap.top() > num){
                int max_top = max_heap.top();
                max_heap.pop();
                min_heap.push(max_top);
                max_heap.push(num);
                count += 1;
                median = (max_heap.top() + min_heap.top()) / 2.0;
            }
            else {
                min_heap.push(num);
                median = (max_heap.top() + min_heap.top()) / 2.0;
                count += 1;
            }
        }

    }

    double findMedian() {
        return median;

    }

};
int main(){
    MedianFinder obj;
    obj.addNum(5);
    cout<< "median: " << obj.findMedian() << endl;
    obj.addNum(3);
    cout<< "median: " << obj.findMedian() << endl;
    obj.addNum(4);
    cout<< "median: " << obj.findMedian() << endl;
    obj.addNum(2);
    cout<< "median: " << obj.findMedian() << endl;
    obj.addNum(6);
    cout<< "median: " << obj.findMedian() << endl;



}
