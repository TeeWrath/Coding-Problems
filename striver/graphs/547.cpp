#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> createUndirectedGraph(int n, int m){
    vector<vector<int>> adjacent(n+1);
    cout << "Creating Undirected Graph" << endl;
    for(int i=0; i<m; i++){
        int u,v;
        cout << "Enter node values for edges (u and v): ";
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    return adjacent;
}

void printGraph(vector<vector<int>> graph){
    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
    private:
        void dfs(int node,vector<vector<int>>& graph, vector<int>& vis){
            vis[node] = 1;

            for(auto it: graph[node]){
                if(!vis[it])dfs(it,graph,vis);
            }
        }
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            vector<vector<int>> adjl(isConnected.size());

            for(int i=0; i<isConnected.size(); i++){
                for(int j=0; j<isConnected.size(); j++){
                    if(isConnected[i][j] == 1 && i != j){
                        adjl[i].push_back(j);
                        adjl[j].push_back(i);
                    }
                }
            }

            vector<int> vis(isConnected.size(),0);
            int cnt=0;
            for(int i=0; i<isConnected.size();i++){
                if(!vis[i]){
                    cnt++;
                    dfs(i,adjl,vis);
                }
            }
            return cnt;
        }
    };

int main(){
    int n,m;
    cout << "Enter value of n and m respectively" << endl;
    cin >> n >> m;
    vector<vector<int>> udg = createUndirectedGraph(n,m);
    cout << "Undirected Graph:" << endl;
    printGraph(udg);
    cout << endl;
    return 0;
}