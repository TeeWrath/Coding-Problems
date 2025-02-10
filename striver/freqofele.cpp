//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int firstOcc(vector<int>& arr, int n, int k){
        int l =0; int h = n-1;
        int first = -1;
        
        while(l <= h){
            int mid = (l+h)/2;
            if(arr[mid] == k){
                first = mid;
                h = mid - 1;
            }
            else if(arr[mid] < k){
                l = mid + 1;
            }else h = mid - 1;
        }
        
        return first;
    }
    
    int lastOcc(vector<int>& arr, int n, int k){
        int l =0; int h = n-1;
        int last = -1;
        
        while(l <= h){
            int mid = (l+h)/2;
            if(arr[mid] == k){
                last = mid;
                l=mid+1;
            }
            else if(arr[mid] < k){
                l = mid + 1;
            }else h = mid - 1;
        }
        
        return last;
    }
    
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        
        int first = firstOcc(arr,n,target);
        int last = lastOcc(arr,n,target);
        int cnt = last - first + 1;
        if(last == -1 && first == -1) cnt = 0; // to check edge cases
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends