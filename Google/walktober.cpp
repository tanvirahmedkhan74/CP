#include<bits/stdc++.h>

template <class T>
void InsertArr(T &item, T arr[]){
    int len = 0;
    while(len < 5){
        if(item > arr[len]){
            len++;
        }else if(item < arr[len]){
            break;
        }
    }

    for(int idx = 5;idx>len;idx--){
        arr[idx] = arr[idx - 1];
    }

    arr[len] = item;
}

void deleteItem(int val, int arr[]){
    int len = 0;

    while(val != arr[len]) len++;

    for(int i = len+1;i<5;i++){
        arr[i - 1] = arr[i];
    }
}

int main(){
    int arr[5] = {1, 2, 3, 5};
    int add = 4;
    InsertArr(add, arr);
    deleteItem(3, arr);
    
    for(int i: arr){
        std::cout << i << " ";
    }
}

