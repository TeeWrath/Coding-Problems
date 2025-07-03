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

vector<vector<int>> createDirectedGraph(int n, int m){
    vector<vector<int>> adjacent(n+1);
    cout << "Creating Directed Graph" << endl;
    for(int i=0; i<m; i++){
        int u,v;
        cout << "Enter node values for edges (from u to v): ";
        cin >> u >> v;
        adjacent[u].push_back(v);
    }

    return adjacent;
}

vector<vector<pair<int,int>>> createWeightedUndirectedGraph(int n,int m){
    vector<vector<pair<int,int>>> adjacent(n+1);
    cout << "Creating Undirected Weighted Graph" << endl;
    for(int i=0; i<m; i++){
        int u,v;
        cout << "Enter node values for edges (u and v): ";
        cin >> u >> v;
        cout << "Enter weight between u and v: ";
        int wt; cin >> wt;
        adjacent[u].push_back({v,wt});
        adjacent[v].push_back({u,wt});
    }

    return adjacent;
}

vector<vector<pair<int,int>>> createWeightedDirectedGraph(int n,int m){
    vector<vector<pair<int,int>>> adjacent(n+1);
    cout << "Creating Directed Weighted Graph" << endl;
    for(int i=0; i<m; i++){
        int u,v;
        cout << "Enter node values for edges (from u to v): ";
        cin >> u >> v;
        cout << "Enter weight between u and v: ";
        int wt; cin >> wt;
        adjacent[u].push_back({v,wt});
    }

    return adjacent;
}

void printGraph(vector<vector<int>> graph){
    for(auto it: graph){
        for(int i=0; i< it.size(); i++){
            cout << it[i] << " ";
        }
        cout << endl;
    }
}

void printWeightedGraph(vector<vector<pair<int,int>>> graph){
    for(auto it: graph){
        for(int i=0; i< it.size(); i++){
            cout << "{"<< it[i].first <<"," << it[i].second << "}" << " ";
        }
        cout << endl;
    }
}

int main(){
    int n,m;
    cout << "Enter value of n and m respectively" << endl;
    cin >> n >> m;
    vector<vector<int>> dg = createDirectedGraph(n,m);
    vector<vector<int>> udg = createUndirectedGraph(n,m);
    cout << "directed" << endl;
    printGraph(dg);
    cout << "undirected" << endl;
    printGraph(udg);
    return 0;
}


    // graph is below using adjacency matrix - time costly
    // int adj[n+1][m+1];
    // for(int i=0; i<m; i++){
    //     int u,v;
    //     cin >> u >> v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }

    // graph using list way
    // vector<int> adjacent[n+1];
    // for(int i=0; i<m; i++){
    //     int u,v;
    //     cin >> u >> v;
    //     adjacent[u].push_back(v);
    //     adjacent[v].push_back(u); // for a directed graph, simply remove this line, rest is same
    // }