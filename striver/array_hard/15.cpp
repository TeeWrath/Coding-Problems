#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fo(i, n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vi> st;
        int n = nums.size();
        fo(i,n){
            set<int> hashSet;
            for(int j=i+1;j<n;j++){
                int third = -(nums[i] + nums[j]);
                if(hashSet.find(third) != hashSet.end()){
                    vi tmp = {nums[i],nums[j],third};
                    sort(all(tmp));
                    st.insert(tmp);
                }
                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(all(st));
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vi nums = {-1,0,1,2,-1,-4};
    vector<vi> ans = Solution().threeSum(nums);
    for(auto it: ans){
        for(auto itr: it){
            cout << itr << ' ';
        }
        cout << '\n';
    }
    return 0;
}
