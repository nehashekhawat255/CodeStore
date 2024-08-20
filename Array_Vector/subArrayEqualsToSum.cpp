#include <bits/stdc++.h>
using namespace std;

//naive approach
//time complexity = O(n^2) space complexity = O(1);
void subArraySum(vector<int> arr, int sum){
    int stIdx = -1;
    int ltIdx = -1;
    int flag = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        int s = 0;
        
        for(int j = i ; j < arr.size() ; j++){
            s += arr[j];
            if( s == sum){
                stIdx = i+1;
                ltIdx = j+1;
                flag = 1;
                break;
            }
            
            if(s > sum){
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
    if(stIdx != -1){
        cout << stIdx << " " << ltIdx << endl;
    }
    else{
        cout << -1 << endl;
    }
}

//Better Approach using sliding window 
//time complexity = O(n) and space complexity = O(1)
void subArraySumSlidingWindow(vector<int> arr, int sum){
    int l =0 , r = 0 , temp = 0 ; 
    for(int i = 0 ; i < arr.size() ; i ++){
        temp += arr[i];

        if(temp >= sum){
            r = i;
            
            while(temp > sum && l < r){
                temp -= arr[l];
                l++;
            }

            if(temp == sum){
                cout << l+1 << " " << r+1;
                break;
            }
        }
    }
}

int main(){
    vector<int> arr = { 15, 2, 4, 8, 9, 5, 10, 23};
    int sum = 23;
    subArraySum(arr, sum);
    subArraySumSlidingWindow(arr, sum);
    return 0;
}