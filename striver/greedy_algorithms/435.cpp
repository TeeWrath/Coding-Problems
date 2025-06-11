#include<bits/stdc++.h>
using namespace std;

bool static comp(vector<int> val1, vector<int> val2){
    return val1[1] < val2[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(),intervals.end(),comp);
    int cnt =1;
    int lastEndInterval = intervals[0][1];
    for(int i=1 ; i<n; i++){
        if(intervals[i][0] >= lastEndInterval){
            cnt++;
            lastEndInterval = intervals[i][1];
        }
    }
    return n-cnt;
}

int main(){
    return 0;
}