#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximum69Number (int num) {
            vector<int> nums;
            int t = num;
            while(t>0){
                nums.push_back(t%10);
                t = t/10;
            }
            int n = nums.size();
            int cnt = 1;
            for(int i= n-1;i>=0;i--){
                if(cnt == 0)break;
                if(cnt == 1 && nums[i] == 6){
                    nums[i] = 9;
                    cnt--;
                }
            }
            int ans=0;
            for(int i=n-1;i>=0;i--){
                ans = ans * 10;
                ans += nums[i];
            }

            return ans;
        }
    };

int main(){
    int num; cin >> num;
    cout << Solution().maximum69Number(num) << endl;
    return 0;
}