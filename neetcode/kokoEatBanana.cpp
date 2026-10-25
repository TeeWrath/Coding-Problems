#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l =1;
        int r = *max_element(piles.begin(),piles.end());
        int res = r;

        while(l<=r){
            int m = (l+r)/2;

            long long totalTime =0;
            for(int i=0;i<n;i++){
                totalTime += ceil((piles[i] + m - 1)/m);
            }
            if(totalTime <= h){
                res = m;
                r=m-1;
            }else{
                l=m+1;
            }
        }

        return res;
    }
};


int main(){
    vector<int> piles = {25,10,23,4};
    int h; cin >> h;
    cout << Solution().minEatingSpeed(piles,h)<< endl;
    return 0;
}