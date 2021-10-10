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

void insert_sort(int arr[]){
    int i, j, key;
    for(i = 1; i < len; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        print_arr(arr);
    }
}

int main(){
    int* arr;
    arr = gen_random_arr();
    cout<<"unsorted"<<endl;
    print_arr(arr);
    cout<<"processed"<<endl;
    insert_sort(arr);
    cout<<"sorted"<<endl;
    print_arr(arr);
    return 0;
}
