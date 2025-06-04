#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Returns indices of next strictly smaller elements to the right (n if none)
vector<int> nextSmallestElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

// Returns indices of previous strictly smaller elements to the left (-1 if none)
vector<int> prevSmallestElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

// Returns sum of minimums of all subarrays
ll sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse = nextSmallestElement(arr);
    vector<int> pse = prevSmallestElement(arr);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        ll left = i - pse[i];
        ll right = nse[i] - i;
        total += left * right * arr[i];
    }
    return total;
}

// Returns indices of next strictly greater elements to the right (n if none)
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nge[i] = st.top();
        }
        st.push(i);
    }
    return nge;
}

// Returns indices of previous strictly greater elements to the left (-1 if none)
vector<int> prevGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pge(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            pge[i] = st.top();
        }
        st.push(i);
    }
    return pge;
}

// Returns sum of maximums of all subarrays
ll sumSubarrayMaxs(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge = nextGreaterElement(arr);
    vector<int> pge = prevGreaterElement(arr);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        ll left = i - pge[i];
        ll right = nge[i] - i;
        total += left * right * arr[i];
    }
    return total;
}

// Returns sum of ranges (max - min) of all subarrays
ll subArrayRanges(vector<int>& nums) {
    return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
}

int main() {
    vector<int> nums = {4, -2, -3, 4, 1};
    cout << "Answer: " << subArrayRanges(nums) << endl;
    return 0;
}