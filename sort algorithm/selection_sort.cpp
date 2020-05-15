#include <iostream>
#include <vector>

using namespace std;


void exch(std::vector<int> &a, int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void sort(std::vector<int> & a){
    for(int i = 0; i<= a.size()-2; i++){
        int minIndex = i;
        for(int j = i+1; j< a.size(); j++){
            if(a[minIndex] - a[j] > 0){
                minIndex = j;
            }
        }
        exch(a, i, minIndex);
    }
}


int main(int argc, char** argv){
    vector<int> a = {4,6,8,7,9,2,10,1};
    sort(a);
    cout<<"The sequence after the selection sort:"<<endl;
    for(int i=0; i<a.size();i++){
        cout<< a.at(i)<<" ";
    }
    return 0;
}