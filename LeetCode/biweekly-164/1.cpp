#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        if (n == 0) return 0;
        
        map<int, int> hash;
        int t = n;
        
        while (t > 0) {
            int rem = t % 10;
            hash[rem]++;
            t = t / 10;
        }
        
        int minFreq = INT_MAX;
        int result = -1;
        
        for (auto it : hash) {
            if (it.second < minFreq) {
                minFreq = it.second;
                result = it.first;
            } else if (it.second == minFreq) {
                if (it.first < result) {
                    result = it.first;
                }
            }
        }
        
        return result;
    }
};

int main() {
    int n; cin >> n;
    cout << Solution().getLeastFrequentDigit(n) << endl;
    return 0;
}