#include<bits/stdc++.h>
using namespace std;

// TC - O(N), SC - O(3)
int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
int l=0,r=0;
int lenMax=0;
map<int,int> mpp;

while(r < n){
    mpp[fruits[r]]++;
        while(mpp.size() > 2){
            int fruit = fruits[l];
            mpp[fruits[l]]--;
            if(mpp[fruits[l]] == 0){
                mpp.erase(fruit);
            }
            l++;
        }
    if(mpp.size() <= 2){
        lenMax = max(lenMax, r- l + 1);
    }
    r++;
}

return lenMax;
}

int main(){
    vector<int> fruits = {1,2,1};
    cout << totalFruit(fruits) << endl;
    return 0;
}