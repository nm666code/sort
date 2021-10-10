#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>
using namespace std;

const int len = 9;

int* gen_random_arr(){
    srand(time(NULL));
    static int arr[len];
    std::set<int> myset;

    for(int i = 0; i < len; i++){
        int r = rand()%100;
        while(myset.count(r)!=0){
            r = rand()%100;
        }
        arr[i] = r;
        myset.insert(r);
    }

    return arr;
}

void print_arr(int arr[]){
    for(int i = 0; i < len ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void my_merge(int arr[], int left, int mid, int right){

    static int buffer[len];
    int k = left;
    int i = left, j = mid + 1;

    while(i <= mid && j <= right){
        if(arr[i] < arr[j])
            buffer[k++] = arr[i++];
        else
            buffer[k++] = arr[j++];
    }

    while(i <= mid)
        buffer[k++] = arr[i++];

    while(j <= right)
        buffer[k++] = arr[j++];

    for(int k = left; k <= right; k++)
        arr[k] = buffer[k];
}

void mergeSort(int arr[], int left, int right){

    int mid = (left + right)/2;
    if(right - left <= 0)
        return;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    my_merge(arr, left, mid, right);
}

int main(){
    int* p;
    p = gen_random_arr();
    cout<<"unsorted"<<endl;
    print_arr(p);
    mergeSort(p, 0, len-1);
    cout<<"sorted"<<endl;
    print_arr(p);
    return 0;
}
