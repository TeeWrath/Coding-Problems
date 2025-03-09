// Q1 of contest
#include<bits/stdc++.h>
using namespace std;

// Brute force
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int> check = baskets;
        for(int i=0; i<fruits.size(); i++){
            int j=0;
            while( j < check.size() && (check[j] < fruits[i]))j++;
            if(j < check.size() && check[j] >= fruits[i])check.erase(check.begin()+j);
        }
        return check.size();
    }
};

// Better Solution - 1ms runtime
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> visit(n,false);

        int ans=0;
        for(int i=0; i<n; ++i){
            bool check = false;
            for(int j=0; j<n; ++j){
                if(!visit[j] && fruits[i] <= baskets[j]){
                    visit[j] = true;
                    check = true;
                    break;
                }
            }
            if(check == false){
                ans++;
            }
        }
        return ans;
    }
};