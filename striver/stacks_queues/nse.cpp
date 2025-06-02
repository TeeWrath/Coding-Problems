#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallestElement(vector<int> & nums){
    int n = nums.size();
    vector<int> nse(n,-1);
    int i= n-1;
    stack<int> st;

    while(i>=0){
        // Pop elements from stack while they are >= nums[i]
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }
        // If stack is not empty, top is the next greater element
        if (!st.empty()) {
            nse[i] = st.top();
        }
        // Push current element
        st.push(nums[i]);
        i--;
    }
    return nse;
}

int main(){
    vector<int> nums = {1, 3, 4, 2};
    vector<int> ans = nextSmallestElement(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}