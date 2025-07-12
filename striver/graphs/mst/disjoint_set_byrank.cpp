#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0; i<n+1; i++)parent[i] = i;
        }

        // path compression
        int findUltimateParent(int node){
            if(node == parent[node])return node;
            return parent[node]= findUltimateParent(parent[node]);
        }

        void unionByRank(int u,int v){
            int pu = findUltimateParent(u);
            int pv = findUltimateParent(v);
            if(pu == pv)return;
            if(rank[pu] < rank[pv]){
                parent[pu]=pv;
            }
            else if(rank[pu] > rank[pv]){
                parent[pv] = pu;
            }else {
                parent[pv]=pu;
                rank[pu]++;
            }
        }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    // if 3 and 7 belong to same component?
    bool same = ds.findUltimateParent(3) == ds.findUltimateParent(7);
    cout << same << endl;
    ds.unionByRank(3,7);
    // now do they belong to same component?
    same = ds.findUltimateParent(3) == ds.findUltimateParent(7);
    cout << same << endl;
    return 0;
}