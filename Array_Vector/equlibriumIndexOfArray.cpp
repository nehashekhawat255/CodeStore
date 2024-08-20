/*Given an array arr[] of size n, return an equilibrium index (if any) or -1 if no equilibrium index exists. The equilibrium index of an array is an index such that the sum of elements at lower indexes equals the sum of elements at higher indexes.

Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. */
#include <bits/stdc++.h>
using namespace std;

//naive approach
//Time Complexity = O(n^2) and space complexity = O(1)
void equiliBri(vector<int> arr){
    int equiliBriIdx = -1;
    for(int i = 0 ; i < arr.size() ; i++){
        int leftSum = 0, rightSum = 0;
        for(int j = 0; j < i ; j++){
            leftSum += arr[j];
        }
        for(int j = i+1 ; j < arr.size() ; j++){
            rightSum += arr[j];
        }
        if(leftSum == rightSum){
            equiliBriIdx = i;
            break;
        }
    }
    cout << equiliBriIdx << endl;
}

//better approach
//by using prefix sum array and suffix sum array
//Time Complexity = O(n) and space complexity = O(n)
void equBriSumArray(vector<int> arr){
    int n = arr.size();
    if(n==1){
        cout << 0;
    }
    else{
        vector<int> prefixSumArr{n};
        vector<int> suffixSumArr{n};

        prefixSumArr[0] = arr[0];
        suffixSumArr[n-1] = arr[n-1];
        
        for(int i = 1 ; i < n ; i++){
            prefixSumArr[i] = arr[i] + prefixSumArr[i-1];
        }

        for(int i = n-2 ; i >= 0 ; i--){
            suffixSumArr[i] = arr[i] + suffixSumArr[i+1];
        }

        int equiliBri = -1;
        for(int i = 0 ; i < n ; i++){
            if(prefixSumArr[i] == suffixSumArr[i]){
                equiliBri = i;
                break;
            }
        }
        cout << equiliBri << endl;
    }
}

//expected approach
//here we will optimise the space complexity of the better approach
//time complexity = O(n) and space complexity = O(1)
void equiPoint(vector<int> arr){
    int pivot = 0, left = 0, right = 0;
    for(int i = 1 ; i < arr.size() ; i++){
        right += arr[i];
    }

    while(pivot < arr.size() - 1 && left != right){
        pivot++;
        right -= arr[pivot];
        left += arr[pivot - 1];
    }
    
    if(left == right){
        cout << pivot << endl;
    }
    else{
        cout << -1 << endl;
    }
}

int main(){
    vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};
    vector<int> arr2 = {-7, 1, 5, 2, -4, 3, 0};
    vector<int> arr3 = {-7, 1, 5, 2, -4, 3, 0};

    equiliBri(arr);
    equiPoint(arr3);
    equBriSumArray(arr2);
    return 0;
}