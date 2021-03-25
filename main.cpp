#include <iostream>
#include <vector>
using namespace std;
int *add_one(vector<int> arr, int size){
    // creating dynamic array of size "size" with new keyword
    int  *myArray = new int[size];
    for (int i=0; i < size; i++){
        myArray[i] = arr[i] + 1;
    }
    return myArray;

}
int main() {
   auto a = 10000009000000009;
   vector<int> arr = {1, 2, 3, 4};
   int *pointer = add_one(arr, 4);
   for (int i = 0; i < 4; i++){
       cout << pointer[i] << " ";

   }
   // deallocating memory
   delete pointer;
   pointer = nullptr;
    for (int i = 0; i < 4; i++){
        cout << pointer[i] << " ";

    }
    return 0;
}
