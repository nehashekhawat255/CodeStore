/*Given an array of distinct positive integers arr[] of length N, the task is to count all the triplets such that the sum of two elements equals the third element.

Examples:  

Input: arr[] = {1, 5, 3, 2} 
Output: 2 
Explanation: 
In the given array, there are two such triplets such that sum of the two numbers is equal to the third number, those are – 
(1, 2, 3), (3, 2, 5)*/

#include <bits/stdc++.h>
using namespace std;

//Brute Force approach
//Time complexity = O(n^3) and space complexity = O(1)
void countTriplet(vector<int> arr){
    int count = 0 ;
    int n = arr.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            for (int k = j+1 ; k < n ; k++){
                if(arr[i] + arr[j] == arr[k]){
                    count++;
                }
                else if(arr[i] + arr[k] == arr[j]){
                    count++;
                }
                else if(arr[j] + arr[k] == arr[i]){
                    count++;
                }
            }
        }
    }

    cout << count << endl;
}

//better approach 
//time complexity = O(n^2) and space complexity = O(n)

void tripletCount(vector<int> arr)
	{
        int n = arr.size();
        unordered_map<int, int> mp = {};
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]]++;
        }
    
        for(int i = 0 ; i < n ; i++){
            for (int j = i+1 ; j < n ; j++){
                int sum = arr[i] + arr[j];
                if(mp.find(sum)!= mp.end()){
                    count++;
                }
            }
        }
    
        cout << count ;
	}
int main(){
    vector<int> arr = {1, 5, 3, 2};
    countTriplet(arr);
    tripletCount(arr);
    return 0;
}
 