#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(int i=0; i< s.size();i++){
            if(isalnum(s[i])){
                ans +=  tolower(s[i]);
            }
        }

        int i=0,j=ans.size()-1;
        while(i<ans.size() && j >=0){
            if(ans[i]!=ans[j])return false;
            else {
                i++;j--;
            }
        }

        return true;
    }
};

class Solution2 {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(char c:s){
            if(isalnum(c)){
                ans += tolower(c);
            }
        }

        return ans == string(ans.rbegin(),ans.rend());
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i=0,j=n-1;

        while(i<n && j>=0){
            while(!isalnum(s[i]))i++;
            while(!isalnum(s[j]))j--;
            if(tolower(s[i]) != tolower(s[j]))return false;
            else{
                i++;
                j--;
            }
        }

        return true;
    }
};

int main(){
    string s = "Was it a car or a cat I saw?";
    cout << Solution().isPalindrome(" ") << endl;
    return 0;
}