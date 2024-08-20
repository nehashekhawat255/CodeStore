#include <bits/stdc++.h>
using namespace std;

//naive approach
//time complexity = O(n) and space complexity = O(1);
void indexOfOne(vector<int> arr){
    int idx = -1;
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] == 1){
            idx = i;
            break;
        }
    }
    cout << idx << endl;
}

//expected approach
//time complexity = O(log n) and space complexity = O(1);
void indexOfOneBinarySearch(vector<int> arr){
    int low = 0, high = arr.size()-1;
    int idx = -1;

    while(low <= high){

        int mid = (low + high)/2;

        if(arr[mid] == 1 && (mid == 0 || arr[mid -1] == 0)){
            idx = mid;
            break;
        }
        else if(arr[mid] == 1){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << idx;
}

int main(){
    vector<int> arr = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    indexOfOne(arr);
    indexOfOneBinarySearch(arr);
    return 0;
}