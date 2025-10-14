#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    bool checkIfAllFreqMatch(char key,map<char,int> mpp){
        int n = mpp.size();
        int prev=mpp[key];
        for(auto it: mpp){
            if(it.second != prev){
                return false;
            }
            prev = it.second;
        }
        return true;
    }

public:
    int f(int i,string s, int n, map<char,int> &pmpp, map<char,int> &npmpp){
        if(i == n)return 0;

        int pk,np;
        if(pmpp.find(s[i]) == pmpp.end())pmpp[s[i]]=1;
        else pmpp[s[i]]++;
        bool ready = checkIfAllFreqMatch(s[i],pmpp);
        pk += ready? 1 + f(i+1,s,n,pmpp,pmpp): 0 + f(i+1,s,n,pmpp,pmpp);

        np += f(i+1,s,n,npmpp,npmpp);
        
        return max(np,pk);
    }
public:
    int longestBalanced(string s) {
        map<char,int> pmpp,npmpp;
        return f(0,s,s.size(),pmpp,npmpp);
    }
};

int main(int argc, char const *argv[])
{
    string s ; cin >> s;
    cout << Solution().longestBalanced(s)<<endl;
    return 0;
}
