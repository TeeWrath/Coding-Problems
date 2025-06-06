#include<bits/stdc++.h>
using namespace std;

// brute force
int func(string s){
    int n = s.size();
    int res = 0;
    for(int i=0; i<n; i++){
        bool isA = false, isB= false,isC=false;
        for(int j=i; j<n;j++){
            if(s[j] == 'a' && !isA)isA = true;
            if(s[j] == 'b' && !isB)isB = true;
            if(s[j] == 'c' && !isC)isC = true;
            if(isA && isB && isC)res++;
        }
    }

    return res;
}

// Optimal
int numberOfSubstrings(string s) {
    vector<int> lastSeen(3,-1);
    int cnt=0;

    for(int i =0; i< s.size(); i++){
        lastSeen[s[i] -'a'] = i;
        cnt += 1+ min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
    }

    return cnt;
}

int main(){
    string s = "abcabc";
    cout << numberOfSubstrings(s) << endl;
    return 0;
}