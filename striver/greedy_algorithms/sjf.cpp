#include<bits/stdc++.h>
using namespace std;

int shortestJobFirst(vector<int> & jobs){
    int n = jobs.size();
    sort(jobs.begin(),jobs.end());
    int totalWait = 0;
    int wait = 0;
    for(int i=1; i<n; i++){
        wait += jobs[i-1];
        totalWait += wait;
    }

    return totalWait/n;
}

int main(){
    vector<int> jobs = {4, 3, 7, 1, 2};
    cout << shortestJobFirst(jobs) <<  endl;
    return 0;
}