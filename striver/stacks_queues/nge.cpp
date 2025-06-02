#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;
    int i = n - 1;
    while (i >= 0) {
        // Pop elements from stack while they are <= nums[i]
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        // If stack is not empty, top is the next greater element
        if (!st.empty()) {
            nge[i] = st.top();
        }
        // Push current element
        st.push(nums[i]);
        i--;
    }
    return nge;
}

vector<int> nextGreaterElementCircular(vector<int> nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st;
    // int i = n - 1;
    for(int i= 2*n-1; i>=0 ; i--) {
        // Pop elements from stack while they are <= nums[i]
        while (!st.empty() && st.top() <= nums[i%n]) {
            st.pop();
        }
        // If stack is not empty, top is the next greater element
        if (!st.empty()) {
            nge[i%n] = st.top();
        }
        // Push current element
        st.push(nums[i%n]);
    }
    return nge;
}

int main() {
    vector<int> nums = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElementCircular(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}