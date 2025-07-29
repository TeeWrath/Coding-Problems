#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool judgeCircle(string moves) {
            int u=0,l=0;
            for(char ch:moves){
                if(ch == 'U')u++;
                if(ch=='D')u--;
                if(ch=='L')l++;
                if(ch == 'R')l--;
            }
    
            return u==0 && l==0;
        }
    };