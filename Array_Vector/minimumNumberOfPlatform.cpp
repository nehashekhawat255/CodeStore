#include <bits/stdc++.h>
using namespace std;

//naive approach
//time complexity = O(n^2) and space complexity = O(1)
void platform(vector<int> arr, vector<int> dep){
    int plt = 1, res = 1;
    for(int i = 0 ; i < arr.size() ; i++){
        plt = 1;
        for(int j = 0 ; j < dep.size() ; j++){
            if(i != j){
                if(arr[i] >= arr[j] && dep[j] >= arr[i]){
                    plt++;
                }
            }
        }
        res = max(plt,res);
    }
    cout << res << endl;
}

//better approach using merge sort and then traversing;
void findPlatform(vector<int> arr, vector<int> dep){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platform = 1, result = 1;
    int i=1 , j=0;
    
    while(i<arr.size() && j<dep.size()){
        if(arr[i]<=dep[j]){
            platform++;
            i++;
        }
        else{
            platform--;
            j++;
        }
        result = max(platform, result);
    }

    cout << result << endl;
}

int main(){
    vector<int> arr = { 100, 300, 500 };
    vector<int> dep = { 900, 400, 600 };
    platform(arr, dep);
    findPlatform(arr, dep);
    return 0;
}