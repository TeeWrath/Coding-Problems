#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int f(int i, int j,int n, char x, vector<string>& cards){
            if(j==n)  return f(i+1,i+2,n,x,cards);
            if(i==n)return 0;

            int pt =0;
            if(isCompatible(cards[i],cards[j],x) == false)pt += f(i,j+1,n,x,cards);
            else{
                int accepted,notaccepted=0;
                accepted += 1+ f(1+2,j+2,n,x,cards);
                notaccepted += f(i,j+1,n,x,cards);
                pt = max(accepted,notaccepted);
            }

            return pt;
        }
    public:
        bool isCompatible(string s,string t,char x){

            int diffChar = 0;
            int xfound = 0;

            for(int i=0;i<2;i++){
                if(s[i] == x && t[i] == x)xfound++;
                if(diffChar > 1 || xfound > 1)return false;
                if(s[i] != t[i]){
                    diffChar++;
                }
            }

            return true;
        }
    public:
        int score(vector<string>& cards, char x) {
            int n = cards.size();
            return f(0,1,n,x,cards);
        }
    };

int main() {
    vector<string> cards = {"aa","ab","ba","ac"};
    char x = 'a';
    cout << Solution().score(cards,x)<<endl;
    return 0;
}