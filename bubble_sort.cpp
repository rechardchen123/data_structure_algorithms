#include <iostream>

using namespace std;

void swap(int *a, int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}


void bubble_sort(int *a){
    int len = sizeof(a)/sizeof(int);
    for(int i = len -1; i>0; i--){
        for(int j = 0; j<i;j++){
            if(a[j+1] < a[j]){
                swap(a, j, j+1);
            }
        }
    }
}

void print_arr(int *a){
    int i;
    int len = sizeof(a)/sizeof(int);
    if(len <1){
        printf("length greater than 0");
    }
    for(i = 0;i<len-1;i++){
         printf("%d ",a[i]);
    }
    printf("%d]\n",a[len-1]);
}

int main(int argc, char** argv){
    int a[6] = {6,5,4,3,2,1};
    bubble_sort(a);
    print_arr(a);
    return 0;
}