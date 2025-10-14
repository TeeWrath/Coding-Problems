#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fo(i,n) for(int i=0;i<n;i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

// brute 
class Solutionb {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n = nums.size();
       vector<int> res;
       map<int,int> mpp;
       fo(i,n){
        if(mpp.find(nums[i]) == mpp.end())mpp[nums[i]] = 1;
        else mpp[nums[i]]++;
       }

       for(auto it: mpp){
        if(it.second > (n/3)) res.push_back(it.first);
       }

       return res;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n = nums.size();
       int check = n/3;
       int cnt1=0,cnt2=0;
       int ele1=0,ele2=0;
       vi res;

       fo(i,n){
        if(cnt1==0 && nums[i]!=ele2){
            ele1=nums[i];
            cnt1=1;
        }
        else if(cnt2==0 && nums[i]!=ele1){
            ele2= nums[i];
            cnt2=1;
        }
        else if(nums[i] ==ele1)cnt1++;
        else if(nums[i] == ele2)cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
       }

       cnt1=0,cnt2=0;;
       fo(i,n){
        if(nums[i] ==ele1)cnt1++;
        else if(nums[i] ==ele2)cnt2++;
        if(cnt1 == check){
            res.pb(ele1);
            break;
        }
        if(cnt2 == check){
            res.pb(ele2);
            break;
        }
       }

       return res;
    }
};

int main(int argc, char const *argv[])
{
    vi nums;
    int n; cin >>n;
    fo(i,n){
        int ele;
        cin >> ele;
        nums.pb(ele);
    }

    vi ans = Solution().majorityElement(nums);
    for(auto it: ans){
        cout << it<<" ";
    }
    cout << '\n';
    return 0;
}
