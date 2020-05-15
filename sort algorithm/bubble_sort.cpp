#include <iostream>
#include <vector>

using namespace std;

void swap(std::vector<int> &a, int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}


void bubble_sort(std::vector<int> &a){
    int len = a.size();
    for(int i = len -1; i>0; i--){
        for(int j = 0; j<i;j++){
            if(a[j+1] < a[j]){
                swap(a, j, j+1);
            }
        }
    }
}



int main(int argc, char** argv){
    vector<int> a = {6,5,4,3,2,1};
    bubble_sort(a);
    cout<< "the sequence for the bubble sort:"<<endl;
    for(int i=0; i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    return 0;
}