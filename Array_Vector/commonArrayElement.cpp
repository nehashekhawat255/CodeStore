#include <bits/stdc++.h>
using namespace std;

//brute force approach
//time complexity = O(m*n) and space complexity = O(max(m,n))
void cmnEle(vector<int> arr1, vector<int> arr2){
    unordered_set<int> out;
    for(int i = 0 ; i < arr1.size() ; i++){
        for(int j = 0 ; j < arr2.size() ; j++){
            if(arr1[i] == arr2[j]){
                out.insert(arr1[i]);
            }
        }
    }

    for(auto it = out.begin() ; it != out.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;
}

//better approach applied on sorted array (if not sorted then we will apply merge sort)
void merge(vector<int>& arr, int low, int high, int mid){
    vector<int> temp = {};
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low ; i <= high ; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int>& arr, int low, int high){
    if(low >= high){
        return;
    }
    int mid = (low + mid)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void commonElement(vector<int>& arr1, vector<int>& arr2){
    mergeSort(arr1, 0, arr1.size()-1);
    mergeSort(arr2, 0, arr2.size()-1);
    unordered_set<int> out ={};

    int i =0, j=0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            out.insert(arr1[i]);
        }
    }

    for(auto it = out.begin() ; it != out.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr1 = {8, 2, 3, 4, 5, 6, 7, 1};
    vector<int> arr2 = {4, 5, 7, 11, 6, 1};
    cmnEle(arr1, arr2);
    commonElement(arr1, arr2);
    return 0;
}
