#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPredecessor(const string &a, const string &b) {
        // Check if 'a' can be formed by inserting one character into 'b'
        if (a.size() != b.size() + 1) return false;
        
        int i = 0, j = 0;
        bool inserted = false;
        
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                if (inserted) return false;
                inserted = true;
                i++; // skip one character in 'a'
            }
        }
        
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        // Sort by length
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        vector<int> dp(n, 1); // dp[i] = longest chain ending at words[i]
        int maxChain = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxChain = max(maxChain, dp[i]);
        }
        
        return maxChain;
    }
};

int main() {
    vector<string> words = {"abcd","dbqca"};
    cout << Solution().longestStrChain(words) << endl;
    return 0;
}