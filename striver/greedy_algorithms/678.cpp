#include<bits/stdc++.h>
using namespace std;

// Brute force solution, using recursion
// TC - 3^n, SC - O(n) for the recursive stack space
bool valid(string s, int index, int cnt){
    if(cnt < 0) return false;
    if(index == s.size()) return cnt == 0;
    if(s[index] == '(') return valid(s,index+1,cnt+1);
    if(s[index] == ')') return valid(s,index+1,cnt-1);

    return valid(s,index+1,cnt+1) || valid(s,index+1,cnt-1) || valid(s,index+1,cnt);
}

bool checkValidString1(string s) {
    return valid(s,0,0);
}

// Most optimal - O(n)
bool checkValidString(string s) {
    int n = s.size();
    int min=0;
    int max=0;

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            min++;
            max++;
        }else if(s[i] == ')'){
            min--;
            max++;
        }else{
            min--;
            max++;
        }
        if(min < 0) min =0;
        if(max < 0) return false;
    }

    return min==0;
}

int main(){
    string s = "(**(";
    cout << checkValidString(s) << endl;
    return 0;
}