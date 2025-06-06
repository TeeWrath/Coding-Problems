#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int> & cardPoints, int k){
    int n = cardPoints.size();
    int res=0;
    int lsum =0, rsum = 0;
    for(int i=0; i<= k-1; i++)lsum += cardPoints[i];
    res = lsum;

    int rIndex = n-1;
    for(int i= k-1; i>=0; i--){
        lsum -= cardPoints[i];
        rsum += cardPoints[rIndex];
        rIndex--;
        res = max(res,lsum+rsum);
    }

    return res;
}

int main(){
    vector<int> nums ={100,40,17,9,73,75};
    int k = 3;
    cout << maxScore(nums,k) << endl;
    return 0;
}