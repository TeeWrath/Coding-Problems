#include<bits/stdc++.h>
using namespace std;

// Brute force
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size(); // Row
        int m = arr[0].size(); // Columns
        vector<int> arr2(n,0);
        
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1) arr2[i]++;
            }
        }
        
        int ans = INT_MIN;
        int ind = 0;
        for(int i=0; i<n; i++){
            if(arr2[i] > ans){
                ans = arr2[i];
                ind = i;
            }
        }
        
        return ind;
    }
};

// Better
class Solution {
  public:
    int firstOcc(vector<int>& arr, int k){
        int n = arr.size();
        int first = -1;
        
        int low = 0; int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            
            if(arr[mid] == k){
                first = mid;
                high = mid-1;
            }else if(arr[mid] < k){
                low = mid+1;
            }else high = mid - 1;
        }
        
        return first;
    }
    
    int lastOcc(vector<int>& arr, int k){
        int n = arr.size();
        int last = -1;
        
        int low = 0; int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            
            if(arr[mid] == k){
                last = mid;
                low = mid+1;
            }else if(arr[mid] < k){
                low = mid+1;
            }else high = mid - 1;
        }
        
        return last;
    }
    
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size(); // Row
        int m = arr[0].size(); // Columns
        // vector<int> arr2(n,0);
        int ans = INT_MIN;
        int ind = 0;
        
        for(int i=0; i<n; i++){
            int first = firstOcc(arr[i], 1);
            int last = lastOcc(arr[i],1);
            int freq = (first == -1) ? 0 : (last - first + 1);
            // arr2[i] = freq;
            if(freq > ans){
                ans = freq;
                ind = i;
            }
        }
        
        return ind;
    }
};