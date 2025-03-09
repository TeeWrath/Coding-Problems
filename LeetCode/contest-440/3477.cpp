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