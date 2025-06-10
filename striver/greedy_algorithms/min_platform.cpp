#include<bits/stdc++.h>
using namespace std;

int minPlatform(vector<int> & arrival, vector<int>& departure){
    int n = arrival.size();
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());
    int i=0,j=0;
    int maxCnt=0;
    int cnt=0;
    while(i<n && j<n){
        if(arrival[i] > departure[j]){
            cnt--;
            j++;
        }else{
            cnt++;
            i++;
        }
        maxCnt = max(maxCnt,cnt);
    }

    return maxCnt;
}

int main(){
    vector<int> arr = {900,945,955,1100,1500,1800};
    vector<int> dep = {920,1200,1130,1150,1900,2000};
    cout << minPlatform(arr,dep) << endl;
    return 0;
}