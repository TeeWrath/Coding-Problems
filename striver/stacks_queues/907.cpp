#include <bits/stdc++.h>
using namespace std;

// poor time complexity - O(n^2)
int sumSubarrayMinsz(vector<int> &arr)
{
    int n = arr.size();
    const int MOD = 1e9 + 7;
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        int minNum = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minNum = min(arr[j], minNum);
            res = (res + minNum) % MOD;
        }
    }
    return res;
}

// TC = O(5N) = SC
vector<int> nextSmallestElement(vector<int> & nums){
    int n = nums.size();
    vector<int> nse(n, n);
    int i= n-1;
    stack<int> st;

    while(i>=0){
        // Pop elements from stack while they are >= nums[i]
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        // If stack is not empty, top is the next greater element
        if (!st.empty()) {
            nse[i] = st.top();
        }
        // Push current element
        st.push(i);
        i--;
    }
    return nse;
}

vector<int> prevSmallestElement(vector<int> & nums){
    int n = nums.size();
    vector<int> nse(n,-1);
    int i= 0;
    stack<int> st;

    while(i<n){
        // Pop elements from stack while they are >= nums[i]
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        // If stack is not empty, top is the next greater element
        if (!st.empty()) {
            nse[i] = st.top();
        }
        // Push current element
        st.push(i);
        i++;
    }
    return nse;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    const int MOD = 1e9 + 7;
    vector<int> nse = nextSmallestElement(arr);
    vector<int> pse = prevSmallestElement(arr);
    int total =0;

    for(int i=0; i<n; i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        total = (total + ((right * left * 1LL * arr[i]) %MOD)) % MOD;
    }

    return total;
}

int main(){
    vector<int> arr = {11,81,94,43,3};
    cout << "sum of subarray mins: " << sumSubarrayMins(arr) << endl;
    return 0;
}