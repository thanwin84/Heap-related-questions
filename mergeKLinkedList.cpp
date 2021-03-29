#include <iostream>
#include<string>
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
     };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> heap;
        for (auto &i: lists){
            if (i!= nullptr)
            heap.push({i->val, i});
        }
        ListNode * current = new ListNode(100);
        ListNode * dummy = current;
        while (!heap.empty()){
            pair<int, ListNode*> p = heap.top();
            heap.pop();
            current->next = p.second;
            current = current->next;
            if (p.second->next!= nullptr){
                heap.push({p.second->next->val, p.second->next});
            }
        }
        return dummy->next;
    }
};
int main() {
    ListNode* node1 = new ListNode(1);
    node1->next = new ListNode(4);
    node1->next->next = new ListNode(5);
    ListNode*node2 = new ListNode(1);
    node2->next = new ListNode(3);
    node2->next->next = new ListNode(4);
    ListNode* node3 = new ListNode(2);
    node3->next = new ListNode(6);
    vector<ListNode*> arr = {node1, node2, node3};
    Solution obj;
    ListNode * head = obj.mergeKLists(arr);
    display(head);
    return 0;
}
