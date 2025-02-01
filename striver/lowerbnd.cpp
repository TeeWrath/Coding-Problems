#include<bits/stdc++.h>
using namespace std;

// Brute force
int findFloor(vector<int>& arr, int k) {
        int n = arr.size();
        int max = -1;
        
        for(int i=0; i<n; i++){
            if(arr[i] <= k && arr[i] > max) max = i;
        }
        return max;
    }

// Binary Search
int findFloorBs(vector<int>& arr, int k) {
        int n = arr.size();
        int max = -1;
        int l = 0; int h = n -1;

        while(l <= h){
            int mid = (l+h)/2;
            if(arr[mid] >= k){
                max = mid;
                h = mid-1;
            }
            else l = mid + 1;
        }
        return max;
    }

int main(){
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int res = findFloorBs(arr,0);
    cout << res;
    return 0;
}