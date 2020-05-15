#include <iostream>
#include <vector>

using namespace std;

void exch(std::vector<int> &a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


void insert_sort(std::vector<int> &a){
    for(int i=1; i < a.size(); i++){
        for(int j = i; j > 0; j--){
            if(a[j-1] - a[j] > 0){
                exch(a, j-1, j);
            }
            else
                break;
            
        }
    }
}


int main(int argc, char** argv){
    vector<int> a = {4,6,8,7,9,2,10,1};
    insert_sort(a);
    cout<<"The sequence after the insert sort:"<<endl;
    for(int i=0; i<a.size();i++){
        cout<< a.at(i)<<" ";
    }
    return 0;
}