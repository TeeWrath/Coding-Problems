#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
// most optimized
class Solutionb
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int cnt = 1, maxcnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                cnt++;
                maxcnt = max(maxcnt, cnt);
            }
            else if (nums[i] == nums[i - 1])
                continue;
            else
                cnt = 1;
        }

        return maxcnt;
    }
};

// stupid, idk why u did that
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            if(nums.size() == 0)return 0;

            int longest=1;
            unordered_set<int> st;
            for(int i=0;i<n;i++) st.insert(nums[i]);

            for(auto it:st){
                if(st.find(it-1) == st.end()){
                    int x = it;
                    int cnt=1;
                    while(st.find(x+1) != st.end()){
                        cnt++;
                        x++;
                    }
                    longest = max(longest,cnt);
                }
            }

            return longest;
        }
    };

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << Solution().longestConsecutive(nums) << endl;
    return 0;
}
