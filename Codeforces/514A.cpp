#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int i =0;
    if(s[0] == '9')i++;
    while(i<s.length()){
        if((9 - (s[i] - '0')) < (s[i] - '0')){
            s[i] = (9 - (s[i] - '0')) + '0';
        }
        i++;
    }
    cout << s;
    return 0;
}