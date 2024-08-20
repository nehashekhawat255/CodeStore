
/*Given an array A[] consisting of only 0s, 1s, and 2s. The task is to sort the array, i.e., put all 0s first, then all 1s and all 2s in last.*/

#include <bits/stdc++.h>
using namespace std;

//Print array
void printArray(vector<int> arr){
    cout << endl;
    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i] << " ";
    }
}
//brute force approach
//Time Complexity = O(N * log(n)) and space complexity = O(1)
void sort(vector<int> arr){
    for(int i = 0 ; i < arr.size() ; i++){
        for(int j = i+1 ; j < arr.size() ; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArray(arr);
}

//Better solution 
//counting 0s 1s and 2s
//Time Complexity = O(2*N) and space complexity = O(1)
void coutAndInsert(vector<int> arr){
    int c0 = 0 , c1 = 0 , c2 = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] == 0){
            c0++;
        }
        else if(arr[i] == 1){
            c1++;
        }
        else{
            c2++;
        }
    }

    int idx = 0 ;

    for(int i = 0 ; i < c0 ; i++){
        arr[idx++] = 0;
    }

    for(int i = 0 ; i < c1 ; i++){
        arr[idx++] = 1;
    }

    for(int i = 0 ; i < c2 ; i++){
        arr[idx++] = 2;
    }
    printArray(arr);
}

//Best approach
//Dutch national flag algorithm
//Time Complexity = O(N) and space complexity = O(1)
void dutchFlagAlgo(vector<int> arr){
    int lo=0 , mid = 0, hi = arr.size();

    while(mid <= hi){
        switch(arr[mid]){
            case 0:
                swap(arr[mid++], arr[lo++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid],arr[hi--]);
                break;
        }
    }
    printArray(arr);
}


int main(){
    vector<int> arr = {0,1,2,1,1,2,0,2};
    vector<int> arr2 = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    vector<int> arr3 = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1, 2, 1, 0, 1, 1, 0, 0, 2,1,0, 1};
    sort(arr);
    coutAndInsert(arr2);
    dutchFlagAlgo(arr3);

}