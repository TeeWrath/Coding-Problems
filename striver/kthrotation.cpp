#include <bits/stdc++.h>
using namespace std;

// Brute force - linear search
class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
                return i;
        }

        return 0;
    }
};

// Using Binary search - find the index of the minimum element as it will be the ans we need
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
       int n = arr.size();
        int ans = INT_MAX;
        int index = -1;
        int low=0; int high = n-1;

        while(low <= high){
            int mid = (low+high)/2;

            if(arr[low] <= arr[mid]){
                if(ans >= arr[low]){
                    index = low;
                    ans = arr[low];
                }
                low = mid + 1;
            }
            else{
                if(arr[mid] <= ans){
                    index = mid;
                    ans = arr[mid];
                }
                high = mid - 1;
            }
        }

        return index;
    }
};