#include <bits/stdc++.h>
using namespace std;

//Navie Approach 
//Time Complexity = O(n^2) and space compexity = O(n);
void leaderOfArr(vector<int> arr){
    unordered_set<int> leader ={};
    for(int i = 0 ; i < arr.size() ; i++){
        int flag = 0;
        for(int j = i+1 ; j < arr.size() ; j++){
            if(arr[j] >= arr[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            leader.insert(arr[i]);
        }
    }
    
    for(auto it = leader.begin() ; it != leader.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;
}

//better approach
//time complexity = O(n^2) and space complexity = O(1)
void leaderFind(vector<int> arr){
    for(int i = 0 ; i < arr.size() ; i++){
        int j;
        for(j = i+1 ; j < arr.size() ; j++){
            if(arr[i] <= arr[j]){
                break;
            }
        }
        if(j == arr.size()){
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

//expected approach
//time complexity = O(n) and space complexity = O(1)
void leaderPrint(vector<int> arr){
    int maxElement = arr[arr.size()-1];
    cout << maxElement << " ";
    for(int i = arr.size() - 2 ; i >= 0 ; i--){
        if(arr[i] > maxElement){
            maxElement = arr[i];
            cout << maxElement << " ";
        }
    }
}

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    leaderOfArr(arr);
    leaderFind(arr);
    leaderPrint(arr);
    return 0;
}