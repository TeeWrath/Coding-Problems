#include<bits/stdc++.h>
using namespace std;

void printSubarraywithMaxSum(vector<int> &arr){
    int n = arr.size();
    int cursum,ansStart,ansEnd,start=0;
    ansStart = ansEnd = -1;
    cursum = 0;
    long int maxsum = LONG_MIN;

    for(int i=0;i<n;i++){
        if(cursum == 0)start = i;
        cursum += arr[i];

        if(cursum > maxsum){
            maxsum = cursum;

            ansStart = start;
            ansEnd = i;
        }

        if(cursum < 0)cursum = 0;
    }

    cout << "MAX SUM SUBARRAY: [";
    for(int i= ansStart; i<=ansEnd;i++){
        cout << arr[i]<< ' ';
    }
    cout << "]" << "\n" << "Max sum: "<< maxsum << endl;
}

int main(){
    vector<int> arr = {2,1,-3,4,-1,2,1,-5,4};
    printSubarraywithMaxSum(arr);
    return 0;
}