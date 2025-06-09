#include<bits/stdc++.h>
using namespace std;

struct meet
{
    int start;
    int end;
    int pos;
};

bool comp(meet a1, meet a2){
    int r1 = a1.end;
    int r2 = a2.end;

    return r1<r2;
}


vector<int> orderOfMeets(vector<int> &start, vector<int>& end){
    int n = start.size();
    vector<meet> meets(n);
    for(int i=0; i<n; i++){
        meets[i].start = start[i];
        meets[i].end =  end[i];
        meets[i].pos = i+1;
    }
    sort(meets.begin(), meets.end(),comp);
    int cnt=1; int freetime = meets[0].end;
    vector<int> ds;
    ds.push_back(meets[0].pos);

    for(int i=0; i<n; i++){
        if(meets[i].start > freetime){
            cnt++;
            freetime = meets[i].end;
            ds.push_back(meets[i].pos);
        }
    }

    return ds;

}

int main(){
    vector<int> start = {0,3,1,5,5,8};
    vector<int> end = {5,4,2,9,7,9};
    vector<int> ans = orderOfMeets(start,end);
    for(int i=0; i< ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}