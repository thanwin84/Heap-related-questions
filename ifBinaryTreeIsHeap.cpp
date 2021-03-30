#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
struct Node{
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
bool isHeap(Node * tree){
    bool flag = true;
    deque<Node*> de;
    de.push_back(tree);
    while (!de.empty()){
        Node* node = de[0];
        de.pop_front();
        if (!flag){
            return false;
        }
        if (node->left){
            de.push_back(node->left);
            if (node->data < node->left->data){
                flag = false;
            }
        }
        if (node->right){
            de.push_back(node->right);
            if (node->data < node->right->data){
                flag = false;
            }
        }

    }
    return flag;
}

int main(){
    Node* node = new Node(5);
    node ->left = new Node(4);
    node->right = new Node(2);
    node->left->left = new Node(1);
    node->left->right = new Node(30);
    cout << isHeap(node);


}
